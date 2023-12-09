#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include "theme.h"
#include "snake.h"

class Controller {
 public:
  Controller(std::shared_ptr<ThemeManager> _themeMgr) : themeMgr(_themeMgr) {};
  bool HandleInput(bool &running, Snake &snake);

 private:
  std::shared_ptr<ThemeManager> themeMgr;
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif