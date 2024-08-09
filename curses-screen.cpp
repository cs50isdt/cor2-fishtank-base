#include "curses-screen.h"
#include "ncurses.h"

CursesScreen::CursesScreen(int width, int height) : Screen(width, height) {
  window_ = newwin(height, width, /*starty=*/0, /*startx=*/0);
}

void CursesScreen::clear() { werase(window_); }

char CursesScreen::charAt(int col, int row) const {
  checkCoordinates(col, row);
  return mvwinch(window_, /*y=*/row, /*x=*/col);
}

void CursesScreen::charAtPut(int col, int row, char value) {
  checkCoordinates(col, row);
  mvwaddch(window_, /*y=*/row, /*x=*/col, value);
}

void CursesScreen::render() { wrefresh(window_); }

WINDOW *CursesScreen::window() const { return window_; }
