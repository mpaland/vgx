///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2001-2018, PALANDesign Hannover, Germany
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
// \brief LCD font 6x10, monospace, chars 0x20 - 0xFE
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _VIC_FONT_LCD_6X10_H_
#define _VIC_FONT_LCD_6X10_H_

#include "../font.h"


namespace vic {
namespace font {


class LCD_6x10 final : public font_type
{
  virtual const info_type& get_info() const
  {
    static const std::uint8_t LCD_6x10_data[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00,
      0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x28, 0x28, 0x7C, 0x50, 0xF8, 0xA0, 0xA0, 0x00, 0x00,
      0x20, 0x78, 0xA0, 0xE0, 0x30, 0x28, 0x28, 0xF0, 0x20, 0x00,
      0x00, 0x44, 0xA8, 0x50, 0x30, 0x28, 0x54, 0x88, 0x00, 0x00,
      0x00, 0x20, 0x50, 0x70, 0x64, 0xB4, 0x98, 0x78, 0x00, 0x00,
      0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x0C, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x10, 0x0C, 0x00,
      0xC0, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0xC0, 0x00,
      0x00, 0x20, 0xD8, 0x60, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x10, 0x20,
      0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00,
      0x04, 0x08, 0x08, 0x10, 0x30, 0x20, 0x40, 0x40, 0x80, 0x00,
      0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x60, 0xA0, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0x00, 0x70, 0x08, 0x08, 0x10, 0x20, 0x40, 0x78, 0x00, 0x00,
      0x00, 0x78, 0x08, 0x08, 0x30, 0x08, 0x08, 0x70, 0x00, 0x00,
      0x00, 0x10, 0x30, 0x50, 0x90, 0xF8, 0x10, 0x10, 0x00, 0x00,
      0x00, 0x78, 0x40, 0x40, 0x70, 0x08, 0x08, 0x70, 0x00, 0x00,
      0x00, 0x38, 0x40, 0x80, 0xB0, 0xC8, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x78, 0x08, 0x10, 0x20, 0x20, 0x40, 0x40, 0x00, 0x00,
      0x00, 0x70, 0x88, 0x90, 0x70, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x70, 0x88, 0x88, 0x78, 0x08, 0x10, 0xE0, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x10, 0x20,
      0x00, 0x00, 0x00, 0x08, 0x30, 0xC0, 0x30, 0x08, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0xFC, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0x60, 0x80, 0x00, 0x00,
      0x00, 0x78, 0x48, 0x08, 0x10, 0x20, 0x00, 0x20, 0x00, 0x00,
      0x00, 0x78, 0x88, 0xB8, 0xA8, 0xBC, 0x80, 0x78, 0x00, 0x00,
      0x00, 0x30, 0x30, 0x50, 0x48, 0x78, 0x48, 0x84, 0x00, 0x00,
      0x00, 0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, 0x00, 0x00,
      0x00, 0x38, 0x40, 0x80, 0x80, 0x80, 0x40, 0x38, 0x00, 0x00,
      0x00, 0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0, 0x00, 0x00,
      0x00, 0x78, 0x40, 0x40, 0x70, 0x40, 0x40, 0x78, 0x00, 0x00,
      0x00, 0x78, 0x40, 0x40, 0x70, 0x40, 0x40, 0x40, 0x00, 0x00,
      0x00, 0x38, 0x40, 0x80, 0x98, 0x88, 0x48, 0x38, 0x00, 0x00,
      0x00, 0x88, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x88, 0x00, 0x00,
      0x00, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x60, 0x00, 0x00,
      0x00, 0x88, 0x90, 0xA0, 0xC0, 0xA0, 0x90, 0x88, 0x00, 0x00,
      0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x78, 0x00, 0x00,
      0x00, 0x88, 0xD8, 0xD8, 0xE8, 0xA8, 0xA8, 0x88, 0x00, 0x00,
      0x00, 0x88, 0xC8, 0xE8, 0xA8, 0x98, 0x98, 0x88, 0x00, 0x00,
      0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0xF0, 0x88, 0x88, 0xF0, 0x80, 0x80, 0x80, 0x00, 0x00,
      0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x0C, 0x00,
      0x00, 0xE0, 0x90, 0x90, 0xE0, 0xA0, 0x90, 0x88, 0x00, 0x00,
      0x00, 0x38, 0x40, 0x40, 0x30, 0x08, 0x08, 0x70, 0x00, 0x00,
      0x00, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
      0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x84, 0x88, 0x48, 0x48, 0x50, 0x30, 0x20, 0x00, 0x00,
      0x00, 0x88, 0xA8, 0xA8, 0xA8, 0xF0, 0x50, 0x50, 0x00, 0x00,
      0x00, 0x84, 0x48, 0x30, 0x10, 0x30, 0x48, 0x84, 0x00, 0x00,
      0x00, 0x88, 0x50, 0x50, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
      0x00, 0xF8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00, 0x00,
      0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x00,
      0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x08, 0x08, 0x04, 0x00,
      0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00,
      0x00, 0x20, 0x20, 0x50, 0x50, 0x50, 0x88, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
      0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x80, 0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0xF0, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x78, 0x80, 0x80, 0x80, 0x78, 0x00, 0x00,
      0x08, 0x08, 0x08, 0x78, 0x88, 0x88, 0x98, 0x68, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x78, 0x00, 0x00,
      0x18, 0x20, 0x20, 0x78, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x78, 0x88, 0x88, 0x98, 0x68, 0x08, 0x70,
      0x80, 0x80, 0x80, 0xB8, 0xC8, 0x88, 0x88, 0x88, 0x00, 0x00,
      0x10, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
      0x10, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0xE0,
      0x40, 0x40, 0x40, 0x48, 0x50, 0x60, 0x50, 0x48, 0x00, 0x00,
      0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xF8, 0xA8, 0xA8, 0xA8, 0xA8, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xB8, 0xC8, 0x88, 0x88, 0x88, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xB0, 0xC8, 0x88, 0x88, 0xF0, 0x80, 0x80,
      0x00, 0x00, 0x00, 0x78, 0x88, 0x88, 0x98, 0x68, 0x08, 0x08,
      0x00, 0x00, 0x00, 0x58, 0x68, 0x40, 0x40, 0x40, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x38, 0x40, 0x30, 0x08, 0x70, 0x00, 0x00,
      0x00, 0x20, 0x20, 0x78, 0x20, 0x20, 0x20, 0x18, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x98, 0xE8, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x88, 0x50, 0x50, 0x50, 0x20, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xA4, 0xB4, 0xB4, 0x48, 0x48, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x84, 0x48, 0x48, 0x30, 0x30, 0x20, 0xC0,
      0x00, 0x00, 0x00, 0xF8, 0x10, 0x20, 0x40, 0xF8, 0x00, 0x00,
      0x38, 0x20, 0x20, 0x20, 0x40, 0x20, 0x20, 0x20, 0x38, 0x00,
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,
      0x70, 0x10, 0x10, 0x10, 0x08, 0x10, 0x10, 0x10, 0x70, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xE4, 0x9C, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x20, 0x50, 0x88, 0x88, 0x88, 0xF8, 0x00, 0x00,
      0x00, 0x38, 0x40, 0x80, 0x80, 0x80, 0x40, 0x38, 0x10, 0x30,
      0x00, 0x50, 0x00, 0x88, 0x88, 0x88, 0x98, 0xE8, 0x00, 0x00,
      0x08, 0x10, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x78, 0x00, 0x00,
      0x20, 0x50, 0x00, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x00, 0x50, 0x00, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x40, 0x20, 0x00, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x00, 0x10, 0x28, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x78, 0x80, 0x80, 0x80, 0x78, 0x10, 0x30,
      0x20, 0x50, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x78, 0x00, 0x00,
      0x00, 0x50, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x78, 0x00, 0x00,
      0x40, 0x20, 0x00, 0x70, 0x88, 0xF8, 0x80, 0x78, 0x00, 0x00,
      0x00, 0x50, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
      0x20, 0x50, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
      0x40, 0x20, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
      0x50, 0x30, 0x30, 0x50, 0x48, 0x78, 0x48, 0x84, 0x00, 0x00,
      0x38, 0x10, 0x30, 0x28, 0x48, 0x78, 0x44, 0x84, 0x00, 0x00,
      0x08, 0x78, 0x40, 0x40, 0x70, 0x40, 0x40, 0x78, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xD8, 0x24, 0x7C, 0xA0, 0xDC, 0x00, 0x00,
      0x00, 0x1C, 0x30, 0x30, 0x58, 0x50, 0x70, 0x9C, 0x00, 0x00,
      0x20, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x50, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x40, 0x20, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x20, 0x50, 0x00, 0x88, 0x88, 0x88, 0x98, 0xE8, 0x00, 0x00,
      0x40, 0x20, 0x00, 0x88, 0x88, 0x88, 0x98, 0xE8, 0x00, 0x00,
      0x00, 0x50, 0x00, 0x84, 0x48, 0x48, 0x30, 0x30, 0x20, 0xC0,
      0x50, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x50, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x78, 0x98, 0xA8, 0xC8, 0xF0, 0x00, 0x00,
      0x00, 0x18, 0x20, 0x20, 0x70, 0x20, 0x20, 0x78, 0x00, 0x00,
      0x00, 0x78, 0x98, 0xA8, 0xA8, 0xC8, 0xC8, 0xF0, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00, 0x00,
      0x38, 0x20, 0x20, 0x70, 0x20, 0x20, 0x20, 0x20, 0x20, 0xE0,
      0x08, 0x10, 0x00, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x10, 0x20, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
      0x10, 0x20, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x10, 0x20, 0x00, 0x88, 0x88, 0x88, 0x98, 0xE8, 0x00, 0x00,
      0x50, 0x70, 0x00, 0xB8, 0xC8, 0x88, 0x88, 0x88, 0x00, 0x00,
      0x50, 0xA8, 0xC8, 0xE8, 0xA8, 0x98, 0x98, 0x88, 0x00, 0x00,
      0x00, 0x70, 0x70, 0x50, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x30, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x20, 0x40, 0x48, 0x78,
      0x00, 0x70, 0x88, 0xE8, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xF8, 0x08, 0x08, 0x00, 0x00, 0x00,
      0x00, 0xC8, 0x50, 0x50, 0x3C, 0x44, 0x58, 0x9C, 0x00, 0x00,
      0x00, 0xC8, 0x50, 0x50, 0x38, 0x68, 0x7C, 0x88, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20,
      0x00, 0x00, 0x00, 0x28, 0x50, 0xA0, 0x50, 0x28, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xA0, 0x50, 0x28, 0x50, 0xA0, 0x00, 0x00,
      0xA8, 0x00, 0xA8, 0x00, 0xA8, 0x00, 0xA8, 0x00, 0xA8, 0x00,
      0x54, 0xA8, 0x54, 0xA8, 0x54, 0xA8, 0x54, 0xA8, 0x54, 0xA8,
      0xFC, 0xA8, 0xFC, 0xA8, 0xFC, 0xA8, 0xFC, 0xA8, 0xFC, 0xA8,
      0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
      0x10, 0x10, 0x10, 0x10, 0xF0, 0x10, 0x10, 0x10, 0x10, 0x10,
      0x10, 0x30, 0x30, 0x50, 0x48, 0x78, 0x48, 0x84, 0x00, 0x00,
      0x20, 0x70, 0x30, 0x50, 0x48, 0x78, 0x48, 0x84, 0x00, 0x00,
      0x40, 0x30, 0x30, 0x50, 0x48, 0x78, 0x48, 0x84, 0x00, 0x00,
      0x00, 0x78, 0x84, 0xB4, 0xA4, 0xB4, 0x84, 0x78, 0x00, 0x00,
      0x28, 0x28, 0x28, 0xE8, 0x08, 0xE8, 0x28, 0x28, 0x28, 0x28,
      0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,
      0x00, 0x00, 0x00, 0xF8, 0x08, 0xE8, 0x28, 0x28, 0x28, 0x28,
      0x28, 0x28, 0x28, 0xE8, 0x08, 0xF8, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x10, 0x38, 0x50, 0x50, 0x50, 0x38, 0x10, 0x00, 0x00,
      0x00, 0x84, 0x48, 0x30, 0x70, 0x20, 0x70, 0x20, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xF0, 0x10, 0x10, 0x10, 0x10, 0x10,
      0x10, 0x10, 0x10, 0x10, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x10, 0x10, 0x10, 0x10, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xFC, 0x10, 0x10, 0x10, 0x10, 0x10,
      0x10, 0x10, 0x10, 0x10, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10,
      0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x10, 0x10, 0x10, 0x10, 0xFC, 0x10, 0x10, 0x10, 0x10, 0x10,
      0x50, 0x70, 0x00, 0x70, 0x08, 0x38, 0x48, 0x7C, 0x00, 0x00,
      0x50, 0xB0, 0x30, 0x50, 0x48, 0x78, 0x48, 0x84, 0x00, 0x00,
      0x28, 0x28, 0x28, 0x2C, 0x20, 0x3C, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x3C, 0x20, 0x2C, 0x28, 0x28, 0x28, 0x28,
      0x28, 0x28, 0x28, 0xEC, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xFC, 0x00, 0xEC, 0x28, 0x28, 0x28, 0x28,
      0x28, 0x28, 0x28, 0x2C, 0x20, 0x2C, 0x28, 0x28, 0x28, 0x28,
      0x00, 0x00, 0x00, 0xFC, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
      0x28, 0x28, 0x28, 0xEC, 0x00, 0xEC, 0x28, 0x28, 0x28, 0x28,
      0x00, 0x84, 0x78, 0x48, 0x48, 0x78, 0x84, 0x00, 0x00, 0x00,
      0xD0, 0x60, 0x90, 0x78, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0xF0, 0x88, 0x88, 0xC8, 0x88, 0x88, 0xF0, 0x00, 0x00,
      0x20, 0x78, 0x40, 0x40, 0x70, 0x40, 0x40, 0x78, 0x00, 0x00,
      0x50, 0x78, 0x40, 0x40, 0x70, 0x40, 0x40, 0x78, 0x00, 0x00,
      0x20, 0x78, 0x40, 0x40, 0x70, 0x40, 0x40, 0x78, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00,
      0x10, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0x20, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0x50, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0x10, 0x10, 0x10, 0x10, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x1C, 0x10, 0x10, 0x10, 0x10, 0x10,
      0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
      0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC,
      0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x00,
      0x20, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x10, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x70, 0x90, 0x90, 0xA0, 0xA0, 0x90, 0x88, 0xB8, 0x00, 0x00,
      0x20, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x20, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x50, 0x70, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x50, 0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x98, 0xE8, 0x80, 0x80,
      0x80, 0x80, 0x80, 0xB0, 0xC8, 0x88, 0x88, 0xF0, 0x80, 0x80,
      0x00, 0x80, 0xF0, 0x88, 0x88, 0x88, 0xF0, 0x80, 0x00, 0x00,
      0x10, 0xA8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x20, 0xD8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x20, 0x98, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00,
      0x08, 0x10, 0x00, 0x84, 0x48, 0x48, 0x30, 0x30, 0x20, 0xC0,
      0x08, 0x98, 0x50, 0x50, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
      0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x20, 0x20, 0xF8, 0x20, 0x20, 0xF8, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
      0x00, 0xE4, 0xC8, 0xF0, 0x38, 0x28, 0x7C, 0x88, 0x00, 0x00,
      0x00, 0xF8, 0xE8, 0x68, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00,
      0x00, 0x38, 0x40, 0x30, 0x48, 0x68, 0x10, 0x08, 0x70, 0x00,
      0x00, 0x00, 0x00, 0x20, 0x00, 0xF8, 0x00, 0x20, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30,
      0x00, 0x20, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00,
      0x00, 0x30, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x38, 0x10, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x70, 0x20, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00
    };

    static const mono_type LCD_6x10_mono = {
      0x20U,                                  // first char code
      0xFEU,                                  // last char code
      6U,                                     // x-size of the char in pixel
      1U,                                     // bytes per char line
      LCD_6x10_data                           // char data
    };

    static const info_type LCD_6x10_info = {
      ENCODING_ASCII | AA_NONE | TYPE_MONO,   // type of font
      10U,                                    // height of font
      10U,                                    // space of font y
      0U,                                     // baseline
      &LCD_6x10_mono
    };

    return LCD_6x10_info;
  }
};


} // namespace font
} // namespace vic

#endif // _VIC_FONT_LCD_6X10_H_
