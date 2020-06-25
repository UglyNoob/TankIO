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
SDL_Renderer* renderer;
struct resource image;

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
        SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,128,255));
        pos.x=0;pos.y=0;
        SDL_Surface **iter=(SDL_Surface**)&image;
        for(int i=0;i<(sizeof(image)/sizeof(SDL_Surface*));i++){
            SDL_BlitSurface(*iter,NULL,screen,&pos);
            pos.x+=(*iter)->w;
            if((pos.x+pos.y)>599){
                pos.x=0;
                pos.y+=height;
                height=0;
            }else{
                height=(*iter)->w>height?(*iter)->w:height;
            }
            iter++;
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
        stat = STAT_MAINMENU;
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
