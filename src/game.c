#include "game.h"
#include "macros.h"
#include "raylib.h"
#include "screen_manager.h"

ScreenManager currentScreen = SCR_TITLE;
ScreenSetup *setup = 0;

void init(void) {
  //
  setup = ScreenSetup_initialize(currentScreen, NUM_OF_SCREENS);
}

void loop(float *dt) {
  //
  ScreenManager_managmentLoop(setup[currentScreen]);
}

void draw(void) {
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText("TEMPLATE", 200, 200, 20, GREEN);
  EndDrawing();
}

void destroy(void) {
  //
  ScreenSetup_destroy(setup);
}
