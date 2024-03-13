#ifndef GRAPHICS
#define GRAPHICS
#include"defs.h"
using namespace std;
bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer, const char* WINDOW_TITLE);
class Graphics
{
public:
    Graphics(); // Constructor
    ~Graphics(); // Destructor


    void free();

    // Load media
    bool LoadMedia_file(string path, SDL_Renderer* &gRenderer);
    // Load texts
    bool LoadText_file(string textureText, SDL_Color textColor, SDL_Renderer* &gRenderer, TTF_Font *&gFont);

    //Renders texture at given point
    void render( int x, int y,SDL_Renderer* &gRenderer);

    //Gets texture dimensions
    SDL_Texture* getTexture();
    int getWidth();
    int getHeight();

private:
    SDL_Texture* mTexture;

    //Texture dimensions
    int mWidth;
    int mHeight;
};
// nhảy, nền, chướng ngại vật 1, chướng ngại vật 2,
bool loadMedia(Graphics &gPlayer_jump, Graphics &gPlayer_background, Graphics &gThreat1, Graphics &gThreat2, Graphics &gPause,
               Graphics &gResume, Graphics &gScore, Graphics &game_over,Graphics &play_again, Graphics &exit_game,
               Mix_Music *&gMusic, Mix_Chunk *&gjump, Mix_Chunk *&gdeath, TTF_Font *&gFont, SDL_Renderer* &gRenderer, Graphics &gPlayer_ground, SDL_Rect &player_rect,
               int &frame_width, Graphics &gHiscore, Graphics &gRocket1, Graphics &gRocket2, Graphics &gWarning, Graphics &how_to_play);
void close(Graphics &gPlayer_jump, Graphics &gPlayer_background, Graphics &gThreat1, Graphics &gThreat2,
          Graphics &gPause, Graphics &gResume, Graphics &gScore, Graphics &game_over, Graphics &play_again,
          Graphics &exit_game, Mix_Music *&gMusic, Mix_Chunk *&gjump, Mix_Chunk *&gdeath, TTF_Font *&gFont, Graphics &current_score, SDL_Window *&gWindow, SDL_Renderer* &gRenderer,
           Graphics &gPlayer_ground, Graphics &gHiscore, Graphics &gRocket1, Graphics &gRocket2, Graphics &gWarning, Graphics &how_to_play);
#endif // GRAPHICS
