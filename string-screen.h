#pragma once

#include "screen.h"
#include <string>
#include <vector>

/// @brief Serializable implementation of Screen using a 2D character buffer.
///
/// This class is designed to assist with unit testing of other classes.
/// Although you should still write tests to make sure this class works as
/// expected, you also shouldn't hesitate to instantiate it as part of unit
/// tests for other classes. (Even though it's a separate unit in many senses.)
class StringScreen : public Screen {
public:
  /// Construct and initialize the buffer. Fill the screen with space (``'
  /// '``) characters.
  /// @copydoc Screen::Screen
  explicit StringScreen(int width, int height);
  /// @copydoc Shape::charAt
  char charAt(int col, int row) const;
  /// Write a character to the internal buffer. Updates the buffer immediately.
  /// @param col 0-based column (x) index
  /// @param row 0-based row (y) index
  /// @param value the character to write
  /// @exception std::out_of_range if the row or column is out of bounds (negative or too large)
  void charAtPut(int col, int row, char value);
  /// Fill the screen with space (``' '``) characters. Updates the buffer
  /// immediately.
  void clear();
  /// Serialize the buffer. Wrap the output in a border:
  /// ```
  /// +----+
  /// | hi |
  /// +----+
  /// ```
  /// @returns a newline-separated list of lines
  std::string toString() const;

private:
  std::vector<std::vector<char>> buffer_;
};
