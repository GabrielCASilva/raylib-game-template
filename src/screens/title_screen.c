#include "title_screen.h"
#include <raylib.h>
#include <stdio.h>

void TitleScreen_beforeLoop(void) {
  //
  printf("Title Screen before Loop\n");
}

void TitleScreen_mainLoop(void) {
  //
  printf("Title Screen main Loop\n");
}

int TitleScreen_afterLoop(void) {
  printf("Title Screen after Loop\n");
  return 0;
}

void TitleScreen_destroy(void) {
  // --
  //
}

void TitleScreen_draw(void) {
  ClearBackground(BLACK);
  DrawText("TEMPLATE", 200, 200, 20, GREEN);
}
