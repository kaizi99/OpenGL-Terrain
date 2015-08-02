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

#pragma once
#include <vector>
#include <gl\glew.h>
#include <glm\glm.hpp>
#include <glm\geometric.hpp>
#include "Shader\Shader.h"

class Renderable
{
public:
	Renderable(glm::mat4 projection, glm::mat4 view, Shader* shader);
	void setCustomModelMatrix(glm::mat4 model);
	void initialize(std::vector<glm::vec3> vertecies, std::vector<int> indices, std::vector<glm::vec3> normals);
	void initialize(std::vector<glm::vec3> vertecies, std::vector<int> indices);
	void updateView(glm::mat4 view);
	void render();
protected:
	int vertexCount;
	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	Shader* shader;
	GLuint vaoID;
	void storeVectorsInAttributeList(std::vector<glm::vec3> data, int attributeList);
	void bindIndicesBuffer(std::vector<int> data);
	glm::vec3 computeNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);
};