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

Renderer::~Renderer()
{

}

Renderer::Renderer(int width, int height)
{
	projection = glm::perspectiveFov(45.0f, (float)width, (float)height, 0.01f, 100.0f);
	view = glm::lookAt(glm::vec3(4.0f, 3.0f, 3.0f), glm::vec3(8.0f, 0.0f, 8.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void Renderer::renderScene()
{
	for each(Entity* e in thingsToRender)
	{
		e->render(projection, view);
	}
}

void Renderer::renderScene(glm::mat4 view, glm::mat4 projection)
{
	for each(Entity* e in thingsToRender)
	{
		e->render(projection, view);
	}
}

void Renderer::push_back_entities(Entity* entity)
{
	thingsToRender.push_back(entity);
}