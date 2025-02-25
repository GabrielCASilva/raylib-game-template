#include "screen_manager.h"
#include "title_screen.h"
#include <stdlib.h>

void ScreenManager_managmentLoop(ScreenSetup setup) {
  int static beforeLoopRunned = 0;
  if (!beforeLoopRunned) {
    setup.before();
    beforeLoopRunned = 1;
  }

  // TODO: mudar de tela
  setup.main();

  int change = setup.after();
  if (change) {
    // TODO: destroy screen before change it
    // change screen
  }
}

void ScreenManager_managmentDraw(ScreenSetup setup) {
  // --
  setup.draw();
}

void ScreenSetup_destroy(ScreenSetup *setup) {
  // --
  free(setup);
}

void ScreenManager_destroy(void) {
  // --
  TitleScreen_destroy();
};

ScreenSetup *ScreenSetup_initialize(ScreenManager currentScreen,
                                    const int len) {
  ScreenSetup stp;
  ScreenSetup *setup = malloc(sizeof(ScreenSetup) * len);

  // --
  stp.current = SCR_TITLE;
  stp.next = SCR_TITLE;
  stp.before = &TitleScreen_beforeLoop;
  stp.main = &TitleScreen_mainLoop;
  stp.after = &TitleScreen_afterLoop;
  stp.draw = &TitleScreen_draw;
  setup[SCR_TITLE] = stp;
  // --

  return setup;
}
