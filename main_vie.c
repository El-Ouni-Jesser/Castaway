
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include  "fonctionr.h"


int main(void) {
SDL_Surface *screen;
SDL_Surface *barre_vie;
SDL_Event event;

Vie *v;
int cont=1;
perso *hero;
ENTITE_secondaire_object *o;

screen= SDL_SetVideoMode(350,550,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set video mode:%s\n",SDL_GetError());
return(-1);
}
barre_vie=IMG_Load("barre des vie.png");

while(cont)
{
initialiser_vie(v);
gest_vie (v,hero,o);
affich_vie(v,screen);
loadFont();
closeFont();

SDL_FreeSurface(screen);
}
return 0;
}
