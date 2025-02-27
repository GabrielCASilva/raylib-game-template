#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

enum screenManager {
  SCR_TITLE,
  SCR_GAME,
  SCR_GAMEOVER,
};

typedef enum screenManager ScreenManager;

struct screenSetup {
  ScreenManager *current;
  ScreenManager currentIndex;
  void (*before)(ScreenManager *current);
  void (*main)();
  void (*after)();
  int (*beforeDestroy)();
  void (*destroy)();
  void (*draw)();
};

typedef struct screenSetup ScreenSetup;

void ScreenManager_change(void);

void ScreenManager_managmentLoop(ScreenSetup setup);
void ScreenManager_managmentDraw(ScreenSetup setup);

ScreenSetup *ScreenSetup_initialize(ScreenManager *currentScreen,
                                    const int len);

// free all static variables in all sceans
void ScreenManager_destroy(void);
void ScreenSetup_destroy(ScreenSetup *setup);

#endif
