#include "game.h"
#include "macros.h"
#include "raylib.h"
#include "screen_manager.h"

static ScreenManager currentScreen = SCR_GAME;
static ScreenSetup *setup = 0;

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
  ScreenManager_managmentDraw(setup[currentScreen]);
  EndDrawing();
}

void destroy(void) {
  //
  ScreenSetup_destroy(setup);
}
