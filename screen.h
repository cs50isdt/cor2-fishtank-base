#pragma once

/// Represents the abstract notion of a character-addressable writable screen.
class Screen {
public:
  /// @param width width in columns
  /// @param height height in rows
  /// @exception std::out_of_range if width or height is negative
  explicit Screen(int width, int height);
  /// @returns the width in columns
  int width() const;
  /// @returns the height in rows
  int height() const;
  /// Abstract function that subclasses should override. May not cause the
  /// screen to update immediately.
  /// @param col 0-based column (x) index
  /// @param row 0-based row (y) index
  /// @param value the character to write
  /// @exception std::out_of_range if the row or column is out of bounds (negative or too large)
  virtual void charAtPut(int col, int row, char value) = 0;
  /// Abstract function that subclasses should override. May not cause the
  /// screen to update immediately.
  virtual void clear() = 0;

protected:
  void checkCoordinates(int col, int row) const;

  int width_;
  int height_;
};
