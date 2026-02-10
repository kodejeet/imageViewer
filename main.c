#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main() {

  FILE *in = stdin;
  char *pthroway = calloc(1000, sizeof(char));

  // free(pdimensions);

  // reads first line (specifier - p3 ascii or p6 binary/raw)
  fgets(pthroway, 1000, in);
  // reads second line comment
  fgets(pthroway, 1000, in);
  // fgets(pthroway, 1000, in); // P6

  // do {
  //   fgets(pthroway, 1000, in);
  // }
  // while (pthroway[0] == '#');

  //reads third line - dimensions : width/height
  char *pdimensions = calloc(1000, sizeof(char));
  fgets(pdimensions, 1000, in); 
  // reads fourth line comment (max color value - ignore it)
  fgets(pthroway, 1000, in);
  free(pthroway);

  // int *width;
  // int *height;

  int width = -1;
  int height = -1;

  sscanf(pdimensions, "%d %d\n", &width, &height);
  free(pdimensions);
  // free(pthroway);
  
  printf("width=%d, height=%d\n", width, height);

  // int width = *pwidth;
  // int height = *pheight;

  printf("Hello World!");
  //this creates the window, only for a flash second 
  SDL_Window *pwindow = SDL_CreateWindow("Image Viewer",
                              SDL_WINDOWPOS_CENTERED ,  SDL_WINDOWPOS_CENTERED , width,
                              height, 0 );
  // this keeps the window open for 3 second
  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  // Uint8 r,g,b;
  // r = 0xFF;
  // g = b = 0x00;
  // Uint32 color = SDL_MapRGB(psurface->format,r,g,b);

  // creates a white background window
  // int x = 50; 
  // int y = 50;
  //generated a single red pixel
  
  // this loops cover the whole screen of 900/600 red since the pixel runs on a loop
  SDL_Rect pixel = (SDL_Rect){0,0,1,1};
  Uint32 color = 0;
  for(int y = 0; y<height; y++){
    for (int x=0; x<width; x++) {
      Uint8 r,g,b;
      r = (char) getchar();
      g = (char) getchar();
      b = (char) getchar();
      // g = b = 0x00;
      color = SDL_MapRGB(psurface->format,r,g,b);
      pixel.x=x;
      pixel.y=y;
      SDL_FillRect(psurface, &pixel, color);
    }
  }
  // SDL_Rect pixel = (SDL_Rect){x,y,1,1};
  // SDL_FillRect(psurface, &pixel, color);
  SDL_UpdateWindowSurface(pwindow); 
  // SDL_Delay(2000); 
  
  int app_running = 1;
  while (app_running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) { 
        if (event.type == SDL_QUIT) {
          app_running = 0;
        }       
      }
      SDL_Delay(100); 
  }
}
