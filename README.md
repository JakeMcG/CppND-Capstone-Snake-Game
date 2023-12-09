# CPPND: Capstone Snake Game

Capstone Project submission for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

<img src="snake_game.gif"/>

## Building and Running

The build and run instructions are unchanged:
- `mkdir build && cd build`
- `cmake .. && make`
- `./SnakeGame`.

## Capstone Project Additions

Three main features were added to the game:

1. **High Score.** The players high score is stored to a text file. After each game the file is updated if the previous high score was beat.
2. **Replay.** When your snake dies, press the spacebar to immediately start a new game.
3. **Themes.** Feeling colorful? At any time, press tab to toggle the game's color scheme. Although only two themes are implemented (default and "grassy"), the implementation allows for cycling between any number of themes.

## Rubric Components

### Loops, Functions, I/O
- Storing and updating high score requires reading and writing to an external file.
- Toggling the color scheme requires accepting new user input.

### Object Oriented Programming
- Several new classes were added. `Logger` manages high score updating. `ThemeManager` manages color scheme toggling. A color scheme is defined by a `Theme` object which itself is composed of `Color`s.
- `Theme` and `Color` use member initialization lists.
- `Color::SetRendererToDraw` abstracts the assignment of the RGBA color to the SDL renderer out of the `renderer.cpp` body. This declutters the `Renderer::Render` method significantly, especially with the addition of `Theme`s and `Color`s.

### Memory Management
- `Logger` takes ownership of the underlying text file with a `std::fstream` upon construction, and closes the file in its destructor.
- A smart pointer (`shared_ptr`) is used to share ownership of the `ThemeManager` between the `Controller` and `Renderer` objects. The former toggles the currently selected color scheme, while the latter pulls the current color scheme to render objects accordingly.
- The `ThemeManager` smart pointer is *moved* into the `Controller` after being copied into `Renderer`, so that there is no lasting ownership in `main.cpp`.

### Concurrency
- Updating the high score is done in a separate task using `std::async`.
- Reading from and writing to the high score file is protected using a mutex and `lock_guard`.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## CC Attribution-ShareAlike 4.0 International

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
