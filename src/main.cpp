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

#include "Renderer.h"
#include "Timer.h"

#include "OpenGL.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm.hpp>

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int width = 1280;
const int height = 720;

GLFWwindow* init();

int main()
{
	/********************
	******SCENE_INIT*****
	********************/

	GLFWwindow* window = init();
	Rendering::Renderer renderer(width, height);

	Rendering::Shader shader("shaders/shader.vert", "shaders/shader.frag");
	Terrain::Terrain t(4, 8, 4);

	/********************
	******MAIN_LOOP******
	*********************/

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//renderer.RenderModel(m, shader, glm::vec3(0.0f, 0.0f, 0.0f));
		renderer.RenderTerrain(t, shader, glm::vec3(0.0f, 0.0f, 0.0f));

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
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);

	glfwSwapInterval(1);
	if (!window)
	{
		std::cout << "Window creation failed!" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

#ifndef __APPLE__
	gl3wInit();
#endif

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return window;
}
