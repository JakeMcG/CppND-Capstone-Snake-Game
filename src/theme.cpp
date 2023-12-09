#include "theme.h"

const Color Color::Red{0xFF, 0x00, 0x00, 0xFF};
const Color Color::Black{0x1E, 0x1E, 0x1E, 0xFF};
const Color Color::Blue{0x00, 0x7A, 0xCC, 0xFF};
const Color Color::Yellow{0xFF, 0xCC, 0x00, 0xFF};
const Color Color::White{0xFF, 0xFF, 0xFF, 0xFF};
const Color Color::Green{0x00, 0xFF, 0x00, 0xFF};

void Color::SetRendererToDraw(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, R, G, B, A);
}

const Theme Theme::Default{Color::Black, 
  Color::Yellow, Color::White, Color::Blue, Color::Red};
const Theme Theme::Grassy{Color::Green,
  Color::Red, Color::Yellow, Color::Blue, Color::Black};

ThemeManager::ThemeManager() {
  themes = {Theme::Default, Theme::Grassy};
}

Theme ThemeManager::CurrentTheme() {
  return themes[currentIndex];
}

void ThemeManager::ToggleTheme() {
  if (currentIndex == themes.size()-1) {
    currentIndex = 0;
  } else {
    currentIndex++;
  }
}
