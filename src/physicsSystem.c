#include <physicsSystem.h>

void Init_physicsSystem(Phisics *p,EntityManager *man,SDL_Window *window)
{
	SDL_GetWindowSize(window,&p->WIDTH_t,&p->HEIGHT_t);
	p->window = window;
	Entity *e = Vector_getValue(man->entities,0);
	for(uint32_t i=0; i<man->entities->size; i++){
		e->aceleration.x = 0.f;
		e->aceleration.y = 0.f;
		Vec2Zero(&e->velocity);
		e++;
	}
}

void physicsSystem(Phisics *p,EntityManager *man,float dt)
{
	(void)p;
	const float speed = 400.f;
	int width,height;
	SDL_GetWindowSize(p->window,&width,&height);
	Entity *e = Vector_getValue(man->entities,0);
	for(uint32_t i=0; i<man->entities->size; i++){
		if(e->position.y < width)
			e->velocity.y += e->aceleration.y;
		e->velocity.x += e->aceleration.x;
		e->position.x += speed * e->velocity.x * dt;
		e->position.y += speed * e->velocity.y * dt;
		e->dimension.x = e->position.x;
		e->dimension.y = e->position.y;
		if((e->position.x + e->dimension.w) >= width) e->position.x = width - e->dimension.w;
		if(e->position.x <= 0) e->position.x = 0;
		if((e->position.y + e->dimension.h) >= height) e->position.y = height - e->dimension.h;
		if(e->position.y <= 0) e->position.y = 0;
		e++;
	}
}

