#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

int main(void) 
{
SDL_Surface *screen=NULL, *image=NULL, *PLAY=NULL, *SETTINGS=NULL, *EXIT=NULL, *MUSIC=NULL, *icon=NULL, *PLAY2=NULL, *SETTINGS2=NULL, *EXIT2=NULL, *MUSIC_CUT=NULL;
SDL_Rect positionecran, positionPLAY, positionSETTINGS, positionEXIT, positionMUSIC;
SDL_Event event;
int done=1, test=1;
if (SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Unable to initialize SDL:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
Mix_Music *music=NULL; 
Mix_Chunk *soundeffect=NULL;
music = Mix_LoadMUS("castaway.mp3");
Mix_PlayMusic(music,-1);

 
if (music==NULL) 
	{ 
		printf("Unable to load Music: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
screen= SDL_SetVideoMode(800,602,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen==NULL)
	{
		printf("Unable to set video mode:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
SDL_WM_SetIcon(IMG_Load("icon.png"),NULL);
SDL_WM_SetCaption("CASTAWAY",NULL);
image=IMG_Load("menu.png");
if (image==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
PLAY=IMG_Load("playv3.png");
if (PLAY==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
SETTINGS=IMG_Load("settingsv3.png");
if (SETTINGS==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
EXIT=IMG_Load("exitv3.png");
if (EXIT==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
MUSIC=IMG_Load("music.png");
if (MUSIC==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;
positionecran.h=image->h;

positionPLAY.x=335;
positionPLAY.y=250;

positionSETTINGS.x=335;
positionSETTINGS.y=315;

positionEXIT.x=335;
positionEXIT.y=380;

positionMUSIC.x=750;
positionMUSIC.y=10;

SDL_BlitSurface(image, NULL, screen, NULL);
SDL_BlitSurface(PLAY, NULL, screen, &positionPLAY);
SDL_BlitSurface(SETTINGS, NULL, screen, &positionSETTINGS);
SDL_BlitSurface(EXIT, NULL, screen, &positionEXIT);
SDL_BlitSurface(MUSIC, NULL, screen, &positionMUSIC);
SDL_Flip(screen);

PLAY2=IMG_Load("playV1.png");
if (PLAY2==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
SETTINGS2=IMG_Load("settingsV1.png");
	if (SETTINGS2==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
EXIT2=IMG_Load("exitV1.png");
if (EXIT2==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	} 
MUSIC_CUT=IMG_Load("musiccut.png");
if (MUSIC_CUT==NULL)
	{
		printf("Unable to load bitmap:%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
while (done==1)
	{
		SDL_WaitEvent(&event);
 		switch(event.type)
 			 {
				case SDL_QUIT:
     				done=0;
     				break;

    				case SDL_KEYDOWN:
    				switch (event.key.keysym.sym)
        			 {
         				 case SDLK_ESCAPE:
          				 done=0;
       		      			 break;

           				 case SDLK_p:
           					 if (!Mix_PlayingMusic())
            						{
							Mix_PlayMusic(music,-1);
							SDL_BlitSurface(image, NULL, screen, NULL);
							SDL_BlitSurface(PLAY, NULL, screen, &positionPLAY);
							SDL_BlitSurface(SETTINGS, NULL, screen, &positionSETTINGS);
							SDL_BlitSurface(EXIT, NULL, screen, &positionEXIT);
						        SDL_BlitSurface(MUSIC, NULL, screen, &positionMUSIC);
							SDL_Flip(screen);
							test=1;}
							
           					else 
							if (Mix_PausedMusic())
            						{ Mix_ResumeMusic();
							 SDL_BlitSurface(image, NULL, screen, NULL);
							 SDL_BlitSurface(PLAY, NULL, screen, &positionPLAY);
							 SDL_BlitSurface(SETTINGS, NULL, screen, &positionSETTINGS);
							 SDL_BlitSurface(EXIT, NULL, screen, &positionEXIT);
							 SDL_BlitSurface(MUSIC, NULL, screen, &positionMUSIC);
							 SDL_Flip(screen); 
							 test=1;		}
							
           					else 
            						{Mix_PauseMusic();
							 SDL_BlitSurface(image, NULL, screen, NULL);
							 SDL_BlitSurface(PLAY, NULL, screen, &positionPLAY);
							 SDL_BlitSurface(SETTINGS, NULL, screen, &positionSETTINGS);
							 SDL_BlitSurface(EXIT, NULL, screen, &positionEXIT);
							 SDL_BlitSurface(MUSIC_CUT, NULL, screen, &positionMUSIC);
							 SDL_Flip(screen);
							test=0;
							}
           					break;

          				case SDLK_s:
           						{Mix_HaltMusic();
							SDL_BlitSurface(image, NULL, screen, NULL);
							SDL_BlitSurface(PLAY, NULL, screen, &positionPLAY);
							SDL_BlitSurface(SETTINGS, NULL, screen, &positionSETTINGS);
							SDL_BlitSurface(EXIT, NULL, screen, &positionEXIT);
							SDL_BlitSurface(MUSIC_CUT, NULL, screen, &positionMUSIC);
							SDL_Flip(screen);
							test=0;}
           				break;
        			  }
      			 	break;

   				case SDL_MOUSEMOTION:
   				if  ((event.button.x > 330) && (event.button.x < 480) && (event.button.y > 230) && (event.button.y < 285))
					{
						SDL_BlitSurface(PLAY2, NULL, screen, &positionPLAY);
						SDL_Flip(screen);
						
					}
				else if ((event.button.x > 315) && (event.button.x < 465) && (event.button.y > 300) && (event.button.y < 365))
					{ 
						SDL_BlitSurface(SETTINGS2, NULL, screen, &positionSETTINGS);
						SDL_Flip(screen);	
					}
				else if ((event.button.x > 315) && (event.button.x < 465) && (event.button.y > 370) && (event.button.y < 440))
					{ 
						SDL_BlitSurface(EXIT2, NULL, screen, &positionEXIT);
						SDL_Flip(screen);
					}
				else
					{
						SDL_BlitSurface(image, NULL, screen, NULL);
						SDL_BlitSurface(PLAY, NULL, screen, &positionPLAY);
						SDL_BlitSurface(SETTINGS, NULL, screen, &positionSETTINGS);
						SDL_BlitSurface(EXIT, NULL, screen, &positionEXIT);
						if (test==1)
					{  SDL_BlitSurface(MUSIC, NULL, screen, &positionMUSIC);}
					else 
					{ SDL_BlitSurface(MUSIC_CUT, NULL, screen, &positionMUSIC);}
					  SDL_Flip(screen);
					}
				break;
  				}			
			}

SDL_FreeSurface(image);
SDL_FreeSurface(SETTINGS);
SDL_FreeSurface(SETTINGS2);
SDL_FreeSurface(PLAY2);
SDL_FreeSurface(PLAY);
SDL_FreeSurface(EXIT);
SDL_FreeSurface(EXIT2);
SDL_FreeSurface(MUSIC);
Mix_FreeChunk(soundeffect);
Mix_FreeMusic(music);
SDL_FreeSurface(MUSIC_CUT);
Mix_CloseAudio();
SDL_Quit();
return EXIT_SUCCESS;
}
