#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include "screen_manager.h"

void TitleScreen_beforeLoop(ScreenManager *current);
void TitleScreen_mainLoop(void);
void TitleScreen_afterLoop(void);

int TitleScreen_beforeDestroy(void);
void TitleScreen_destroy(void);
void TitleScreen_draw(void);

#endif
