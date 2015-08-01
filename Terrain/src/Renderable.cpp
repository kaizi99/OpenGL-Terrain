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

#include "Renderable.h"

Renderable::Renderable(glm::mat4 projection, glm::mat4 view, Shader* shader)
{
	this->projection = projection;
	this->view = view;
	this->shader = shader;
	model = glm::mat4(1.0f);
}

void Renderable::initialize(std::vector<glm::vec3> vertecies, std::vector<int> indices, std::vector<glm::vec3> normals)
{
	vertexCount = indices.size();

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	bindIndicesBuffer(indices);
	storeVectorsInAttributeList(vertecies, 0);
	//storeVectorsInAttributeList(normals, 1);

	glBindVertexArray(0);
}

void Renderable::updateView(glm::mat4 view)
{
	this->view = view;
}

void Renderable::setCustomModelMatrix(glm::mat4 model)
{
	this->model = model;
}

void Renderable::render()
{
	shader->useShader();
	shader->sendMatreciesToShader(projection, view, model);

	glBindVertexArray(vaoID);
	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->disableShader();
}

void Renderable::storeVectorsInAttributeList(std::vector<glm::vec3> data, int attributeList)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * data.size(), data.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(attributeList);
	glVertexAttribPointer(attributeList, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Renderable::bindIndicesBuffer(std::vector<int> data)
{
	GLuint indicesBuffer;
	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW);
}