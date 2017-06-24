///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2001-2014, PALANDesign Hannover, Germany
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
// \brief LCD font 6x8, monospace, chars 0x20 - 0xFE
//
///////////////////////////////////////////////////////////////////////////////

#include "LCD_6x8.h"


namespace vgx {
namespace font {

static const std::uint8_t LCD_6x8_data[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x10,0x38,0x38,0x10,0x10,0x00,0x10,0x00,
  0x6C,0x6C,0x48,0x00,0x00,0x00,0x00,0x00,
  0x00,0x28,0x7C,0x28,0x28,0x7C,0x28,0x00,
  0x20,0x38,0x40,0x30,0x08,0x70,0x10,0x00,
  0x64,0x64,0x08,0x10,0x20,0x4C,0x4C,0x00,
  0x20,0x50,0x50,0x20,0x54,0x48,0x34,0x00,
  0x30,0x30,0x20,0x00,0x00,0x00,0x00,0x00,
  0x10,0x20,0x20,0x20,0x20,0x20,0x10,0x00,
  0x20,0x10,0x10,0x10,0x10,0x10,0x20,0x00,
  0x00,0x28,0x38,0x7C,0x38,0x28,0x00,0x00,
  0x00,0x10,0x10,0x7C,0x10,0x10,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x20,
  0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,
  0x00,0x04,0x08,0x10,0x20,0x40,0x00,0x00,
  0x38,0x44,0x4C,0x54,0x64,0x44,0x38,0x00,
  0x10,0x30,0x10,0x10,0x10,0x10,0x38,0x00,
  0x38,0x44,0x04,0x18,0x20,0x40,0x7C,0x00,
  0x38,0x44,0x04,0x38,0x04,0x44,0x38,0x00,
  0x08,0x18,0x28,0x48,0x7C,0x08,0x08,0x00,
  0x7C,0x40,0x40,0x78,0x04,0x44,0x38,0x00,
  0x18,0x20,0x40,0x78,0x44,0x44,0x38,0x00,
  0x7C,0x04,0x08,0x10,0x20,0x20,0x20,0x00,
  0x38,0x44,0x44,0x38,0x44,0x44,0x38,0x00,
  0x38,0x44,0x44,0x3C,0x04,0x08,0x30,0x00,
  0x00,0x00,0x30,0x30,0x00,0x30,0x30,0x00,
  0x00,0x00,0x30,0x30,0x00,0x30,0x30,0x20,
  0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x00,
  0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,
  0x20,0x10,0x08,0x04,0x08,0x10,0x20,0x00,
  0x38,0x44,0x04,0x18,0x10,0x00,0x10,0x00,
  0x38,0x44,0x5C,0x54,0x5C,0x40,0x38,0x00,
  0x38,0x44,0x44,0x44,0x7C,0x44,0x44,0x00,
  0x78,0x44,0x44,0x78,0x44,0x44,0x78,0x00,
  0x38,0x44,0x40,0x40,0x40,0x44,0x38,0x00,
  0x78,0x44,0x44,0x44,0x44,0x44,0x78,0x00,
  0x7C,0x40,0x40,0x78,0x40,0x40,0x7C,0x00,
  0x7C,0x40,0x40,0x78,0x40,0x40,0x40,0x00,
  0x38,0x44,0x40,0x5C,0x44,0x44,0x3C,0x00,
  0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x00,
  0x38,0x10,0x10,0x10,0x10,0x10,0x38,0x00,
  0x04,0x04,0x04,0x04,0x44,0x44,0x38,0x00,
  0x44,0x48,0x50,0x60,0x50,0x48,0x44,0x00,
  0x40,0x40,0x40,0x40,0x40,0x40,0x7C,0x00,
  0x44,0x6C,0x54,0x44,0x44,0x44,0x44,0x00,
  0x44,0x64,0x54,0x4C,0x44,0x44,0x44,0x00,
  0x38,0x44,0x44,0x44,0x44,0x44,0x38,0x00,
  0x78,0x44,0x44,0x78,0x40,0x40,0x40,0x00,
  0x38,0x44,0x44,0x44,0x54,0x48,0x34,0x00,
  0x78,0x44,0x44,0x78,0x48,0x44,0x44,0x00,
  0x38,0x44,0x40,0x38,0x04,0x44,0x38,0x00,
  0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x00,
  0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,
  0x44,0x44,0x44,0x44,0x44,0x28,0x10,0x00,
  0x44,0x44,0x54,0x54,0x54,0x54,0x28,0x00,
  0x44,0x44,0x28,0x10,0x28,0x44,0x44,0x00,
  0x44,0x44,0x44,0x28,0x10,0x10,0x10,0x00,
  0x78,0x08,0x10,0x20,0x40,0x40,0x78,0x00,
  0x38,0x20,0x20,0x20,0x20,0x20,0x38,0x00,
  0x00,0x40,0x20,0x10,0x08,0x04,0x00,0x00,
  0x38,0x08,0x08,0x08,0x08,0x08,0x38,0x00,
  0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
  0x30,0x30,0x10,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x40,0x40,0x78,0x44,0x44,0x44,0x78,0x00,
  0x00,0x00,0x38,0x44,0x40,0x44,0x38,0x00,
  0x04,0x04,0x3C,0x44,0x44,0x44,0x3C,0x00,
  0x00,0x00,0x38,0x44,0x78,0x40,0x38,0x00,
  0x18,0x20,0x20,0x78,0x20,0x20,0x20,0x00,
  0x00,0x00,0x3C,0x44,0x44,0x3C,0x04,0x38,
  0x40,0x40,0x70,0x48,0x48,0x48,0x48,0x00,
  0x10,0x00,0x10,0x10,0x10,0x10,0x18,0x00,
  0x08,0x00,0x18,0x08,0x08,0x08,0x48,0x30,
  0x40,0x40,0x48,0x50,0x60,0x50,0x48,0x00,
  0x10,0x10,0x10,0x10,0x10,0x10,0x18,0x00,
  0x00,0x00,0x68,0x54,0x54,0x44,0x44,0x00,
  0x00,0x00,0x70,0x48,0x48,0x48,0x48,0x00,
  0x00,0x00,0x38,0x44,0x44,0x44,0x38,0x00,
  0x00,0x00,0x78,0x44,0x44,0x44,0x78,0x40,
  0x00,0x00,0x3C,0x44,0x44,0x44,0x3C,0x04,
  0x00,0x00,0x58,0x24,0x20,0x20,0x70,0x00,
  0x00,0x00,0x38,0x40,0x38,0x04,0x38,0x00,
  0x00,0x20,0x78,0x20,0x20,0x28,0x10,0x00,
  0x00,0x00,0x48,0x48,0x48,0x58,0x28,0x00,
  0x00,0x00,0x44,0x44,0x44,0x28,0x10,0x00,
  0x00,0x00,0x44,0x44,0x54,0x7C,0x28,0x00,
  0x00,0x00,0x48,0x48,0x30,0x48,0x48,0x00,
  0x00,0x00,0x48,0x48,0x48,0x38,0x10,0x60,
  0x00,0x00,0x78,0x08,0x30,0x40,0x78,0x00,
  0x18,0x20,0x20,0x60,0x20,0x20,0x18,0x00,
  0x10,0x10,0x10,0x00,0x10,0x10,0x10,0x00,
  0x30,0x08,0x08,0x0C,0x08,0x08,0x30,0x00,
  0x28,0x50,0x00,0x00,0x00,0x00,0x00,0x00,
  0x10,0x38,0x6C,0x44,0x44,0x7C,0x00,0x00,
  0x38,0x44,0x40,0x40,0x44,0x38,0x10,0x30,
  0x48,0x00,0x48,0x48,0x48,0x58,0x28,0x00,
  0x0C,0x00,0x38,0x44,0x78,0x40,0x38,0x00,
  0x38,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x28,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x30,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x38,0x28,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x00,0x38,0x44,0x40,0x44,0x38,0x10,0x30,
  0x38,0x00,0x38,0x44,0x78,0x40,0x38,0x00,
  0x28,0x00,0x38,0x44,0x78,0x40,0x38,0x00,
  0x30,0x00,0x38,0x44,0x78,0x40,0x38,0x00,
  0x28,0x00,0x10,0x10,0x10,0x10,0x18,0x00,
  0x38,0x00,0x10,0x10,0x10,0x10,0x18,0x00,
  0x20,0x00,0x10,0x10,0x10,0x10,0x18,0x00,
  0x28,0x00,0x10,0x28,0x44,0x7C,0x44,0x00,
  0x38,0x28,0x38,0x6C,0x44,0x7C,0x44,0x00,
  0x0C,0x00,0x7C,0x40,0x78,0x40,0x7C,0x00,
  0x00,0x00,0x78,0x14,0x7C,0x50,0x3C,0x00,
  0x3C,0x50,0x50,0x7C,0x50,0x50,0x5C,0x00,
  0x38,0x00,0x30,0x48,0x48,0x48,0x30,0x00,
  0x28,0x00,0x30,0x48,0x48,0x48,0x30,0x00,
  0x60,0x00,0x30,0x48,0x48,0x48,0x30,0x00,
  0x38,0x00,0x48,0x48,0x48,0x58,0x28,0x00,
  0x60,0x00,0x48,0x48,0x48,0x58,0x28,0x00,
  0x28,0x00,0x48,0x48,0x48,0x38,0x10,0x60,
  0x48,0x30,0x48,0x48,0x48,0x48,0x30,0x00,
  0x28,0x00,0x48,0x48,0x48,0x48,0x30,0x00,
  0x00,0x00,0x04,0x38,0x58,0x68,0x70,0x80,
  0x18,0x24,0x20,0x78,0x20,0x24,0x5C,0x00,
  0x3C,0x4C,0x54,0x54,0x54,0x64,0x78,0x00,
  0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00,
  0x08,0x14,0x10,0x38,0x10,0x10,0x50,0x20,
  0x18,0x00,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x18,0x00,0x10,0x10,0x10,0x10,0x18,0x00,
  0x18,0x00,0x30,0x48,0x48,0x48,0x30,0x00,
  0x18,0x00,0x48,0x48,0x48,0x58,0x28,0x00,
  0x28,0x50,0x00,0x70,0x48,0x48,0x48,0x00,
  0x28,0x50,0x00,0x48,0x68,0x58,0x48,0x00,
  0x38,0x04,0x3C,0x44,0x3C,0x00,0x3C,0x00,
  0x30,0x48,0x48,0x48,0x30,0x00,0x78,0x00,
  0x10,0x00,0x10,0x30,0x40,0x44,0x38,0x00,
  0x78,0x94,0xAC,0xB4,0xAC,0x84,0x78,0x00,
  0x00,0x00,0xFC,0x04,0x04,0x00,0x00,0x00,
  0x40,0x48,0x50,0x38,0x44,0x08,0x1C,0x00,
  0x40,0x48,0x50,0x2C,0x54,0x1C,0x04,0x00,
  0x10,0x00,0x10,0x10,0x38,0x38,0x10,0x00,
  0x00,0x00,0x24,0x48,0x24,0x00,0x00,0x00,
  0x00,0x00,0x48,0x24,0x48,0x00,0x00,0x00,
  0x54,0x00,0xA8,0x00,0x54,0x00,0xA8,0x00,
  0x54,0xA8,0x54,0xA8,0x54,0xA8,0x54,0xA8,
  0xA8,0xFC,0x54,0xFC,0xA8,0xFC,0x54,0xFC,
  0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0xF0,0x10,0x10,0x10,0x10,
  0x18,0x00,0x10,0x28,0x44,0x7C,0x44,0x00,
  0x38,0x00,0x10,0x28,0x44,0x7C,0x44,0x00,
  0x30,0x00,0x10,0x28,0x44,0x7C,0x44,0x00,
  0x78,0x84,0xB4,0xA4,0xB4,0x84,0x78,0x00,
  0x50,0xD0,0x10,0xD0,0x50,0x50,0x50,0x50,
  0x50,0x50,0x50,0x50,0x50,0x50,0x50,0x50,
  0x00,0xF0,0x10,0xD0,0x50,0x50,0x50,0x50,
  0x50,0xD0,0x10,0xF0,0x00,0x00,0x00,0x00,
  0x00,0x10,0x38,0x40,0x40,0x38,0x10,0x00,
  0x44,0x28,0x10,0x7C,0x10,0x7C,0x10,0x00,
  0x00,0x00,0x00,0xF0,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x1C,0x00,0x00,0x00,0x00,
  0x10,0x10,0x10,0xFC,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0xFC,0x10,0x10,0x10,0x10,
  0x10,0x10,0x10,0x1C,0x10,0x10,0x10,0x10,
  0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00,
  0x10,0x10,0x10,0xFC,0x10,0x10,0x10,0x10,
  0x14,0x28,0x38,0x04,0x3C,0x44,0x3C,0x00,
  0x14,0x28,0x10,0x28,0x44,0x7C,0x44,0x00,
  0x50,0x5C,0x40,0x7C,0x00,0x00,0x00,0x00,
  0x00,0x7C,0x40,0x5C,0x50,0x50,0x50,0x50,
  0x50,0xDC,0x00,0xFC,0x00,0x00,0x00,0x00,
  0x00,0xFC,0x00,0xDC,0x50,0x50,0x50,0x50,
  0x50,0x5C,0x40,0x5C,0x50,0x50,0x50,0x50,
  0x00,0xFC,0x00,0xFC,0x00,0x00,0x00,0x00,
  0x50,0xDC,0x00,0xDC,0x50,0x50,0x50,0x50,
  0x44,0x38,0x44,0x44,0x44,0x38,0x44,0x00,
  0x30,0x40,0x20,0x10,0x38,0x48,0x30,0x00,
  0x38,0x24,0x24,0x74,0x24,0x24,0x38,0x00,
  0x38,0x00,0x7C,0x40,0x78,0x40,0x7C,0x00,
  0x28,0x00,0x7C,0x40,0x78,0x40,0x7C,0x00,
  0x30,0x00,0x7C,0x40,0x78,0x40,0x7C,0x00,
  0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,
  0x18,0x00,0x38,0x10,0x10,0x10,0x38,0x00,
  0x38,0x00,0x38,0x10,0x10,0x10,0x38,0x00,
  0x28,0x00,0x38,0x10,0x10,0x10,0x38,0x00,
  0x10,0x10,0x10,0xF0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x1C,0x10,0x10,0x10,0x10,
  0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,
  0x00,0x00,0x00,0x00,0xFC,0xFC,0xFC,0xFC,
  0x10,0x10,0x10,0x00,0x10,0x10,0x10,0x00,
  0x30,0x00,0x38,0x10,0x10,0x10,0x38,0x00,
  0xFC,0xFC,0xFC,0xFC,0x00,0x00,0x00,0x00,
  0x18,0x30,0x48,0x48,0x48,0x48,0x30,0x00,
  0x00,0x70,0x48,0x70,0x48,0x48,0x70,0x40,
  0x38,0x30,0x48,0x48,0x48,0x48,0x30,0x00,
  0x60,0x30,0x48,0x48,0x48,0x48,0x30,0x00,
  0x28,0x50,0x00,0x30,0x48,0x48,0x30,0x00,
  0x28,0x50,0x30,0x48,0x48,0x48,0x30,0x00,
  0x00,0x00,0x48,0x48,0x48,0x70,0x40,0x40,
  0x00,0x60,0x40,0x70,0x48,0x70,0x40,0x60,
  0x60,0x40,0x70,0x48,0x48,0x70,0x40,0x60,
  0x18,0x00,0x48,0x48,0x48,0x48,0x30,0x00,
  0x38,0x00,0x48,0x48,0x48,0x48,0x30,0x00,
  0x60,0x00,0x48,0x48,0x48,0x48,0x30,0x00,
  0x18,0x00,0x48,0x48,0x48,0x38,0x10,0x60,
  0x18,0x00,0x44,0x28,0x10,0x10,0x10,0x00,
  0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
  0x30,0x30,0x20,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,
  0x00,0x10,0x38,0x10,0x00,0x38,0x00,0x00,
  0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,
  0xC0,0x68,0xD0,0x2C,0x54,0x1C,0x04,0x00,
  0x3C,0x54,0x54,0x34,0x14,0x14,0x14,0x00,
  0x38,0x44,0x30,0x28,0x18,0x44,0x38,0x00,
  0x00,0x10,0x00,0x7C,0x00,0x10,0x00,0x00,
  0x00,0x00,0x00,0x38,0x18,0x00,0x00,0x00,
  0x30,0x48,0x48,0x30,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x28,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,
  0x20,0x60,0x20,0x20,0x00,0x00,0x00,0x00,
  0x70,0x20,0x30,0x60,0x00,0x00,0x00,0x00,
  0x60,0x10,0x20,0x70,0x00,0x00,0x00,0x00,
  0x00,0x00,0x78,0x78,0x78,0x78,0x00,0x00
};

static const mono_type LCD_6x8_mono = {
  0x20U,
  0xFEU,
  6U,
  1U,
  LCD_6x8_data
};

const font_type LCD_6x8 = {
  VGX_FONT_ENCODING_ASCII | VGX_FONT_AA_NONE | VGX_FONT_TYPE_MONO,  // type of font
  8U,                                                               // height of font
  8U,                                                               // space of font y
  0U,                                                               // baseline
  &LCD_6x8_mono                                                     // font type
};

} // namespace font
} // namespace vgx