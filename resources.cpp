#include<SDL2/SDL.h>

struct resource{
    SDL_Surface *enemy1L,*enemy1R,*enemy1U,*enemy1D,*enemy2D,*enemy2L,*enemy2R,*enemy2U;
};

bool loadResources(resource &res){
    res.enemy1L=SDL_LoadBMP("image/enemy1L.bmp");
    res.enemy1R=SDL_LoadBMP("image/enemy1R.bmp");
    res.enemy1U=SDL_LoadBMP("image/enemy1U.bmp");
    res.enemy1D=SDL_LoadBMP("image/enemy1D.bmp");
    res.enemy2L=SDL_LoadBMP("image/enemy2L.bmp");
    res.enemy2R=SDL_LoadBMP("image/enemy2R.bmp");
    res.enemy2U=SDL_LoadBMP("image/enemy2U.bmp");
    res.enemy2D=SDL_LoadBMP("image/enemy2D.bmp");
    SDL_Surface *checker=(SDL_Surface*)&res;
    for(int i=0;i<(sizeof(res)/sizeof(SDL_Surface*));i++){
        if(checker==NULL)return false;
        checker++;
    }
    return true;
}

void freeRecourses(resource &res){
    SDL_Surface *iter=(SDL_Surface*)&res;
    for(int i=0;i<(sizeof(res)/sizeof(SDL_Surface*));i++){
        if(iter){
            SDL_FreeSurface(iter);
        }
    }
}
