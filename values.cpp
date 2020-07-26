#include<SDL2/SDL.h>
#include "values.h"
#include<cstdio> 
#include<cstring>

int check_size;

bool loadResources(resource &res){
    res.blast1=SDL_LoadBMP("image/blast1.bmp");
    res.blast2=SDL_LoadBMP("image/blast2.bmp");
    res.blast3=SDL_LoadBMP("image/blast3.bmp");
    res.blast4=SDL_LoadBMP("image/blast4.bmp");
    res.blast5=SDL_LoadBMP("image/blast5.bmp");
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
    res.font_resource=SDL_LoadBMP("image/font.bmp");
    
    SDL_Surface **checker=(SDL_Surface**)&res;
    
    check_size=sizeof(res)/sizeof(SDL_Surface*);
    for(int i=0;i<check_size;i++){
        if(*checker){
        	SDL_SetColorKey(*checker,
				1,
				SDL_MapRGB((*checker)->format,255,255,255));
		}else{
            printf("%d\n",i);
            return false;
        }
        checker++;
    }
    SDL_SetColorKey(res.font_resource,1,SDL_MapRGB(res.font_resource->format,0,0,0));
    
    return true;
}

void freeResources(resource &res){
    SDL_Surface **iter=(SDL_Surface**)&res;
    for(int i=0;i<check_size;i++){
        if(iter){
            SDL_FreeSurface(*iter);
        }
        iter++;
    }
}

void renderText(resource &res,SDL_Surface* at,const char* text,SDL_Rect pos,int op,bool center){
	int len=strlen(text);
	SDL_Rect iter;
	iter.w=FONT_WIDTH;
	iter.h=FONT_HEIGHT;
	iter.y=0;
	if(center){
		pos.x-=len*FONT_WIDTH/2+(len-1)*op/2;
		pos.y-=FONT_HEIGHT/2;
	}
	for(int i=0;i<len;i++){
		if(text[i]==' ') {
			pos.x+=FONT_WIDTH+op;
			continue;
		}
		if(text[i]<='9'&&text[i]>='0'){
			iter.x=(text[i]-'0')*FONT_WIDTH;
			SDL_BlitSurface(res.font_resource,&iter,at,&pos);
		}else if(text[i]>='A'&&text[i]<='Z'){
			iter.x=(text[i]-'A')*FONT_WIDTH+10*FONT_WIDTH;
			SDL_BlitSurface(res.font_resource,&iter,at,&pos);
		}else if(text[i]>='a'&&text[i]<='z'){
			iter.x=(text[i]-'a')*FONT_WIDTH+10*FONT_WIDTH;
			SDL_BlitSurface(res.font_resource,&iter,at,&pos);
		}
		pos.x+=FONT_WIDTH+op;
	}
}
