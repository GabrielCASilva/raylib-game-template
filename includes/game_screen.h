#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screen_manager.h"

void GameScreen_beforeLoop(ScreenManager *current);
void GameScreen_mainLoop(void);
void GameScreen_afterLoop(void);

int GameScreen_beforeDestroy(void);
void GameScreen_destroy(void);
void GameScreen_draw(void);

#endif
