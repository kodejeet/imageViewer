#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main() {

  const int width = 900;
  const int height = 600;

  printf("Hello World!");
  //this creates the window, only for a flash second 
  SDL_Window *pwindow = SDL_CreateWindow("Image Viewer",
                              SDL_WINDOWPOS_CENTERED ,  SDL_WINDOWPOS_CENTERED , width,
                              height, 0 );
  // this keeps the window open for 3 second
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  Uint8 r,g,b;
  r = 0xFF;
  g = b = 0x00;
  Uint32 color = SDL_MapRGB(psurface->format,r,g,b);

  // creates a white background window
  // int x = 50; 
  // int y = 50;
  //generated a single red pixel
  
  // this loops cover the whole screen of 900/600 red since the pixel runs on a loop
  for(int x = 0; x<width; x++){
    for (int y=0; y<height; y++) {
      SDL_Rect pixel = (SDL_Rect){x,y,1,1};
      SDL_FillRect(psurface, &pixel, color);
    }
  }
  // SDL_Rect pixel = (SDL_Rect){x,y,1,1};
  // SDL_FillRect(psurface, &pixel, color);
  SDL_UpdateWindowSurface(pwindow); 
  SDL_Delay(3000); 


}
