#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main() {

  printf("Hello World!");
  //this creates the window, only for a flash second 
  SDL_Window *pwindow = SDL_CreateWindow("Image Viewer",
                              SDL_WINDOWPOS_CENTERED ,  SDL_WINDOWPOS_CENTERED , 900,
                              600, 0 );
  // this keeps the window open for 3 second
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  Uint8 r,g,b;
  r = 0xFF;
  g = b = 0x00;
  Uint32 color = SDL_MapRGB(psurface->format,r,g,b);

  // creates a white background window
  int x = 50; 
  int y = 50;
  //generated a single red pixel
  SDL_Rect pixel = (SDL_Rect){x,y,1,1};
  SDL_FillRect(psurface, &pixel, color);
  SDL_UpdateWindowSurface(pwindow); 
  SDL_Delay(3000); 


}
