#include "string-screen.h"

StringScreen::StringScreen(int width, int height) : Screen(width, height) {
  buffer_.resize(height, std::vector<char>(width, ' '));
}

char StringScreen::charAt(int col, int row) const {
  checkCoordinates(col, row);
  return buffer_[row][col];
}

void StringScreen::charAtPut(int col, int row, char value) {
  checkCoordinates(col, row);
  buffer_[row][col] = value;
}

void StringScreen::clear() {
  for (size_t row = 0; row < buffer_.size(); row++) {
    for (size_t col = 0; col < buffer_[row].size(); col++) {
      buffer_[row][col] = ' ';
    }
  }
}

std::string StringScreen::toString() const {
  std::string result;
  result += "+";
  for (int colidx = 0; colidx < width_; colidx++) {
    result += "-";
  }
  result += "+\n";
  for (int rowidx = 0; rowidx < height_; rowidx++) {
    result += "|";
    for (int colidx = 0; colidx < width_; colidx++) {
      result += buffer_[rowidx][colidx];
    }
    result += "|\n";
  }
  result += "+";
  for (int colidx = 0; colidx < width_; colidx++) {
    result += "-";
  }
  result += "+";
  return result;
}
