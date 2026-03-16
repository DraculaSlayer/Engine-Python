#pragma once
#include <SDL3/SDL.h>
#include <timer.h>
#include <physicsSystem.h>
#include <entityManager.h>
#include <utils.h>

#define WIDTH 640
#define HEIGHT 360

typedef struct{
	SDL_Window *window;
	SDL_Renderer *renderer;
	Timer time;
	SDL_Event e;
	Phisics p;
	int width_t;
	int height_t;
	float mouse_x,mouse_y;
	bool statusGame;
	const bool*keys;
	SDL_FRect cam;
	Vec2 camVel;
	float dt;
}APP;



