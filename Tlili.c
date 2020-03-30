#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct enemy
{
	SDL_Surface *enemy;
    	SDL_Rect positionenemy;
}enemy;

typedef struct Personnage
{	
	
}Personnage;

void Init_enemy(*e)
{enemy e ;
	e.Anim_Ennemi=IMG_Load(".png");
	e.positionenemy.x=;
	e.positionenemy.y=;
	e.positionenemy.h=Mob.Anim_Ennemi->h;
	e.positionenemy.w=Mob.Anim_Ennemi->w;
	return e;
	}

void Afficher_enemy(Enemy e,SDL_Surface *ecran)
{
SDL_BlitSurface (e.Anim_Ennemi,NULL,ecran,&e.positionenemy);
}

int collision(Player hero,enemy e)
{
int collision=1;
if(hero.positiontext.x + hero.positiontext. w< e.positionenemyy. x 
|| hero.positiontext.x> e.positionenemyy. x + e.positionenemyy. w
|| hero.positiontext.y + hero.positiontext.h< e.positionenemyy. y 
|| hero.positiontext.y> e.positionenemyy. y + e.positionenemyy. h )
{
collision=0;
}
else{
collision=1;
}
return collision;
}

Direction mvt_aleatoire (Ennemi Mob , SDL_Rect max , SDL_Rect min  )
{
    
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    Direction sens ;

 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 20) /* Si 20 ms se sont écoulées depuis le dernier tour de boucle */
        {switch (sens ) 
 {case LEFT :
            Mob.Pos_Ennemi.x-=5;

                break ;  
case RIGHT :
 Mob.Pos_Ennemi.x+=5 ;
break ;}
if ( Mob.Pos_Ennemi.x >= max.x )
                    sens = LEFT ;

else if ( Mob.Pos_Ennemi.x <=min.x )
{
sens =RIGHT ;
                    
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }}


return  sens ;
}

