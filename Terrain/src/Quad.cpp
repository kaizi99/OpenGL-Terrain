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

#include "Quad.h"

Quad::Quad(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4, glm::mat4 projection, glm::mat4 view, StandartShader* sh)
{
	this->pos1 = pos1;
	this->pos2 = pos2;
	this->pos3 = pos3;
	this->pos4 = pos4;

	shader = sh;

	this->view = view;
	this->projection = projection;

	this->model = glm::mat4(1.0f);

	glm::vec3 positions[] = { pos1, pos2, pos3, pos1, pos3, pos4 };

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), &positions, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Quad::Quad(glm::vec3 pos1, glm::vec3 pos2, glm::vec3 pos3, glm::vec3 pos4, glm::mat4 projection, glm::mat4 view)
{
	this->pos1 = pos1;
	this->pos2 = pos2;
	this->pos3 = pos3;
	this->pos4 = pos4;

	shader = new StandartShader();

	this->view = view;
	this->projection = projection;

	this->model = glm::mat4(1.0f);

	glm::vec3 positions[] = {pos1, pos2, pos3, pos1, pos3, pos4};

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), &positions, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Quad::~Quad()
{
}

void Quad::render()
{
	shader->useShader();

	shader->sendMatreciesToShader(projection, view, model);

	glBindVertexArray(vaoID);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);

	shader->disableShader();
}

void Quad::updateView(glm::mat4 viewMatrix)
{
	this->view = viewMatrix;
}