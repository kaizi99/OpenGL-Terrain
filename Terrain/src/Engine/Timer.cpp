#include "Timer.h"



Timer::Timer()
{
	lastTime = glfwGetTime();
}


Timer::~Timer()
{
}

void Timer::updateTimer()
{
	double currentTime = glfwGetTime();
	frames++;
	if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
		std::cout << frames << " FPS" << std::endl;
		frames = 0;
		lastTime += 1.0;
	}
}