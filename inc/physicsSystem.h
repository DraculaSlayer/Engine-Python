#pragma once
#include <vector.h>
#include <utils.h>
#include <entityManager.h>

typedef struct{
	int WIDTH_t,HEIGHT_t;
	SDL_Window *window;
}Phisics;

void Init_physicsSystem(Phisics *p,EntityManager *man,SDL_Window *window);
void physicsSystem(Phisics *p,EntityManager *man,float dt);




