#pragma once

#include "screen.h"
#include <ncurses.h>
#include <string>
#include <vector>

/// ncurses-based implementation of Screen using a `WINDOW`.
class CursesScreen : public Screen {
public:
  /// @brief Construct and initialize a `WINDOW`.
  /// @copydoc Screen::Screen
  explicit CursesScreen(int width, int height);
  /// @brief Fill the `WINDOW` with space (``' '``) characters. Does not refresh
  /// it.
  void clear();
  /// @copydoc Shape::charAt
  char charAt(int col, int row) const;
  /// @brief Write a character to the `WINDOW`. Does not refresh it.
  ///
  /// @param col 0-based column (x) index
  /// @param row 0-based row (y) index
  /// @param value the character to write
  /// @exception std::out_of_range if the row or column is out of bounds (negative or too large)
  void charAtPut(int col, int row, char value);
  /// @brief Refresh the WINDOW.
  void render();
  /// @returns the internal `WINDOW` for use with `wgetch` or other functions
  WINDOW *window() const;

private:
  WINDOW *window_;
};
