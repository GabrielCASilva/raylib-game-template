#include "screen_manager.h"
#include "game_screen.h"
#include "title_screen.h"
#include <stdio.h>
#include <stdlib.h>

void ScreenManager_managmentLoop(ScreenSetup setup) {
  static int beforeLoopRunned = 0;
  printf("%d\n", *setup.current);
  if (!beforeLoopRunned) {
    setup.before(setup.current);
    beforeLoopRunned = 1;
  }

  if (*setup.current == setup.currentIndex)
    setup.main();

  if (*setup.current == setup.currentIndex)
    setup.after();

  if (*setup.current != setup.currentIndex) {
    printf("mudou de tela\n");

    int isDestroyed = setup.beforeDestroy();
    if (isDestroyed) {
      setup.destroy();
    }

    // TODO: pensar melhor em que momento isso vai ser 0 de novo
    beforeLoopRunned = 0;
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

ScreenSetup *ScreenSetup_initialize(ScreenManager *currentScreen,
                                    const int len) {
  ScreenSetup stp;
  ScreenSetup *setup = malloc(sizeof(ScreenSetup) * len);

  // --
  stp.current = currentScreen;
  stp.currentIndex = SCR_TITLE;
  stp.before = &TitleScreen_beforeLoop;
  stp.main = &TitleScreen_mainLoop;
  stp.after = &TitleScreen_afterLoop;
  stp.draw = &TitleScreen_draw;
  stp.beforeDestroy = &TitleScreen_beforeDestroy;
  stp.destroy = &TitleScreen_destroy;
  setup[SCR_TITLE] = stp;
  // --

  // --
  stp.current = currentScreen;
  stp.currentIndex = SCR_GAME;
  stp.before = &GameScreen_beforeLoop;
  stp.main = &GameScreen_mainLoop;
  stp.after = &GameScreen_afterLoop;
  stp.draw = &GameScreen_draw;
  stp.beforeDestroy = &TitleScreen_beforeDestroy;
  stp.destroy = &GameScreen_destroy;
  setup[SCR_GAME] = stp;
  // --

  return setup;
}
