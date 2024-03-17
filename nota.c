/*
 * Nota
 * a binary clock build with C and raylib
 * by 256k
 *
 *
 *
 *
 */
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "raylib.h"



// pos calculates position of each circle based on loop interation.
// a = width of circle; i = iterator used as a multiplier of the width; p = the margin for spacing
int pos(int a, int i, int p) { 
  return (a * i) + p; 
}

Color get_color( int timeblock, int i, int y) {
  
        if (timeblock & (int)pow(2,y)) {
          return BLACK;
        } else {
          return GRAY;
        }
}

int main(int argc, char* argv[]) {


  int CIRCLE_RADIUS;

  if (argc > 1) {
    CIRCLE_RADIUS = atoi(argv[1]);
  } else { 
    CIRCLE_RADIUS = 8;
  }

  int CIRCLE_WIDTH = ((CIRCLE_RADIUS * 2) + (CIRCLE_RADIUS / 2));
  int PADDING = CIRCLE_WIDTH;
  int SCREEN_WIDTH = (PADDING + CIRCLE_WIDTH * 3 );
  int SCREEN_HEIGHT  = (PADDING + CIRCLE_WIDTH * 6);

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  
  Color circle_color;
  
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Nota");

  SetTargetFPS(2); 

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    for (int i = 0; i < 3; i++) {
      for (int y = 0; y < 6; y++) {
        switch (i) {
	case 0:
	  circle_color = get_color(tm.tm_sec, i, y);
	  break;
	case 1:
	  circle_color = get_color(tm.tm_min, i, y);
	  break;
	case 2:
	  circle_color = get_color(tm.tm_hour, i, y);
	}
        DrawCircle((SCREEN_WIDTH - pos(CIRCLE_WIDTH, i, PADDING)),(SCREEN_HEIGHT - pos(CIRCLE_WIDTH, y, PADDING)), CIRCLE_RADIUS, circle_color);
      }
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
