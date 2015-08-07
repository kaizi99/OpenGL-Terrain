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
#include <iostream>
#include <vector>
#include <GL\glew.h>
#define GLM_FORCE_PURE
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <noise\noise.h>
#include "Shader\StandartShader.h"
#include "Engine\Entity.h"

class Chunk : public Entity
{
public:
	Chunk(int x, int y, unsigned int sizeOfChunk, unsigned int quadInOne) : Entity(new Shader("Shader/shader.vert", "Shader/shader.frag"))
	{
		this->x = x;
		this->y = y;
		this->size = sizeOfChunk;
		noise::module::Perlin noise;
		noise.SetFrequency(.2);
		//Terrain vertecies and indecies generation

		//x * 16 - 1  y * 16 - 1

		for (double i = 0; i <= sizeOfChunk; i += (1 / (double)quadInOne))
		{
			for (double j = 0; j <= sizeOfChunk; j += (1 / (double)quadInOne))
			{
				glm::vec3 vertex(i, 0, j);
				vertex.y = noise.GetValue(j + .5 + x * (sizeOfChunk - 1), .5, i + .5 + y * (sizeOfChunk - 1));

				vertecies.push_back(vertex);
			}
		}

		for (double i = 1; i < sizeOfChunk * quadInOne; i++)
		{
			for (double j = 1; j < sizeOfChunk * quadInOne; j++)
			{
				int i1 = (sizeOfChunk * quadInOne + 1) * (j - 1) + i;
				int i2 = (sizeOfChunk * quadInOne + 1) * j + i;
				int i3 = i2 + 1;
				int i4 = i1 + 1;
				int i5 = i1;
				int i6 = i3;

				indices.push_back(i1 - 1);
				indices.push_back(i2 - 1);
				indices.push_back(i3 - 1);
				indices.push_back(i4 - 1);
				indices.push_back(i5 - 1);
				indices.push_back(i6 - 1);
			}
		}
		Entity::position = glm::vec3(x * (sizeOfChunk - 1), 0, y * (sizeOfChunk - 1));

		//model = glm::mat4(1.0f);
		//glm::vec3 translation(x * (size - 1), 0, y * (size - 1));
		//model = glm::translate(model, translation);

		Entity::initialize(vertecies, indices);
	}
	glm::mat4 getModelMatrix();
	~Chunk();
private:
	int x, y;
	unsigned int size;
	std::vector<glm::vec3> vertecies, normals;
	std::vector<int> indices;
	noise::module::Perlin noise;
};

