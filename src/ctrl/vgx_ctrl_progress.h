///////////////////////////////////////////////////////////////////////////////
// \author (c) Marco Paland (info@paland.com)
//             2014-2016, PALANDesign Hannover, Germany
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
// \brief Progress bar control
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _VGX_CTRL_PROGRESS_BAR_H_
#define _VGX_CTRL_PROGRESS_BAR_H_

#include "ctrl.h"


namespace vgx {

class progress_bar : public ctrl
{
public:
  typedef enum enum_oriantation_type {
    left_to_right = 0,    // x/y = left/top
    right_to_left,        // x/y = right/top
    bottom_to_top,        // x/y = left/bottom
    top_to_bottom         // x/y = left/top
  } orientation_type;

  typedef struct struct_config_type {
    std::int16_t      x;              // left coordinate
    std::int16_t      y;              // top  coordinate
    std::uint16_t     width;          // width of the bar
    std::uint16_t     height;         // height of the bar
    orientation_type  orientation;    // orientation of the bar, see orientation_type
    std::int16_t      range_lower;    // initial lower range
    std::int16_t      range_upper;    // initial upper range
    color::value_type color;          // foreground
    color::value_type bg_color;       // background color
  } config_type;

  /**
   * ctor
   * \param head Reference to the head driver
   * \param config Configuration params
   */
  progress_bar(drv& head, config_type& config)
    : ctrl(head)
    , config_(config)
    , pos_(config.range_lower)
    , step_(1)
  { render(config.range_lower, true); };

  /**
   * Set new bar color
   * \param color New color for control, control is redrawn
   */
  void set_color(color::value_type color)
  { config_.color = color; redraw(); }

  /**
   * Set the new minimum and maximum range
   * \param lower Lower range limit including 'lower' value
   * \param upper Upper range limit including 'upper' value
   */
  void set_range(std::int16_t lower, std::int16_t upper)
  { config_.range_lower = pos_ = lower; config_.range_upper = upper; redraw(); }

  /**
   * Set new position of the progress bar control
   * \param pos New position - must be within range
   */
  void set_pos(std::int16_t pos)
  { if (pos >= config_.range_lower && pos <= config_.range_upper) render(pos); }

  /**
   * Returns the current position of the progress bar control
   * \return Current position
   */
  std::int16_t get_pos()
  { return pos_; }

  /**
   * Specifies the step increment for step_it() function, can be negative
   * \param pos New step increment
   */
  void set_step(std::int16_t step)
  { step_ = step; }

  /**
   * Advances the current position by the step increment and redraws the bar to reflect the new position
   */
  void step_it()
  { if (pos_ + step_ >= config_.range_lower && pos_ + step_ <= config_.range_upper) render(pos_ + step_); }

  /**
   * Redraw the control
   */
  void redraw()
  { render(pos_, true); }

  virtual bool is_inside(std::int16_t x, std::int16_t y)
  { return config_.x <= x && x <= config_.x + config_.width &&
           config_.y <= y && y <= config_.y + config_.height; }

private:
  void render(std::int16_t pos, bool refresh = false)
  {
    std::int16_t offset_new = static_cast<std::int16_t>((std::int32_t)(((config_.orientation == left_to_right || config_.orientation == right_to_left) ? config_.width : config_.height) *
                              (pos - config_.range_lower)) / (config_.range_upper - config_.range_lower));
    std::int16_t offset_old = static_cast<std::int16_t>((std::int32_t)(((config_.orientation == left_to_right || config_.orientation == right_to_left) ? config_.width : config_.height) *
                              (pos_ - config_.range_lower)) / (config_.range_upper - config_.range_lower));
    std::uint32_t color_old = head_.color_pen_get();

    if (!refresh) {
      // incremental drawing
      if (pos == pos_) {
        // nothing to do
        return;
      }
      head_.color_pen_set(pos > pos_ ? config_.color : config_.bg_color);
/*
      switch (config_.orientation) {
        case left_to_right :
          head_.box(config_.x + offset_old, config_.y, config_.x + offset_new, config_.y + config_.height);
          break;
        case right_to_left :
          head_.box(config_.x + config_.width - offset_old, config_.y, config_.x + config_.width - offset_new, config_.y + config_.height);
          break;
        case bottom_to_top :
          head_.box(config_.x, config_.y + config_.height - offset_old, config_.x + config_.width, config_.y +  config_.height - offset_new);
          break;
        case top_to_bottom :
          head_.box(config_.x, config_.y + offset_old, config_.x + config_.width, config_.y + offset_new);
          break;
        default:
          break;
      }
*/
    }
    else {
      // full refresh
      head_.color_pen_set(config_.bg_color);
/*
      switch (config_.orientation) {
        case left_to_right :
          head_.box(config_.x + offset_new, config_.y, config_.x + config_.width, config_.y + config_.height);
          if (offset_new) {
            head_.color_set(config_.color);
            head_.box(config_.x, config_.y, config_.x + offset_new, config_.y + config_.height);
          }
          break;
        case right_to_left :
          head_.box(config_.x, config_.y, config_.x + config_.width - offset_new, config_.y + config_.height);
          if (offset_new) {
            head_.color_set(config_.color);
            head_.box(config_.x + config_.width - offset_new, config_.y, config_.x + config_.width, config_.y + config_.height);
          }
          break;
        case bottom_to_top :
          head_.box(config_.x, config_.y, config_.x + config_.width, config_.y + config_.height - offset_new);
          if (offset_new) {
            head_.color_set(config_.color);
            head_.box(config_.x, config_.y + config_.height - offset_new, config_.x + config_.width, config_.y + config_.height);
          }
          break;
        case top_to_bottom :
          head_.box(config_.x, config_.y + offset_new, config_.x + config_.width, config_.y + config_.height);
          if (offset_new) {
            head_.color_set(config_.color);
            head_.box(config_.x, config_.y, config_.x + config_.width, config_.y + offset_new);
          }
          break;
        default:
          break;
      }
*/
    }
    head_.color_pen_set(color_old);

    // set new position
    pos_ = pos;
  }

  config_type   config_;  // configuration
  std::int16_t  pos_;     // actual position, valid from range_lower to range_upper
  std::int16_t  step_;    // step increment
};

} // namespace vgx

#endif  // _VGX_CTRL_PROGRESS_BAR_H_
