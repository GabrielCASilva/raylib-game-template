#include "title_screen.h"
#include "screen_manager.h"
#include <raylib.h>
#include <stdio.h>

static ScreenManager *currentScreen;

void TitleScreen_beforeLoop(ScreenManager *current) {
  currentScreen = current;
  printf("Title Screen before Loop\n");
}

void TitleScreen_mainLoop(void) {
  //

  if (IsKeyPressed(KEY_ENTER)) {
    *currentScreen = SCR_GAME;
  }
  /*printf("Title Screen main Loop\n");*/
}

void TitleScreen_afterLoop(void) {
  // -
  /*printf("Title Screen after Loop\n");*/
}

void TitleScreen_destroy(void) {
  // --
  //
}

int TitleScreen_beforeDestroy(void) {
  // -
  //
  return 0;
}

void TitleScreen_draw(void) {
  ClearBackground(BLACK);
  DrawText("TEMPLATE", 200, 200, 20, GREEN);
}
