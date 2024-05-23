
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include<bits/stdc++.h>
#include"defs.h"
#include<SDL_ttf.h>
#include<windows.h>
using namespace std;
class Dot
{
    public:
		static const int DOT_WIDTH = 45;
		static const int DOT_HEIGHT = 40;

		//Maximum axis velocity of the dot
		static const int DOT_VEL = 10;

		//Initializes the variables
		Dot();
        void setClip(); //
		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e );

		//Moves the dot
		void move();
        void reset();
        void pause();
		//Shows the dot on the screen
		void render(bool isDead);

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;
		static const int ANIMATION_FRAME = 5;
        SDL_Rect animationClips[ANIMATION_FRAME];
		//The velocity of the dot
		int frame_count = 0;
		int mVelX, mVelY;
		int jump=0;

};
class ma
{
    public:
        	static const int ma_WIDTH = 38;
		static const int ma_HEIGHT = 45;
		//The dimensions of the dot
        bool checkEnemyCollision(SDL_Rect hitbox);
        void move();
		ma();
		void render();
		void reset();
		void pause();

private:
        SDL_Rect enemyHitbox[4];
		int t1PosX, t1PosY;
		int t2PosX, t2PosY;
		int r1PosX, r1PosY;
		int r2PosX, r2PosY;
};
Dot dot;
ma ma;
bool flag=false;
bool start=false;
bool isDead = false;
int RUN_DISTANCE;
void render_gameover(SDL_Renderer* &gRenderer);
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture gDotTexture,gPlayerjump;
LTexture gBGTexture;
LTexture gmaTexture;
LTexture gma2Texture;
LTexture grocketTexture;
LTexture grocket2Texture;
LTexture gwarningTexture;
LTexture scoreTexture;
LTexture highScoreTexture;
LTexture gStart_Texture;
LTexture gEnd_Texture;
LTexture gReplay_Texture;
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
SDL_Rect playerHitbox = {100, ground, 0, 0};
TTF_Font *gFont = NULL;
SDL_Color textColor = {0, 0, 0, 255}; // Black
Mix_Music *gMusic = NULL;
Mix_Chunk *gjump = NULL;
Mix_Chunk *gdeath = NULL;
int score=0;
int high_score=0;

void intro(){
    SDL_Event e;
    bool isIntro=true;

    while(isIntro){
        gStart_Texture.render(gRenderer,0,0);
        //loadstart();
        while(SDL_PollEvent(&e)){
            if(e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_3)
            {
                RUN_DISTANCE=5;
                isIntro =false;
            }
            if(e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_2)
            {
                RUN_DISTANCE=4.5;
                isIntro =false;
            }
            if(e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_1)
            {
                RUN_DISTANCE=4;
                isIntro =false;
            }

        }
        SDL_RenderPresent(gRenderer);
    }

}
void ShowScore(){
    scoreTexture.render(gRenderer, 10, 10);
}
void Show_High_Score(){
    highScoreTexture.render(gRenderer, 10, 10);
}
void background_music()
{
    Mix_PlayMusic(gMusic,-1);
}
void nhay_music()
{
    Mix_PlayChannel(-1,gjump,0);
}
void death_music()
{
    Mix_PlayChannel(-1,gdeath,0);
}
Dot::Dot()
{
    //Initialize the offsets
    mPosX = 100;
    mPosY = ground;
    playerHitbox = {mPosX, mPosY, 38, 45};
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    jump=0;

    for (int i=0; i<ANIMATION_FRAME; i++)
    {
        animationClips[i] = {i*38, 0, 38, 45};
    }

}


void Dot::move()
{

   if(jump == 0) return;

    // Jump up
    if(jump == -1 && mPosY >= (ground-player_jump))

        {
            mPosY -= mVelY;
        }




    // When character position is at the highest point
    if(mPosY <= (ground-player_jump))
    {
        jump = 1;
    }

    // Fall back
    if(jump == 1 && mPosY <= ground)
    {
        {
            mPosY += mVelY;
        }
    }

    // When character position is on the ground
    if (mPosY >= ground)
    {
        jump = 0;
    }
    playerHitbox = {mPosX, mPosY, 38, 45};

   // mPosY -= mVelY;
}

void Dot::render(bool isDead)
{
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
  // SDL_RenderDrawRect(gRenderer, &playerHitbox);
    //Show the dot
    if(mPosY<ground)
    {
        gPlayerjump.render(gRenderer, mPosX,mPosY);
    }
    else
    {
    if (isDead){
            gDotTexture.render(gRenderer, mPosX, mPosY, &animationClips[0] );
    }
	else gDotTexture.render(gRenderer, mPosX, mPosY, &animationClips[frame_count /  5] );
	frame_count++;
	if (frame_count / 5 >= ANIMATION_FRAME)
    {
        frame_count = 0;
    }
    }
}

