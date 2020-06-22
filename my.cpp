#define _CRT_SECURE_NO_WARNINGS

#include "values.h"
#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<cstdio>

void exitGame(int);
void outError(const char*);
void gaming();
void init(bool, bool);

char stat;

SDL_Window* window;
SDL_Surface* screen;

int main(int argc, char** argv) {
    init(true, true);
    gaming();
    exitGame(0);
    return 0;
}

void gaming() {
    SDL_Surface* image=SDL_LoadBMP("tank/enemy2D.bmp");
    SDL_Rect pos;
    pos.w=100;
    pos.h=100;
    pos.y=250;
    while(true){
        pos.x++;
        SDL_FillRect(screen,&pos,SDL_MapRGB(screen->format,0,0,255));
        SDL_UpdateWindowSurface(window);
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
    }
    if (resetGame) {
        stat = STAT_MAINMENU;
    }
}

void outError(const char *err) {
    fprintf(stderr, "ERROR: %s", err);
}
void exitGame(int code) {
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(code);
}
