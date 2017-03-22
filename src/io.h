///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2017-2017, PALANDesign Hannover, Germany
//
// \license The MIT License (MIT)
//
// This file is part of the vgx library.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// \brief vgx IO class
// Define this class/file in your own project and implement the four hardware
// dependent IO functions.
// Best is to take this header file, copy it and define your access functions in it.
// Alternative use a .cpp file but the compiler won't be able to inline functions very well.
// vgx driver hardware access is done via these functions like io.mem_set<std::uint8_t>(0x000, 0x00);
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _VGX_IO_H_
#define _VGX_IO_H_

#include <cstdint>
#include <cstddef>


namespace vgx {


typedef enum enum_interface_type
{
  interface_dio = 0,    // digital IO interface
  interface_spi,        // SPI interface
  interface_i2c,        // I²C interface
  interface_can,        // CAN interface
  interface_usb,        // USB interface
  interface_serial,     // Serial/UART interface
  intercace_cust        // custom interface (bit banging etc.)
} interface_type;


/**
 * driver IO class
 */
class drv_io
{
public:

  /////////////////////////////////////////////////////////////////////////////
  // H A R D W A R E   A C C E S S
  //
  // Define all IO functions in your project
  //

  /**
   * Init the interfaces
   * \param if_type Interface type
   * \param device_id Logical device ID of the according interface
   */
  void init(interface_type if_type, std::uint32_t device_id);


  /**
   * Direct memory access, write
   * \param address The address to write to
   * \param value The value (of type VALUE_TYPE) written to the address
   */
  template<typename VALUE_TYPE>
  inline void mem_set(void* const address, VALUE_TYPE value);


  /**
   * Direct memory access, read
   * \param address The address to read from
   * \return The value (of type VALUE_TYPE) read from address
   */
  template<typename VALUE_TYPE>
  inline VALUE_TYPE mem_get(const void* const address) const;


  /**
   * IO write/read access to device
   * The bytes read are only valid on interfaces, where writing and reading is simultaneous, like SPI
   * \param if_type Interface type
   * \param device_id Logical device ID of the according interface
   * \param data_out Data transmit buffer
   * \param data_out_length Data length to send
   * \param data_in Data receive buffer
   * \param data_in_length Additional input length
   * \param timeout Time in [ms] to wait for sending data, 0 = no waiting
   * \return true if successful
   */ 
  bool dev_set(interface_type if_type, std::uint32_t device_id,
               const std::uint8_t* data_out, std::size_t data_out_length,
               std::uint8_t* data_in, std::size_t data_in_length,
               std::uint32_t timeout = 0U);


  /**
   * IO read access from device
   * \param if_type Interface type
   * \param device_id Logical device ID of the according interface
   * \param data_in Data receive buffer
   * \param data_in_length Maximum buffer size on input, received chars on output
   * \param timeout Time in [ms] to wait for receiving data, 0 = no waiting (fifo check)
   * \return true if successful
   */ 
  bool dev_get(interface_type if_type, std::uint32_t device_id,
               std::uint8_t* data_in, std::size_t& data_in_length,
               std::uint32_t timeout = 0U);
};

} // namespace vgx

#endif  // _VGX_IO_H_
