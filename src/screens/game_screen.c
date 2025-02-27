#include "game_screen.h"
#include <raylib.h>
#include <stdio.h>

static ScreenManager *currentScreen;

void GameScreen_beforeLoop(ScreenManager *current) {
  // -
  currentScreen = current;
  printf("Game Screen before Loop\n");
}

void GameScreen_mainLoop(void) {
  // -
  //
  if (IsKeyPressed(KEY_ENTER)) {
    *currentScreen = SCR_TITLE;
  }
}

void GameScreen_afterLoop(void) {
  // -
  //
}

int GameScreen_beforeDestroy() {
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
