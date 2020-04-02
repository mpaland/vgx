///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2014-2017, PALANDesign Hannover, Germany
//
// \license The MIT License (MIT)
//
// This file is part of the vic library.
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
// \brief Digole LCD driver for Digole (OLED) graphic displays
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _VIC_DRV_DIGOLE_H_
#define _VIC_DRV_DIGOLE_H_

#include "../drv.h"
#include "../dc.h"    // include drawing context for alpha numeric driver


// defines the driver name and version
#define VIC_DRV_DIGOLE_VERSION   "Digole driver 2.1.0"

namespace vic {
namespace head {


// interface type
typedef enum tag_digole_interface_type {
  DIGOLE_SPI,
  DIGOLE_I2C,
  DIGOLE_UART
} digole_interface_type;


/**
 * Digole head is an RGB color graphics driver
 * \param Screen_Size_X Screen (buffer) width
 * \param Screen_Size_Y Screen (buffer) height
 * \param Viewport_Size_X Viewport (window) width
 * \param Viewport_Size_Y Viewport (window) height
 */
template<std::uint16_t Screen_Size_X   = 8U, std::uint16_t Screen_Size_Y   = 8U,
         std::uint16_t Viewport_Size_X = 8U, std::uint16_t Viewport_Size_Y = 8U,
         drv::orientation_type Orientation = drv::orientation_0,
         digole_interface_type Interface_Mode = digole_uart
>
class digole final : public drv
{
  io::handle_type         device_handle_;   // device handle
  std::uint32_t           uart_baudrate_;   // baudrate for UART interface mode
  color::value_type       color_;           // actual pixel color

public:

  /**
   * ctor
   * \param orientation Screen orientation
   * \param device_handle SPI: device id, I²C: address, UART: port_id
   * \param iface Interface type, SPI, I²C or UART are valid
   * \param uart_baudrate Baudrate of the UART interface, unused for SPI or I²C mode
   */
  digole(io::handle_type device_handle,
         std::uint32_t uart_baudrate = 9600U)
    : drv(Screen_Size_X,   Screen_Size_Y,
          Viewport_Size_X, Viewport_Size_Y,
          0U, 0U)
    , orientation_(Orientation)
    , device_handle_(device_handle)
    , uart_baudrate_(uart_baudrate)
    , color_(color::none)
  { }


  /**
   * dtor
   * Shutdown the driver
   */
  ~digole()
  {
    shutdown();
  }


  /////////////////////////////////////////////////////////////////////////////
  // M A N D A T O R Y   D R I V E R   F U N C T I O N S
  //

  virtual void init()
  {
    std::uint8_t cmd[8];

    if (Interface_Mode == DIGOLE_I2C) {
      // set I²C address
      const std::uint8_t i2c_adr = static_cast<std::uint8_t>(device_handle_);
      device_handle_ = static_cast<io::dev::handle_type>(0x27U);    // use default I²C address ($27) for init
      cmd[0] = 'S';
      cmd[1] = 'I';
      cmd[2] = '2';
      cmd[3] = 'C';
      cmd[4] = 'A';
      cmd[5] = i2c_adr;
      write(cmd, 6U);
      device_handle_ = static_cast<io::dev::handle_type>(i2c_adr);  // use new address now
    }

    // set orientation
    cmd[0] = 'S';
    cmd[1] = 'D';
    cmd[2] = static_cast<std::uint8_t>(orientation_);
    write(cmd, 3U);

    // cursor off
    cmd[0] = 'C';
    cmd[1] = 'S';
    cmd[2] = 0U
    write(cmd, 3U);

    // clear screen
    cls();

    // display and backlight on
    display_enable();
    display_brightness(255U);

    if (Interface_Mode == DIGOLE_UART) {
      // set UART baudrate
      std::uint8_t len = 0U;
      cmd[0] = 'S';
      cmd[1] = 'B';
      switch (uart_baudrate_) {
        case    300U : cmd[2] = '3'; cmd[3] = '0'; cmd[4] = '0';                                           len = 5U; break;
        case   1200U : cmd[2] = '1'; cmd[3] = '2'; cmd[4] = '0'; cmd[5] = '0';                             len = 6U; break;
        case   2400U : cmd[2] = '2'; cmd[3] = '4'; cmd[4] = '0'; cmd[5] = '0';                             len = 6U; break;
        case   4800U : cmd[2] = '4'; cmd[3] = '8'; cmd[4] = '0'; cmd[5] = '0';                             len = 6U; break;
        case   9600U : cmd[2] = '9'; cmd[3] = '6'; cmd[4] = '0'; cmd[5] = '0';                             len = 6U; break;
        case  19200U : cmd[2] = '1'; cmd[3] = '9'; cmd[4] = '2'; cmd[5] = '0'; cmd[6] = '0';               len = 7U; break;
        case  28800U : cmd[2] = '2'; cmd[3] = '8'; cmd[4] = '8'; cmd[5] = '0'; cmd[6] = '0';               len = 7U; break;
        case  38400U : cmd[2] = '3'; cmd[3] = '8'; cmd[4] = '4'; cmd[5] = '0'; cmd[6] = '0';               len = 7U; break;
        case  57600U : cmd[2] = '5'; cmd[3] = '7'; cmd[4] = '6'; cmd[5] = '0'; cmd[6] = '0';               len = 7U; break;
        case 115200U : cmd[2] = '1'; cmd[3] = '1'; cmd[4] = '5'; cmd[5] = '2'; cmd[6] = '0'; cmd[7] = '0'; len = 8U; break;
        default: break;
      }
      write(cmd, len);
    }
  }


