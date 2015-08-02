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