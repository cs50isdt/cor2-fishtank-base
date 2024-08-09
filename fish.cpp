#include "fish.h"
#include "screen.h"

#include <stdexcept>

using std::string;
using std::vector;

Fish::Fish(Shape shape, int col, int row, int horizontal_speed,
           int vertical_speed)
    : shape_(shape), col_(col), row_(row), horizontal_speed_(horizontal_speed),
      vertical_speed_(vertical_speed) {
}

int Fish::col() const { return col_; }

int Fish::row() const { return row_; }

int Fish::width() const { return shape_.width(); }

int Fish::height() const { return shape_.height(); }

void Fish::tick() {
  // TODO(max): This will eventually overflow
  col_ += horizontal_speed_;
  row_ += vertical_speed_;
}

static int wrap(int value, int max) {
  // Can still be negative
  int clamped = value % max;

  // Shift into positive range if needed.
  return clamped >= 0 ? clamped : clamped + max;
}

// TODO(max): Add some notion of transparency?
void Fish::draw(Screen *screen) const {
  for (int row = 0; row < height(); row++) {
    for (int col = 0; col < width(); col++) {
      screen->charAtPut(wrap(this->col() + col, screen->width()),
                        wrap(this->row() + row, screen->height()),
                        shape_.charAt(col, row));
    }
  }
}