  virtual void shutdown()
  {
    cls();
    diplay_enable(false);     // display off
    display_brightness(0U);   // backlight off
  }


  inline const char* version() const
  {
    return (const char*)VIC_DRV_DIGOLE_VERSION;
  }


  inline virtual bool is_graphic() const
  {
    // Digole LCD is a graphic display
    return true;
  }


  ///////////////////////////////////////////////////////////////////////////////
  // C O M M O N  F U N C T I O N S
  //

protected:

  virtual void cls(color::value_type)
  {
    const std::uint8_t cmd[2] = { 'C', 'L' };
    write(cmd, 2U);
  }


  ///////////////////////////////////////////////////////////////////////////////
  // G R A P H I C   F U N C T I O N S
  //

  /**
   * Set pixel in given color, the color doesn't change the actual drawing color
   * \param x X value
   * \param y Y value
   * \param color Color of pixel in ARGB format
   */
  virtual void pixel_set(vertex_type vertex, color::value_type color)
  { 
    std::uint8_t cmd[10];

    // check limits and clipping
    if (!screen_is_inside(vertex)) {
      // out of bounds
      return;
    }

    if (color != color_) {
      color_ = color;
      // use enhanced color setup
      cmd[0] = 'E';
      cmd[1] = 'S';
      cmd[2] = 'C';
      cmd[3] = color::get_red(color);
      cmd[4] = color::get_green(color);
      cmd[5] = color::get_blue(color);
      // set pixel
      cmd[6] = 'D';
      cmd[7] = 'P';
      cmd[8] = static_cast<std::uint8_t>(vertex.x);
      cmd[9] = static_cast<std::uint8_t>(vertex.y);
      write(cmd, 10U);
    }
    else {
      // no color change, just set pixel
      cmd[0] = 'D';
      cmd[1] = 'P';
      cmd[2] = static_cast<std::uint8_t>(vertex.x);
      cmd[3] = static_cast<std::uint8_t>(vertex.y);
      write(cmd, 4U);
    }
  }


  virtual void line_horz(vertex_type v0, vertex_type v1, color::value_type color)
  {
    std::uint8_t cmd[12];

    if (color != color_) {
      color_ = color;
      // use enhanced color setup
      cmd[ 0] = 'E';
      cmd[ 1] = 'S';
      cmd[ 2] = 'C';
      cmd[ 3] = color::get_red(color);
      cmd[ 4] = color::get_green(color);
      cmd[ 5] = color::get_blue(color);
      // draw horz line
      cmd[ 6] = 'L';
      cmd[ 7] = 'N';
      cmd[ 8] = static_cast<std::uint8_t>(v0.x);
      cmd[ 9] = static_cast<std::uint8_t>(v0.y);
      cmd[10] = static_cast<std::uint8_t>(v1.x);
      cmd[11] = static_cast<std::uint8_t>(v1.y);
      write(cmd, 12U);
    }
    else {
      // no color change, draw horz line
      cmd[ 0] = 'L';
      cmd[ 1] = 'N';
      cmd[ 2] = static_cast<std::uint8_t>(v0.x);
      cmd[ 3] = static_cast<std::uint8_t>(v0.y);
      cmd[ 4] = static_cast<std::uint8_t>(v1.x);
      cmd[ 5] = static_cast<std::uint8_t>(v1.y);
      write(cmd, 6U);
    }
  }


