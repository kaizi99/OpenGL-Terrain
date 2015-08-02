#pragma once
#include <vector>
#include "Entity.h"

class Renderer
{
public:
	Renderer() : Renderer(640, 480) {}
	Renderer(int width, int height);
	~Renderer();
	void push_back_entities(Entity* toRender);
	void renderScene(glm::mat4 view, glm::mat4 projection);
	void renderScene();
private:
	std::vector<Entity*> thingsToRender;
	glm::mat4 view, projection;
};

