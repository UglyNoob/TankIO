#include<SDL2/SDL.h>

struct resource{
    SDL_Surface *blast1,*blast2,*blast3,*blast4,*enemy1L,*enemy1R,*enemy1U,*enemy1D,*enemy2L,*enemy2R,*enemy2U,*enemy2D,*enemy3L,*enemy3R,*enemy3U,*enemy3D,*p1tankL,*p1tankR,*p1tankU,*p1tankD,*p2tankL,*p2tankR,*p2tankU,*p2tankD,*enemymissile,*grass,*mintank,*over,*star,*steel,*steels,*tankmissile,*timer,*wall,*walls,*water;
};

bool loadResources(resource &res){
    res.blast1=SDL_LoadBMP("image/blast1.bmp");
    res.blast2=SDL_LoadBMP("image/blast2.bmp");
    res.blast3=SDL_LoadBMP("image/blast3.bmp");
    res.blast4=SDL_LoadBMP("image/blast4.bmp");
    res.enemy1L=SDL_LoadBMP("image/enemy1L.bmp");
    res.enemy1R=SDL_LoadBMP("image/enemy1R.bmp");
    res.enemy1U=SDL_LoadBMP("image/enemy1U.bmp");
    res.enemy1D=SDL_LoadBMP("image/enemy1D.bmp");
    res.enemy2L=SDL_LoadBMP("image/enemy2L.bmp");
    res.enemy2R=SDL_LoadBMP("image/enemy2R.bmp");
    res.enemy2U=SDL_LoadBMP("image/enemy2U.bmp");
    res.enemy2D=SDL_LoadBMP("image/enemy2D.bmp");
    res.enemy3L=SDL_LoadBMP("image/enemy3L.bmp");
    res.enemy3R=SDL_LoadBMP("image/enemy3R.bmp");
    res.enemy3U=SDL_LoadBMP("image/enemy3U.bmp");
    res.enemy3D=SDL_LoadBMP("image/enemy3D.bmp");
    res.p1tankL=SDL_LoadBMP("image/p1tankL.bmp");
    res.p1tankR=SDL_LoadBMP("image/p1tankR.bmp");
    res.p1tankU=SDL_LoadBMP("image/p1tankU.bmp");
    res.p1tankD=SDL_LoadBMP("image/p1tankD.bmp");
    res.p2tankL=SDL_LoadBMP("image/p2tankL.bmp");
    res.p2tankR=SDL_LoadBMP("image/p2tankR.bmp");
    res.p2tankU=SDL_LoadBMP("image/p2tankU.bmp");
    res.p2tankD=SDL_LoadBMP("image/p2tankD.bmp");
    res.star=SDL_LoadBMP("image/star.bmp");
    res.steel=SDL_LoadBMP("image/steel.bmp");
    res.steels=SDL_LoadBMP("image/steels.bmp");
    res.tankmissile=SDL_LoadBMP("image/tankmissile.bmp");
    res.timer=SDL_LoadBMP("image/timer.bmp");
    res.wall=SDL_LoadBMP("image/wall.bmp");
    res.walls=SDL_LoadBMP("image/walls.bmp");
    res.water=SDL_LoadBMP("image/water.bmp");
    res.enemymissile=SDL_LoadBMP("image/enemymissile.bmp");
    res.grass=SDL_LoadBMP("image/grass.bmp");
    res.mintank=SDL_LoadBMP("image/mintank.bmp");
    res.over=SDL_LoadBMP("image/over.bmp");
    res.p1tankL=SDL_LoadBMP("image/enemy3D.bmp");
    SDL_Surface **checker=(SDL_Surface**)&res;
    for(int i=0;i<(sizeof(res)/sizeof(SDL_Surface*));i++){
        if(*checker==NULL){
            printf("%d\n",i);
            return false;
        }
        checker++;
    }
    return true;
}

void freeResources(resource &res){
    SDL_Surface **iter=(SDL_Surface**)&res;
    for(int i=0;i<(sizeof(res)/sizeof(SDL_Surface*));i++){
        if(iter){
            SDL_FreeSurface(*iter);
        }
        iter++;
    }
}