  inline virtual void line_vert(vertex_type v0, vertex_type v1, color::value_type color)
  {
    // vertical and horizontal line are same commands on Digole
    line_horz(v0, v1, color);
  }


  virtual void box(rect_type rect, color::value_type color)
  {
    std::uint8_t cmd[12];

    // ensure that v0 is top left
    util::vertex_top_left(v0, v1);

    if (color != color_) {
      color_ = color;
      // use enhanced color setup
      cmd[ 0] = 'E';
      cmd[ 1] = 'S';
      cmd[ 2] = 'C';
      cmd[ 3] = color::get_red(color);
      cmd[ 4] = color::get_green(color);
      cmd[ 5] = color::get_blue(color);
      // draw filled rectangle
      cmd[ 6] = 'F';
      cmd[ 7] = 'R';
      cmd[ 8] = static_cast<std::uint8_t>(rect.left);
      cmd[ 9] = static_cast<std::uint8_t>(rect.top);
      cmd[10] = static_cast<std::uint8_t>(rect.right);
      cmd[11] = static_cast<std::uint8_t>(rect.bottom);
      write(cmd, 12U);
    }
    else {
      // no color change, draw filled rectangle
      cmd_[0] = 'F';
      cmd_[1] = 'R';
      cmd_[2] = static_cast<std::uint8_t>(rect.left);
      cmd_[3] = static_cast<std::uint8_t>(rect.top);
      cmd_[4] = static_cast<std::uint8_t>(rect.right);
      cmd_[5] = static_cast<std::uint8_t>(rect.bottom);
      write(cmd, 6U);
    }
  }


  virtual void move(vertex_type source, vertex_type destination, std::uint16_t width, std::uint16_t height)
  {
    std::uint8_t cmd[8];

    cmd[0] = 'M';
    cmd[1] = 'A';
    cmd[2] = static_cast<std::uint8_t>(source.x);                   // left
    cmd[3] = static_cast<std::uint8_t>(source.y);                   // top
    cmd[4] = static_cast<std::uint8_t>(width);                      // width
    cmd[5] = static_cast<std::uint8_t>(height);                     // height
    cmd[6] = static_cast<std::int8_t>(destination.x - source.x);    // x offset
    cmd[7] = static_cast<std::int8_t>(destination.y - source.y);    // y offset
    write(cmd, 8U);
  }


  ///////////////////////////////////////////////////////////////////////////////
  // D I S P L A Y   C O N T R O L
  //

public:

  /**
   * Enable/disable the display
   * \param enable True to switch the display on, false to switch it off (standby, powersave)
   */
  virtual void display_enable(bool enable = true)
  {
    std::uint8_t cmd[4];

    cmd[0] = 'S';
    cmd[1] = 'O';
    cmd[2] = 'O';
    cmd[3] = enable ? 1U : 0U;
    write(cmd, 4U);
  }


  /**
   * Set display or backlight brightness
   * \param level 0: dark, backlight off; 255: maximum brightness, backlight full on
   */
  virtual void display_brightness(std::uint8_t level)
  {
    std::uint8_t cmd[3];

    cmd[0] = 'B';
    cmd[1] = 'L';
    cmd[2] = level == 0U ? 0U : 1U;
    write(cmd, 3U);
  }


private:

  inline void write(const std::uint8_t* buffer, std::uint8_t length)
  {
    io::write(device_handle_, 0U, buffer, length, nullptr, 0U);
  }

};

} // namespace head
} // namespace vic

#endif  // _VIC_DRV_DIGOLE_H_