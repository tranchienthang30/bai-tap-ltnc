#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 700;
static SDL_Event* g_even ;
static SDL_Window* g_window=NULL;
static SDL_Renderer* g_screen=NULL;
const int step=5;

typedef struct input{
int left;
int right;
int up;
int down;
int jump;
};
#define WINDOW_TITLE "DEMO GAME"

#endif
