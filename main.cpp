#include "curses-screen.h"
#include "fish.h"
#include "tank.h"
#include <iostream>
#include <ncurses.h>

/// Entrypoint for ncurses-based fishtank.
int main() {
  // Start curses mode
  initscr();
  // Line buffering disabled, Pass on everything to me
  cbreak();
  // Make some fish
  Shape shape0({"__  ____", "\\ \\/   o\\", "/_/\\____/"});
  Shape shape1({" ____  __", "/o   \\/ /", "\\____/\\_\\"});
  Shape shape2({
      // clang-format off
"                 ..     ",
"                  ....  ",
"                   .... ",
"                  ....  ",
"                ....    ",
"              ....      ",
"            ....        ",
"           ....         ",
"          ....          ",
"          ....          ",
"           ....         ",
"            ....        ",
"             ....       ",
"               ....     ",
"               ....     ",
"               ....     ",
"               ....     ",
"              ....      ",
"             ....       ",
"           ....         ",
"          ....          ",
"         ....           ",
      // clang-format on
  });
  Shape shape3({
      "                       -,                 ",
      "                       ) \\                ",
      ".                      )  `._             ",
      "\\`.          __,...---'     ```--...,____ ",
      " \\ `.__,,..-'                (((  <o    ,'",
      "  ) ,---..___      ____;     ```  ___.-'  ",
      " /,'         `;  ,'    ;  ,'-------'      ",
      "'             ;.'      ;,'                ",
      "                       '                  ",
  });
  Fish fish0(shape0, /*col=*/0, /*row=*/0,
             /*horizontal_speed=*/2,
             /*vertical_speed=*/0);
  Fish fish1(shape1, /*col=*/5, /*row=*/5,
             /*horizontal_speed=*/-2,
             /*vertical_speed=*/0);
  Fish fish2(shape2, /*col=*/COLS - shape2.width(),
             /*row=*/LINES - shape2.height(), 0, 0);
  Fish fish3(shape3, /*col=*/20, /*row=*/20,
             /*horizontal_speed=*/1,
             /*vertical_speed=*/0);
  Tank tank({&fish0, &fish1, &fish2, &fish3});
  CursesScreen screen(COLS, LINES);
  // Hide the cursor
  curs_set(0);
  // Start main loop
  int ch;
  wtimeout(screen.window(), 100);
  do {
    screen.clear();
    tank.draw(&screen);
    screen.render();
    tank.tick();
  } while ((ch = wgetch(screen.window())) != 'q');
  // End curses mode
  endwin();
  return 0;
}
