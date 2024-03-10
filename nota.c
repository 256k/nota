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


#define SCREEN_WIDTH 20 + 20 * 3 
#define SCREEN_HEIGHT 20 + 20 * 6 
int pos(int a, int i, int p) { return (a * i) + p; }

Color get_color( int timeblock, int i, int y) {
        if (timeblock & (int)pow(2,y)) {
          return BLACK;
        } else {
          return GRAY;
        }
}
int main(void) {
  const int screenWidth = SCREEN_WIDTH;
  const int screenHeight = SCREEN_HEIGHT;

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  int x = 20;
  int y = 20;
  Color circle_color;
  
  InitWindow(screenWidth, screenHeight, "Nota");

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
