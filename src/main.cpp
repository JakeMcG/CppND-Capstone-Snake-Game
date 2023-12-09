#include <iostream>
#include <memory>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "theme.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  auto themeMgr = std::make_shared<ThemeManager>(); 
  Renderer renderer(themeMgr, kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller(std::move(themeMgr)); // move because we don't need themeMgr here anymore
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}