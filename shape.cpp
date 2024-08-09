#include "shape.h"
#include <stdexcept>

using std::string;
using std::vector;

const char kPadChar = ' ';

Shape::Shape(vector<string> shape) {
  if (shape.size() == 0) {
    return;
  }
  shape_ = shape;
  size_t max_width = shape_[0].size();
  // Find max width
  for (size_t i = 1; i < shape_.size(); i++) {
    if (shape_[i].length() > max_width) {
      max_width = shape_[i].length();
    }
  }
  // Right-pad all lines to be that width
  for (size_t i = 0; i < shape_.size(); i++) {
    if (shape_[i].length() < max_width) {
      shape_[i] = shape_[i] + string(max_width - shape_[i].length(), kPadChar);
    }
  }
}

int Shape::width() const { return height() == 0 ? 0 : shape_[0].length(); }

int Shape::height() const { return shape_.size(); }

char Shape::charAt(int col, int row) const {
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
  return shape_[row][col];
}
