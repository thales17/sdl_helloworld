#include <SDL2/SDL.h>

#define DEFAULT_WIDTH 1280
#define DEFAULT_HEIGHT 720

int main(int argc, char *args[]) {
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  }

  /* Create SDL Window */
  window = SDL_CreateWindow(
    "SDL Starter",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    DEFAULT_WIDTH,
    DEFAULT_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  if(window == NULL) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
  }

  /* Create SDL Renderer */
  renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  if(renderer == NULL) {
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
  }

  if (SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF) > 0) {
    printf("SDL_SetRenderDrawColor Error: %s\n", SDL_GetError());
  }

  SDL_Rect rect;
  rect.x = 100;
  rect.y = 100;
  rect.w = 100;
  rect.h = 100;

  if(SDL_RenderFillRect(renderer, &rect) > 0) {
    printf("SDL_RenderFillRect Error: %s\n", SDL_GetError());
  }
  SDL_RenderPresent(renderer);

  /* Delay */
  SDL_Delay( 5000 );

  /* Quit the program */
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}