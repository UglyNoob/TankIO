#ifndef ___VALUES
#define ___VALUES

#define STAT_MAINMENU	0
#define STAT_MAINMENU_CREATE 	1
#define STAT_MAINMENU_JOIN		1

#define STAT_GAMING		1000


#define STAT_PAUSING	2000


#define STAT_GAMEOVER	3000



struct resource,gamestat;

bool loadResources(resource&);

void freeResources(resource&);

#include "values.cpp"

#endif
