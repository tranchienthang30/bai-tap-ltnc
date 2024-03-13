#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"
//#include "game.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
int main(int argc, char *argv[])
{
    int x=400,y=525;
    Graphics graphics;
    graphics.init();

   SDL_Texture* background = graphics.loadTexture("Background.png");
    graphics.prepareScene(background);

    graphics.presentScene();
//    waitUntilKeyPressed();

    SDL_Texture* spongeBob = graphics.loadTexture("Character.png");
    graphics.renderTexture(spongeBob, x, y);

	graphics.presentScene();
	waitUntilKeyPressed();

     SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) == 0) SDL_Delay(100);
            else if(e.type==SDL_QUIT) break;
             else if(e.type==SDL_KEYDOWN)
             {

                     cerr<<"_"<<SDL_GetKeyName(e.key.keysym.sym)<<"_"<<endl;
                     switch(e.key.keysym.sym){
                 case SDLK_UP: y-=step;break;

                case SDLK_DOWN: y+=step;break;
                case SDLK_RIGHT: x+=step;break;
                case SDLK_LEFT:  x-=step;break;

                     }
graphics.renderTexture(spongeBob, x, y);
graphics.presentScene();

             }
    }
	SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;;
    SDL_DestroyTexture( background );
    background = NULL;

    graphics.quit();
    return 0;
}
