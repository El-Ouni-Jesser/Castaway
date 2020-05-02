#include  "fonctionr.h"


void initialiser_vie (vie *v)
{
v->nbr_vie=3;
/*v->pos.w=v->image_vie->w;
v->pos.h=v->image_vie->h;*/
v->pos.w=350;
v->pos.h=550;
v->pos.x=0;
v->pos.y=0;
}

void gest_vie (vie *v,perso *hero,ENTITE_secondaire_object *o)
{
  if (collision_object (&hero,&o)==1)
     {v->nbr_vie--;}
}

void affich_vie(vie *v,SDL_Surface *screen)
{
         if(v->nbr_vie==3)
         {
           v->coeur3=IMG_Load("coeur3.png");
           SDL_BlitSurface(v->coeur3,&v->pos,screen,NULL);
          }
        if(v->nbr_vie==2)
         {
           v->coeur2=IMG_Load("coeur2.png");
           SDL_BlitSurface( v->coeur1,&v->pos,screen,NULL);
         }
      if(v->nbr_vie==1)
        {
         v->coeur1=IMG_Load("coeur1.png");
         SDL_BlitSurface( v->coeur2,&v->pos,screen,NULL);
        }
      if(v->nbr_vie==0)
         {
            v->coeur0=IMG_Load("coeur0.png");
            SDL_BlitSurface( v->coeur3,&v->pos,screen,NULL);
           // enigme();
          }

}


