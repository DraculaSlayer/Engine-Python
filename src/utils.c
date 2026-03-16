#include <utils.h>

Vec2 Vec2Rest(Vec2 a,Vec2 b)
{
	Vec2 r = { .x=a.x-b.x, .y=a.y-b.y };
	return r;
}

void Vec2Zero(Vec2 *a)
{
	a->x = 0.f;
	a->y = 0.f;
}

