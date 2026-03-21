#pragma once
#include <vector.h>
#include <utils.h>
#include <entityManager.h>

typedef struct{
	int WIDTH_t,HEIGHT_t;
	SDL_Window *window;
}Physics;

void Init_physicsSystem(Physics *p,EntityManager *man,SDL_Window *window);
void physicsSystem(Physics *p,EntityManager *man,float dt);




