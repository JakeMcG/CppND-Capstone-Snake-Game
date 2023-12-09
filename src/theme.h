#pragma once
#include <vector>
#include "SDL.h"

class Color {
 public:
  short R;
  short G;
  short B;
  short A;

  Color(short r, short g, short b, short a) 
   : R(r), G(g), B(b), A(a) {};
  void SetRendererToDraw(SDL_Renderer* renderer);

  const static Color Red;
  const static Color Yellow;
  const static Color Black;
  const static Color Blue;
  const static Color White;
  const static Color Green;
}; 

class Theme {
 public:
  Color background;
  Color food;
  Color body;
  Color head;
  Color dead;

  Theme(Color _background, Color _food, Color _body, Color _head, Color _dead) 
   : background(_background), food(_food), body(_body), head(_head), dead(_dead) {};

  const static Theme Default;
  const static Theme Grassy;
};

class ThemeManager {
 public:
  ThemeManager();
  Theme CurrentTheme();
  void ToggleTheme();

 private:
  std::vector<Theme> themes;;
  int currentIndex = 0;
};