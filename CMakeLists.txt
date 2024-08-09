cmake_minimum_required(VERSION 3.16)
project(Fishtank)

set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(
  fishes
  SHARED
  fish.cpp
  screen.cpp
  shape.cpp
  string-screen.cpp
  tank.cpp
)

add_executable(fishtank main.cpp curses-screen.cpp)
target_link_libraries(fishtank PRIVATE ncurses fishes)

add_executable(
  fishtank-tests
  tests.cpp
  $<TARGET_OBJECTS:fishes-tests>
)
target_link_libraries(fishtank-tests PRIVATE fishes)

add_library(
  fishes-tests
  OBJECT
  fish-test.cpp
  tank-test.cpp
  string-screen-test.cpp
  shape-test.cpp
  utest.h
)
