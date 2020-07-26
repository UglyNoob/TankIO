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
/*
struct resource;
struct gamestat;

bool loadResources(resource&);

void freeResources(resource&);

void renderText(resource&,SDL_Surface*,const char*,SDL_Rect,int,bool);

#include "values.cpp"*/
struct gamestat{
	int stat,substat;
};

struct resource{
    SDL_Surface *blast1,*blast2,*blast3,*blast4,*blast5,*enemy1L,*enemy1R,
	*enemy1U,*enemy1D,*enemy2L,*enemy2R,*enemy2U,*enemy2D,*enemy3L,*enemy3R,
	*enemy3U,*enemy3D,*p1tankL,*p1tankR,*p1tankU,*p1tankD,*p2tankL,*p2tankR,
	*p2tankU,*p2tankD,*enemymissile,*grass,*mintank,*over,*star,*steel,*steels,
	*tankmissile,*timer,*wall,*walls,*water,*font_resource;
};
extern bool loadResources(resource&);
extern void freeResources(resource&);
extern void renderText(resource&,SDL_Surface*,const char*,SDL_Rect,int,bool);

#endif
