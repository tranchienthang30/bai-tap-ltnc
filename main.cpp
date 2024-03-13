#include <iostream>
#include"Graphics.h"
#include"defs.h"
#include<SDL.h>
const char* WINDOW_TITLE="HERO IN";
using namespace std;
Graphics gPlayer_jump, gPlayer_background,gThreat1, gThreat2,gRocket1, gRocket2, gWarning,gPause, gResume,how_to_play,gScore, current_score, gHiscore, hi_score,game_over,play_again, exit_game,gPlayer_ground;
int frame_width;
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
int main(int argc,char*argv[])
{
   SDL_Window* window=NULL;
   SDL_Renderer* render=NULL;
   waitUntilKeyPressed();
   init(window,render,WINDOW_TITLE);
   SDL_Event e;
   while (true) {
        if ( SDL_WaitEvent(&e) == 0) SDL_Delay(100);
            else if(e.type==SDL_QUIT) break;
             else if(e.type==SDL_KEYDOWN)
             {

                     cerr<<"_"<<SDL_GetKeyName(e.key.keysym.sym)<<"_"<<endl;


             }
                     switch(e.key.keysym.sym){
                case SDLK_UP: cerr<<1;

                     }
   }
    return 0;
}
