#include "game_screen.h"
#include <raylib.h>

void GameScreen_beforeLoop(void) {
  // -
  //
}

void GameScreen_mainLoop(void) {
  // -
  //
}

int GameScreen_afterLoop(void) {
  // -
  return 0;
}

void GameScreen_destroy(void) {
  // -
  //
}

void GameScreen_draw(void) {
  // --
  ClearBackground(BLACK);
  DrawText("GAME SCREEN", 200, 200, 20, GREEN);
}
