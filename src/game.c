#include <game.h>

/*  Probando funciones nuevas de C
#warning "Cuidado!"
constexpr unsigned char embed[] = {
#embed "assets/test.png" limit(1000) suffix(,0) preffix(0,)
};
const uint32_t len = sizeof(embed);
*/


void ChangSTATE(Engine *app,uint32_t NEWSTATE)
{
	app->init = false;
	app->STATE = NEWSTATE;
	// Not Free Memory, only free entities and textures!
	Void_TexturesAndEntities(&app->man);
}

inline void throw(Engine *app,const char* string)
{
	ChangSTATE(app,EXIT);
	strncpy(app->throw,string,sizeof(app->throw));
}

bool EventElement(Engine *app,Entity *e,const char *event)
{
	if(app->event) return false;
	if(!strcmp(event,"click")){
		float x,y;
		uint32_t mouseSTATE = SDL_GetMouseState(&x,&y);
		SDL_FRect mouse = { .x=x, .y=y, .w=0, .h=0 };
		if(!SDL_HasRectIntersectionFloat(&mouse,&e->dimension)) return false;
		if(mouseSTATE & SDL_BUTTON_LMASK) return true;
	}else return false;
	return false;
}


void main_menu(Engine *app)
{
	if(!app->init){
		app->init = true;
		LoadSprite_EntityManager(&app->man,"assets/START.png","SPRITE_START");
		LoadSprite_EntityManager(&app->man,"assets/CONFIG.png","SPRITE_CONFIG");
		CreateEntity(&app->man,"SPRITE_START","BUTTON_START");
		int widht,height;
		SDL_GetWindowSize(app->app->window,&widht,&height);
		Entity *BUTTON_START = SearchEntity(&app->man,"BUTTON_START");
		BUTTON_START->position.x = widht/2 - BUTTON_START->dimension.w/2;
		BUTTON_START->position.y = height/2 - BUTTON_START->dimension.h/2;

		CreateEntity(&app->man,"SPRITE_CONFIG","BUTTON_CONFIG");
		Entity *BUTTON_CONFIG = SearchEntity(&app->man,"BUTTON_CONFIG");
		BUTTON_CONFIG->position.x = widht - BUTTON_CONFIG->dimension.w;
		BUTTON_CONFIG->position.y = 0;
	}else{
		Entity *BUTTON_START = SearchEntity(&app->man,"BUTTON_START");
		Entity *BUTTON_CONFIG = SearchEntity(&app->man,"BUTTON_CONFIG");
		if(EventElement(app,BUTTON_START,"click")){
			SDL_Log("Click en START!");
		}
		if(EventElement(app,BUTTON_CONFIG,"click")){
			SDL_Log("Click en CONFIG!");
			ChangSTATE(app,QUIT);
		}
	}
}
void new_game(Engine *app)
{
	(void)app;
}
void load_game(Engine *app)
{
	(void)app;
}
void history(Engine *app)
{
	(void)app;
}
void battle(Engine *app)
{
	(void)app;
}
void platform(Engine *app)
{
	(void)app;
}
void quit(Engine *app){ app->app->statusGame = true; }



void startEngine(Engine *e,APP *app)
{
	InitEntityManager(&e->man,app->renderer);
	e->app = app;
	e->init = false;
	e->event = false;
	e->countEvent = 0;
	ChangSTATE(e,MENU_MAIN);
}

void mainEngine(Engine *app)
{
	app->countEvent++;
	if(app->countEvent == 6){
		app->countEvent=0;
		app->event=false;
	}
	switch(app->STATE){
		case MENU_MAIN:
		main_menu(app);
		break;

		case HISTORY:
		history(app);
		break;

		case NEW_GAME:
		new_game(app);
		break;

		case LOAD_GAME:
		load_game(app);
		break;

		case QUIT:
		quit(app);
		break;

		case EXIT:
		SDL_Log("%s",app->throw);
		app->app->statusGame = true;
		break;

		default:
		break;
	}
	app->event=true;
}

void endEngine(Engine *e)
{
	DestroyEntityManager(&e->man);
}



