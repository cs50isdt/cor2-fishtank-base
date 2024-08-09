#pragma once

#include "screen.h"
#include "shape.h"
#include <string>
#include <vector>

/// Represents the position and velocity of a Shape on an infinite x-y grid.
class Fish {
public:
  /// Construct a Fish at a given position and with the given velocity.
  ///
  /// @param shape the fish drawing
  /// @param col can be positive or negative
  /// @param row can be positive or negative
  /// @param horizontal_speed can be positive or negative
  /// @param vertical_speed can be positive or negative
  explicit Fish(Shape shape, int col, int row, int horizontal_speed,
                int vertical_speed);
  /// @returns column (x-coordinate) of the top left character
  int col() const;
  /// @returns row (y-coordinate) of the top left character
  int row() const;
  /// @returns width of the grid of characters
  int width() const;
  /// @returns height of the grid of characters
  int height() const;
  /// @brief Update col using horizontal_speed. Update row using vertical_speed.
  void tick();
  /// @brief Render to the given Screen. Draws over whatever is already there
  /// with no concept of transparency.
  ///
  /// Because Fish::col and Fish::row return unwrapped coordinates, Fish::draw
  /// wraps them to the dimensions of the Screen.
  void draw(Screen *screen) const;

private:
  Shape shape_;
  int col_;
  int row_;
  int horizontal_speed_;
  int vertical_speed_;
};
