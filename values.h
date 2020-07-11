#ifndef ___VALUES
#define ___VALUES

#define FONT_WIDTH	14
#define FONT_HEIGHT	14

#define STAT_MAINMENU			0
#define STAT_MAINMENU_CREATE 	1
#define STAT_MAINMENU_JOIN		1

#define STAT_GAMING		1000


#define STAT_PAUSING	2000


#define STAT_GAMEOVER	3000

#include<SDL2/SDL.h>

struct resource;
struct gamestat;

bool loadResources(resource&);

void freeResources(resource&);

void renderText(resource&,SDL_Surface*,const char*,SDL_Rect,int,bool);

#include "values.cpp"

#endif
