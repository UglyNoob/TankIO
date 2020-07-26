#define _CRT_SECURE_NO_WARNINGS

#include "values.h"
#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<cstdio>

void exitGame(int);
void outError(const char*);
void gaming();
void init(bool, bool);

SDL_Window* window;
SDL_Surface* screen;
SDL_Renderer* renderer;
struct resource image;
struct gamestat stat;

int main(int argc, char** argv) {
    init(true, true);
    gaming();
    exitGame(0);
    return 0;
}

void gaming() {
    SDL_Event event;
    SDL_Rect pos;
    int height=0;
    while(true){
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,163,255));
        
        pos.x=300;pos.y=300;
        renderText(image,screen,"hello world",pos,1,true);
        pos.y+=FONT_HEIGHT+1;
        renderText(image,screen,"I think",pos,1,true);
        pos.y+=FONT_HEIGHT+1;
        renderText(image,screen,"Sheng Xiangyu is",pos,1,true);
        pos.y+=FONT_HEIGHT+1;
        renderText(image,screen,"the most beautiful",pos,1,true);
        pos.y+=FONT_HEIGHT+1;
        renderText(image,screen,"human in the world",pos,1,true);
        pos.y+=FONT_HEIGHT+1;
        renderText(image,screen,"AbCdEfGhIjKlMnOpQrStUvWxYz1234567890",pos,1,true);
        pos.x=0;pos.y=0;
        renderText(image,screen,"A game, TankIOv0.1",pos,1,false);
        
        switch(stat.stat){
        	case STAT_MAINMENU:
        		break;
		}
        SDL_UpdateWindowSurface(window);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    exitGame(0);
                    break;
            }
        }
        SDL_Delay(20);
    }
}

void init(bool initSDL, bool resetGame) {
    if (initSDL) {
        if (SDL_Init(SDL_INIT_EVENTS || SDL_INIT_VIDEO) <= -1) {
            outError(SDL_GetError());
            exit(-1);
        }
        window = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            outError(SDL_GetError());
            exit(-1);
        }
        screen = SDL_GetWindowSurface(window);
        if (screen == NULL) {
            outError(SDL_GetError());
            exit(-1);
        }
        if(!loadResources(image)){
            outError(SDL_GetError());
            exit(-1);
        }
    }
    if (resetGame) {
        stat.stat = STAT_MAINMENU;
        stat.substat = STAT_MAINMENU_CREATE;
    }
}

void outError(const char *err) {
    fprintf(stderr, "ERROR: %s", err);
}
void exitGame(int code) {
    freeResources(image);
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(code);
}
