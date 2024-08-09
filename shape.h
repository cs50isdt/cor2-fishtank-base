#pragma once

#include <string>
#include <vector>

/// Represents an ASCII-art drawing and its corresponding bounding box.
class Shape {
public:
  /// @brief Take in an array of lines and right-pad the shorter ones with ``'
  /// '`` to the width of the longest line.
  explicit Shape(std::vector<std::string> shape);
  /// @returns the width of the bounding box (0 if the height is 0)
  int width() const;
  /// @returns the height of the bounding box
  int height() const;
  /// @brief Fetch the character at the given coordinate pair.
  /// @param col 0-based column (x) index
  /// @param row 0-based row (y) index
  /// @returns character at the given position
  /// @exception std::out_of_range if the row or column is out of bounds (negative or too large)
  char charAt(int col, int row) const;

private:
  std::vector<std::string> shape_;
};
