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
#include "raylib.h"

#define CIRCLE_WIDTH 20
#define PADDING 20
#define SCREEN_WIDTH PADDING + CIRCLE_WIDTH * 3 
#define SCREEN_HEIGHT PADDING + CIRCLE_WIDTH * 6


// pos calculates position of each circle based on loop interation.
// a = width of circle; i = iterator used as a multiplier of the width; p = the margin for spacing
int pos(int a, int i, int p) { return (a * i) + p; }

Color get_color( int timeblock, int i, int y) {
        if (timeblock & (int)pow(2,y)) {
          return BLACK;
        } else {
          return GRAY;
        }
}
int main(void) {

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
        DrawCircle((SCREEN_WIDTH - pos(20, i, 20)),(SCREEN_HEIGHT - pos(20, y, 20)), 8, circle_color);
      }
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