ma::ma()
{
    //Initialize the offsets
    t1PosX = SCREEN_WIDTH;
    t1PosY = ground;

    t2PosX = SCREEN_WIDTH+500;
    t2PosY = ground;

    r1PosX = SCREEN_WIDTH+4500;
    r1PosY = ground;

    r2PosX = -9500;
    r2PosY = ground;

}
void ma::render()
{
  /*  for (int i = 0; i < 4; i++){
        SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
       SDL_RenderDrawRect(gRenderer, &enemyHitbox[i]);
    }*/
    //Show the dot
	gmaTexture.render(gRenderer, t1PosX, t1PosY );
	 gma2Texture.render(gRenderer, t2PosX, t2PosY );
	 grocketTexture.render(gRenderer, r1PosX, r1PosY );
	 grocket2Texture.render(gRenderer, r2PosX, r2PosY );
	 if(abs(r2PosX - 100) <= 1000)
     {
         gwarningTexture.render(gRenderer, 0, ground);
     }
     if(r1PosX<=900)
     {
         gwarningTexture.render(gRenderer,740,ground);
     }

}

bool ma::checkEnemyCollision(SDL_Rect hitbox){
    for (int i = 0; i < 4; i++){
        if (SDL_HasIntersection(&hitbox, &enemyHitbox[i]))
        {
            return true;
        }
    }
    return false;
}

void ma::move()
{

    //Move the dot left or right
    t1PosX-= RUN_DISTANCE;
    t2PosX-= RUN_DISTANCE;
    r1PosX-= RUN_DISTANCE*1.5;
    r2PosX+= RUN_DISTANCE*1.25;
   //if(dem==0||dem==1)
    if(t1PosX+ ma_WIDTH < 0) t1PosX = SCREEN_WIDTH+300;
    if(t2PosX+ ma_WIDTH < 0) t2PosX = SCREEN_WIDTH+500+rand()%100;


    if(r1PosX< 0)
    {
        r1PosX= SCREEN_WIDTH+4500;

    }
    if(r2PosX>SCREEN_WIDTH)
    {
        r2PosX= -9500-(rand()%20000+10000);

    }


    enemyHitbox[0].x = t1PosX;
    enemyHitbox[0].y = t1PosY;
    enemyHitbox[0].w = gmaTexture.getWidth();
    enemyHitbox[0].h = gmaTexture.getHeight();
    enemyHitbox[1].x = t2PosX;
    enemyHitbox[1].y = t2PosY;
    enemyHitbox[1].w = gma2Texture.getWidth();
    enemyHitbox[1].h = gma2Texture.getHeight();
    enemyHitbox[2].x = r1PosX;
    enemyHitbox[2].y = r1PosY;
    enemyHitbox[2].w = grocketTexture.getWidth();
    enemyHitbox[2].h = grocketTexture.getHeight();
    enemyHitbox[3].x = r2PosX;
    enemyHitbox[3].y = r2PosY;
    enemyHitbox[3].w = grocket2Texture.getWidth();
    enemyHitbox[3].h = grocket2Texture.getHeight();

    //If the dot went too far to the left or right
}
void ma::reset()
{
    t1PosX = SCREEN_WIDTH;
    t1PosY = ground;

    t2PosX = SCREEN_WIDTH+500;
    t2PosY = ground;

    r1PosX = SCREEN_WIDTH+4500;
    r1PosY = ground;

    r2PosX = -9500;
    r2PosY = ground;
}
void Dot::reset()
{
    mPosX=100;
    mPosY=ground;
}
void ma::pause()
{
    t1PosX=t1PosX;
    t1PosY=t1PosY;
    t2PosX=t2PosX;
    t2PosY=t2PosY;
    r1PosX=r1PosX;
    r1PosY=r1PosY;
    r2PosX=r2PosX;
    r2PosY=r2PosY;
}
void Dot::pause()
{
    mPosX=mPosX;
    mPosY=mPosY;
}
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		printf( "Could not initialize SDL and SDL_mixer! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "DINO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				//Initialize SDL_ttf
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}

				//Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
