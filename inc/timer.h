#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <SDL3/SDL.h>

typedef unsigned int uint;
typedef struct{
	bool started;
	uint start;
	double lastTime,dtlasttime;
	int nbFrame;
	int b;
	int countFPS;
	const char *title;
	double frames;
}Timer;


void init_timer(Timer *t);
void limit_fps_start(Timer *t);
void fps(Timer *timer,SDL_Window *window);
double getDeltaTime(Timer *timer);
void limit_fps_end(Timer *timer);
