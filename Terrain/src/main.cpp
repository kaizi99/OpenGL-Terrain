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
#include <fstream>
#include <sstream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <minmax.h>
#include <noise\noise.h>
#include "Quad.h"
#include "Terrain.h"

using namespace std;
using namespace noise;

const int width = 640;
const int height = 480;

void initScene();
void render();

int main()
{
	module::Perlin noise;
	noise.SetFrequency(0.2);

	if (!glfwInit())
	{
		cout << "GLFW konnte nicht initialisiert werden!" << endl;
		std::system("PAUSE");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	GLFWwindow* window;
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::system("PAUSE");
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClearColor(0.4f, 0.6f, 0.9f, 1.0f);

	/********************
	******SCENE_INIT*****
	********************/
	glm::mat4 projection = glm::perspectiveFov(45.0f,(float) width,(float) height, 0.01f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(4.0f, 3.0f, 3.0f), glm::vec3(8.0f, 0.0f, 8.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	Terrain* t = new Terrain(projection, view, 4, 16);

	glfwSwapInterval(1);

	/********************
	******MAIN_LOOP******
	********************/

	double lastTime = glfwGetTime();
	int nbFrames = 0;

	while (!glfwWindowShouldClose(window))
	{
		double currentTime = glfwGetTime();
		nbFrames++;
		if (currentTime - lastTime >= 1.0){ // If last prinf() was more than 1 sec ago
			// printf and reset timer
			std::cout << nbFrames << " FPS" << std::endl;
			nbFrames = 0;
			lastTime += 1.0;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		t->render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}