#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

void GameScreen_beforeLoop(void);
void GameScreen_mainLoop(void);
int GameScreen_afterLoop(void);

void GameScreen_destroy(void);
void GameScreen_draw(void);

#endif
