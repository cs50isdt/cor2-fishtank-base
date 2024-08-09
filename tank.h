#pragma once

#include "fish.h"
#include "screen.h"
#include <string>
#include <vector>

/// @brief Represents a collection of Fish.
///
/// Communicates the passage of time to its constituent Fish and also draws
/// them to a Screen.
class Tank {
public:
  /// @param fish All the Fish to be added to the Tank. Caller owns the memory
  /// before and after constructing a Tank.
  explicit Tank(std::vector<Fish *> fish);
  /// Render all of the Fish to the given Screen. The caller is expected to
  /// provide a clear screen. Draws over whatever is already there with no
  /// concept of transparency.
  void draw(Screen *screen) const;
  /// Signal to every Fish that one unit of time has passed so that it may
  /// update its location. Calls Fish::tick on each.
  void tick();

private:
  std::vector<Fish *> fish_;
};
