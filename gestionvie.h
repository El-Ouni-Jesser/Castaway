#ifndef struct_H_INCLUDED
#define struct_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct vie
{
SDL_Surface *coeur0;
SDL_Surface *coeur1;
SDL_Surface *coeur2;
SDL_Surface *coeur3;
SDL_Rect pos;
int nbr_vie;
} vie;
typedef struct perso
{
	SDL_Surface *hero;
    	SDL_Rect positionperso;
	//Animation Player_Animation;
	//SDL_Surface *Player_Health[3];
	//int NUM;
       // int mv[2]={0,0};
        //int anim;
	//int P_health;
}perso;

typedef struct ENTITE_secondaire_object
{
SDL_Surface* objet;
SDL_Rect positionobjet;
}ENTITE_secondaire_object ;

typedef struct Temps
{
Uint32 temps;
} Temps;

void initialiser_vie (vie *v);
void gest_vie (vie *v,perso *hero,ENTITE_secondaire_object *o);
void affich_vie(vie *v,SDL_Surface *screen);
TTF_Font *font ;
void loadFont();
void closeFont();

#endif









