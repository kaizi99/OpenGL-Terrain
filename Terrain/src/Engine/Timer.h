#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

class Timer
{
public:
	Timer();
	~Timer();
	void updateTimer();
private:
	int frames;
	double lastTime;
};

