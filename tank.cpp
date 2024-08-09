#include "tank.h"
#include "fish.h"

Tank::Tank(std::vector<Fish *> fish) : fish_(fish) {}

void Tank::draw(Screen *screen) const {
  for (size_t i = 0; i < fish_.size(); i++) {
    fish_[i]->draw(screen);
  }
}

void Tank::tick() {
  for (size_t i = 0; i < fish_.size(); i++) {
    fish_[i]->tick();
  }
}