bool loadMedia()
{
    gFont=TTF_OpenFont("font.ttf",16);
	//Loading success flag
	bool success = true;

	//Load dot texture

	if( !gDotTexture.loadFromFile( "img/character1.png", gRenderer ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}
	else
    {
        gSpriteClips[ 0 ].x =   0;
		gSpriteClips[ 0 ].y =   0;
		gSpriteClips[ 0 ].w =  38;
		gSpriteClips[ 0 ].h = 45;

		gSpriteClips[ 1 ].x =  38;
		gSpriteClips[ 1 ].y =   0;
		gSpriteClips[ 1 ].w =  38;
		gSpriteClips[ 1 ].h = 45;

		gSpriteClips[ 2 ].x = 76;
		gSpriteClips[ 2 ].y =   0;
		gSpriteClips[ 2 ].w =  38;
		gSpriteClips[ 2 ].h = 45;

		gSpriteClips[ 3 ].x = 114;
		gSpriteClips[ 3 ].y =   0;
		gSpriteClips[ 3 ].w =  38;
		gSpriteClips[ 3 ].h = 45;

		gSpriteClips[ 4 ].x = 152;
		gSpriteClips[ 4 ].y =   0;
		gSpriteClips[ 4 ].w =  38;
		gSpriteClips[ 4 ].h = 45;
    }


	if( !gPlayerjump.loadFromFile( "img/character.png", gRenderer ) )
	{
		printf( "Failed to load dot texture!\n" );
		success = false;
	}

	//Load background texture
	if( !gBGTexture.loadFromFile( "img/hills_background.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	if(!gEnd_Texture.loadFromFile("img/gameover.png",gRenderer))
    {
        cout<<"Failed to load gameover texture! /n";
        success=false;
    }
    if(!gStart_Texture.loadFromFile("img/start.png",gRenderer))
    {
        cout<<"Failed to load start texture! /n";
        success=false;
    }
if( !gmaTexture.loadFromFile( "img/ma.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	if( !gma2Texture.loadFromFile( "img/ma2.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	if( !grocketTexture.loadFromFile( "img/rocket_2.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	if( !gReplay_Texture.loadFromFile( "img/replay.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	if( !grocket2Texture.loadFromFile( "img/rocket_1.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	if( !gwarningTexture.loadFromFile( "img/warning_signal.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	gMusic = Mix_LoadMUS("music/mission-imposible.mp3");
    if(gMusic == NULL)
    {
       printf("Failed to load background music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    // load sound when jump
    gjump = Mix_LoadWAV("music/jumping.mp3");
    if(gjump == NULL)
    {
        printf("Failed to load jumping sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    // Load sound when die
    gdeath = Mix_LoadWAV("music/death.mp3");
    if(gdeath == NULL)
    {
        printf("Failed to load death sound effect! SDL_mixer Error: %s\n" , Mix_GetError() );
        success = false;
    }
    SDL_Color textColor = {255, 255, 255, 255};
 /*   if (scoreTexture.loadFromRenderedText("Score: ", textColor, gFont, gRenderer) == NULL){
        cout << "false" << endl;
        success = false;
    }*/   //highScoreTexture.loadFromRenderedText("High Score: ", textColor, gFont, gRenderer);
	return success;
}

void close()
{
	//Free loaded images
	gDotTexture.free();
	gBGTexture.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	gFont=NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
	TTF_Quit();
}
void Dot::handleEvent( SDL_Event& e )
{
     if(e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        if ((e.key.keysym.sym == SDLK_SPACE || e.key.keysym.sym== SDLK_UP))
        {
           // std::cout << 1 << std::endl;

           if(isDead==false) nhay_music();
            if(jump== 0)
            {
                jump = -1;
                mVelY = 4 ;

            }
        }
        if(e.key.keysym.sym==SDLK_r)
                        {
                            ma.reset();
                            dot.reset();
                            isDead = false;
                          flag=false;
                            ma.move();
                          score=0;
                        }

    }
}

void loadend(bool flag)
{
    if(flag==true)
    {
        gEnd_Texture.render(gRenderer,330,170);
        gReplay_Texture.render(gRenderer,260,230);
    }
}
int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
            intro();

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			int frame=0;

			//The background scrolling offset
			int scrollingOffset = 0;

			//While application is running
			while( !quit )
			{







    //Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT  )
					{
						quit = true;
					}
					//Handle input for the dot
					dot.handleEvent( e );
					//background_music();

				}



                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
              //  ShowScore();
              //  Show_High_Score();
				//Move the dot
			//	gameover(ma,flag);
               if(ma.checkEnemyCollision(playerHitbox))
               {
                   if(isDead==false)
                   {
                       death_music();
                   }
                   isDead = true;
                   flag=true;
                   ma.pause();
                   dot.pause();
                    dot.render(isDead);
                   scrollingOffset = 0;
                   flag=true;

               }
             if(isDead==false)
             {


                    dot.move();
                    ma.move();
                    score++;
             }
				//Scroll background
				--scrollingOffset;
				if( scrollingOffset < -gBGTexture.getWidth() )
				{
					scrollingOffset = 0;
				}

				//Clear screen


				//Render background
				gBGTexture.render(gRenderer, scrollingOffset, 0 );
				gBGTexture.render(gRenderer, scrollingOffset + gBGTexture.getWidth(), 0 );
                ma.render();
                dot.render(isDead);
                loadend(flag);

                ++frame;
				//Cycle animation
				if( frame / 5>= WALKING_ANIMATION_FRAMES )
				{
					frame = 0;
				}

				//Update screen
				SDL_RenderPresent( gRenderer );



			}}
	}

	//Free resources and close SDL

	return 0;
}

