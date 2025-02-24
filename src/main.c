#include "game.h"
#include "macros.h"
#include "raylib.h"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Template");
  init();

  float dt = 0.0f;
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    dt += GetFrameTime();
    // GameLoop
    loop(&dt);
    // Drawing Textures
    draw();
  }

  destroy();
  CloseWindow();
  return 0;
}
