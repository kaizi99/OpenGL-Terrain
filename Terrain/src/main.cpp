//Copyright 2015 Kai-Uwe Zimdars
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//http ://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

#include <iostream>
#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Terrain.h"
#include "Engine\Renderer.h"
#include "Engine\Timer.h"

using namespace std;
using namespace noise;

const int width = 640;
const int height = 480;

GLFWwindow* init();

int main()
{
	/********************
	******SCENE_INIT*****
	********************/

	GLFWwindow* window = init();
	Renderer r(width, height);
	Terrain* t = new Terrain(2, 16, &r);
	Timer timer = Timer();
	timer.writeFPS = true;

	/********************
	******MAIN_LOOP******
	********************/

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		timer.updateTimer();
		r.renderScene();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}

GLFWwindow* init()
{
	if (!glfwInit())
	{
		cout << "GLFW konnte nicht initialisiert werden!" << endl;
		std::system("PAUSE");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	GLFWwindow* window;
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

	glfwSwapInterval(1);
	if (!window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClearColor(0.4f, 0.6f, 0.9f, 1.0f);

	return window;
}