#include"defs.h"
#include"Graphics.h"
Graphics::Graphics()
{

    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}
Graphics::~Graphics()
{
    free();
}
void Graphics::free()
{
    if(mTexture!=NULL)
    {
        SDL_DestroyTexture(mTexture);
         mTexture = NULL;
         mWidth = 0;
         mHeight = 0;
    }
}
bool Graphics::LoadMedia_file(string path, SDL_Renderer* &gRenderer)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL)
    {
        cout << "Could not load image! SDL_image Error: " << IMG_GetError() << endl;
    }
    else
    {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(newTexture == NULL)
        {
            cout << "Could not create Texture from image! SDL Error: " << SDL_GetError() << endl;
        }
        else
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    mTexture = newTexture;
    return (mTexture!=NULL);
}
bool Graphics::LoadText_file(string textureText, SDL_Color textColor, SDL_Renderer* &gRenderer, TTF_Font *&gFont)
{
    free();
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if(textSurface != NULL)
    {
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if(mTexture == NULL)
        {
            cout << "Unable to create texture from text surface! SDL Error: " << SDL_GetError() << endl;
        }
        else
        {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    return (mTexture!=NULL);
}

void Graphics::render(int x, int y, SDL_Renderer* &gRenderer)
{
    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

SDL_Texture* Graphics::getTexture()
{
    return mTexture;
}

int Graphics::getHeight()
{
    return mHeight;
}

int Graphics::getWidth()
{
    return mWidth;
}
bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, const char* WINDOW_TITLE)
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0)
    {
        cout << "Error: " << SDL_GetError() << endl;
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            cout << "Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == NULL)
            {
                cout << "Error:" << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);

                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) && imgFlags))
                {
                    cout << "Error: " << IMG_GetError() << endl;
                    success = false;
                }

                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "Error: %s\n", Mix_GetError() );
                    success = false;
                }

                if( TTF_Init() == -1 )
                {
                    cout << "Error:" << TTF_GetError() << endl;
                    success = false;
                }

            }
        }
    }
    return success;
}
bool loadMedia(Graphics &gPlayer_jump, Graphics &gPlayer_background, Graphics &gThreat1, Graphics &gThreat2, Graphics &gPause,
               Graphics &gResume, Graphics &gScore, Graphics &game_over,Graphics &play_again, Graphics &exit_game,
               Mix_Music *&gMusic, Mix_Chunk *&gjump, Mix_Chunk *&gdeath, TTF_Font *&gFont, SDL_Renderer* &gRenderer, Graphics &gPlayer_ground, SDL_Rect &player_rect,
               int &frame_width, Graphics &gHiscore, Graphics &gRocket1, Graphics &gRocket2, Graphics &gWarning, Graphics &how_to_play)
{
    bool success = true;

    // Load character animation
    if(!gPlayer_ground.LoadMedia_file("img\\character_animation.png", gRenderer))
    {
        cout << "Could not load character animation" << endl;
        success = false;
    }
    else
    {
        frame_width = gPlayer_ground.getWidth()/5;
        player_rect.w = frame_width;
        player_rect.h = gPlayer_ground.getHeight();
        player_rect.x = 0;
        player_rect.y = 0;
    }

    // Load character when jump
    if(!gPlayer_jump.LoadMedia_file("img\\character.png", gRenderer))
    {
        cout << "Could not load character when jump" << endl;
        success = false;
    }

    // Load background
    if(!gPlayer_background.LoadMedia_file("img\\hills_background.png", gRenderer))
    {
        cout << "Could not load Dino background" << endl;
        success = false;
    }

    // Load threat_1
    if(!gThreat1.LoadMedia_file("img\\obstacle_1.png", gRenderer))
    {
        cout << "Could not load Threat 1" << endl;
        success = false;
    }

    // Load threat_2
    if(!gThreat2.LoadMedia_file("img\\obstacle_2.png", gRenderer))
    {
        cout << "Could not load Threat 2" << endl;
        success = false;
    }
    // Load rocket1
    if(!gRocket1.LoadMedia_file("img\\rocket_1.png", gRenderer))
    {
        cout << "Could not load Rocket 1" << endl;
        success = false;
    }
    // Load rocket 2
    if(!gRocket2.LoadMedia_file("img\\rocket_2.png", gRenderer))
    {
        cout << "Could not load Rocket 2" << endl;
        success = false;
    }

    // Load Warning signal
    if(!gWarning.LoadMedia_file("img\\warning_signal.png", gRenderer))
    {
        cout << "Could not load Warning Signal!" << endl;
        success = false;
    }

    // Load how to play png
    if(!how_to_play.LoadMedia_file("img\\how_to_play.png", gRenderer))
    {
        cout << "Could not load How to play png" << endl;
        success = false;
    }

    // Load pause image
    if(!gPause.LoadMedia_file("img\\pause.png", gRenderer))
    {
        cout << "Could not load pause img" << endl;
        success = false;
    }

    // Load resume image
    if(!gResume.LoadMedia_file("img\\resume.png", gRenderer))
    {
        cout << "Could not load resume img" << endl;
        success = false;
    }

    // Open the font
    gFont = TTF_OpenFont("font.ttf", 16);
    if(gFont == NULL)
    {
        cout << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    }
    else
    {
        SDL_Color textColor = {0, 0, 0, 255}; // black
        // Load current score
        if(!gScore.LoadText_file("Score:", textColor, gRenderer, gFont))
        {
            cout << "Unable to render score texture!" << endl;
            success = false;
        }
        // Load high score
        if(!gHiscore.LoadText_file("Hi: ", textColor, gRenderer, gFont))
        {
            cout << "Unable to render hi score texture!" << endl;
            success = false;
        }
        // Load texts on screen
        if(!game_over.LoadText_file("GAME OVER!", textColor, gRenderer, gFont))
        {
            cout << "Unable to render game over texture!" << endl;
            success = false;
        }
        if(!play_again.LoadText_file("Press R to play again", textColor, gRenderer, gFont))
        {
            cout << "Unable to render play again texture!" << endl;
            success = false;
        }
        if(!exit_game.LoadText_file("Press Esc to quit", textColor, gRenderer, gFont))
        {
            cout << "Unable to render exit game texture!" << endl;
            success = false;
        }

    }
    // Load music
    gMusic = Mix_LoadMUS("music\\mission-imposible.mp3");
    if(gMusic == NULL)
    {
        cout << "Failed to load background music! SDL_mixer Error: " << Mix_GetError() << endl;
        success = false;
    }

    // load sound when jump
    gjump = Mix_LoadWAV("music\\jumping.wav");
    if(gjump == NULL)
    {
        cout << "Failed to load jumping sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
        success = false;
    }

    // Load sound when die
    gdeath = Mix_LoadWAV("music\\death.wav");
    if(gdeath == NULL)
    {
        cout << "Failed to load death sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
        success = false;
    }

    return success;

}
void closeLoad(Graphics &gPlayer_jump, Graphics &gPlayer_background, Graphics &gThreat1, Graphics &gThreat2,
          Graphics &gPause, Graphics &gResume, Graphics &gScore, Graphics &game_over, Graphics &play_again,
          Graphics &exit_game, Mix_Music *&gMusic, Mix_Chunk *&gjump, Mix_Chunk *&gdeath, TTF_Font *&gFont, Graphics &current_score, SDL_Window *&gWindow, SDL_Renderer* &gRenderer,
           Graphics &gPlayer_ground, Graphics &gHiscore, Graphics &gRocket1, Graphics &gRocket2, Graphics &gWarning, Graphics &how_to_play)
{


    gPlayer_jump.free();
    gPlayer_ground.free();
    gPlayer_background.free();
    gScore.free();
    gHiscore.free();
    current_score.free();
    gPause.free();
    gResume.free();
    gThreat1.free();
    gThreat2.free();
    gRocket1.free();
    gRocket2.free();
    gWarning.free();
    game_over.free();
    play_again.free();
    exit_game.free();
    how_to_play.free();

    TTF_CloseFont(gFont);
    gFont = NULL;
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
    Mix_FreeChunk(gjump);
    gjump = NULL;
    Mix_FreeChunk(gdeath);
    gdeath = NULL;
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    TTF_Quit();
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
}
