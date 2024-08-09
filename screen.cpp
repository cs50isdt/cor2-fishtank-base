#include "screen.h"
#include <string>
#include <stdexcept>

Screen::Screen(int width, int height) {
  if (width < 0) {
    throw std::out_of_range("width must be nonnegative");
  }
  if (height < 0) {
    throw std::out_of_range("height must be nonnegative");
  }
  width_ = width;
  height_ = height;
}

void Screen::checkCoordinates(int col, int row) const {
  if (col < 0) {
    throw std::out_of_range("col must be nonnegative");
  }
  if (col >= width()) {
    throw std::out_of_range("col must be < width");
  }
  if (row < 0) {
    throw std::out_of_range("row must be nonnegative");
  }
  if (row >= height()) {
    throw std::out_of_range("row must be < height");
  }
}

int Screen::width() const { return width_; }

int Screen::height() const { return height_; }
