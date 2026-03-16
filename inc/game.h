#pragma once
#include <SDL3/SDL.h>
#include <entityManager.h>
#include <init.h>

typedef struct{
	EntityManager man;
	APP *app;
	bool init,event;
	uint32_t countEvent;
	uint32_t STATE;
	char throw[255];
}Engine;

enum ENGINESTATE{
	MENU_MAIN,
	NEW_GAME,
	LOAD_GAME,
	HISTORY,
	BATTLE,
	PLATFORM,
	QUIT,
	EXIT,
	COUNT
};

void startEngine(Engine*,APP*);
void mainEngine(Engine*);
void endEngine(Engine*);

