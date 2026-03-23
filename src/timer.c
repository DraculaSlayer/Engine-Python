#include <timer.h>

// first call
void init_timer(Timer *timer)
{
	timer->started = 0;
	timer->start = 0;
	timer->lastTime = 0;
	timer->dtlasttime = 0;
	timer->nbFrame = 0;
	timer->b = SDL_GetTicks();
	timer->countFPS = 60;

	Uint64 start_time = SDL_GetPerformanceCounter();
	Uint64 frequency = SDL_GetPerformanceFrequency();
	timer->lastTime = (double)start_time/(double)frequency;
	timer->dtlasttime = timer->lastTime;
	timer->start = 0;
	timer->started = false;

}
double getTime()
{
	Uint64 start_time = SDL_GetPerformanceCounter();
	Uint64 frequency = SDL_GetPerformanceFrequency();
	return (double)start_time/(double)frequency;
}

// draw fps - second call
void fps(Timer *timer,SDL_Window *window)
{
	double currentTime = getTime();
	timer->nbFrame++;
	if(currentTime - timer->lastTime >= 1.0){
		double ms = 1000.0/(double)(timer->nbFrame);
		//double frames = 1.0f/(ms/1000.0f);
		double frames = (double)timer->nbFrame;
		char title[256];
		sprintf(title,"%s - %.4f ms/Frame - %d fps",timer->title,ms,(uint)frames);
		SDL_SetWindowTitle(window,title);
		timer->nbFrame = 0;
		timer->lastTime += 1.0;
		timer->frames = frames;
	}
}

// thrid call - then glClearColor and glClear
double getDeltaTime(Timer *timer)
{
	double currentTime = getTime();
	double dt = currentTime - timer->dtlasttime;
	timer->dtlasttime = currentTime;
	return dt;
}
double getTicks(Timer *timer)
{
	Uint64 _time = 0;
	if(timer->started){
		_time = SDL_GetTicks() - timer->start;
	}
	return _time;
}
// first call then init_timer
void limit_fps_start(Timer *timer)
{
	timer->started = true;
	timer->start = SDL_GetTicks();
}
// four call - then SDL_GL_SwapWindow

void limit_fps_end(Timer *timer)
{
	Uint64 limit = timer->countFPS;
	Uint64 frame = getTicks(timer);
	if(frame < (1000/limit)){
		SDL_Delay((1000/limit)-frame);
	}
}



