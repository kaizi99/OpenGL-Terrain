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

#include "Entity.h"

Entity::Entity(Shader* shader)
{
	this->shader = shader;
}

void Entity::initialize(std::vector<glm::vec3> vertecies, std::vector<int> indices)
{
	std::vector<glm::vec3> normals;

	for (int i = 0; i < indices.size(); i += 3)
	{
		glm::vec3 normal = computeNormal(vertecies[indices[i]], vertecies[indices[i + 1]], vertecies[indices[i + 2]]);
		normals.push_back(normal);
		normals.push_back(normal);
		normals.push_back(normal);
	}

	vertexCount = indices.size();

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	bindIndicesBuffer(indices);
	storeVectorsInAttributeList(vertecies, 0);
	storeVectorsInAttributeList(normals, 1);

	glBindVertexArray(0);
}

void Entity::initialize(std::vector<glm::vec3> vertecies, std::vector<int> indices, std::vector<glm::vec3> normals)
{
	vertexCount = indices.size();

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	bindIndicesBuffer(indices);
	storeVectorsInAttributeList(vertecies, 0);
	storeVectorsInAttributeList(normals, 1);

	glBindVertexArray(0);
}

void Entity::render(glm::mat4 projection, glm::mat4 view)
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);

	shader->useShader();
	shader->sendMatreciesToShader(projection, view, model);

	glBindVertexArray(vaoID);
	glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	shader->disableShader();
}

void Entity::storeVectorsInAttributeList(std::vector<glm::vec3> data, int attributeList)
{
	GLuint vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * data.size(), data.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(attributeList);
	glVertexAttribPointer(attributeList, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Entity::bindIndicesBuffer(std::vector<int> data)
{
	GLuint indicesBuffer;
	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW);
}

glm::vec3 Entity::computeNormal(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
{
	glm::vec3 V1 = v2 - v1;
	glm::vec3 V2 = v3 - v1;
	glm::vec3 surfaceNormal;

	surfaceNormal.x = (V1.y * V2.z) - (V1.z * V2.y);
	surfaceNormal.y = -((V2.z * V1.x) - (V2.x * V1.z));
	surfaceNormal.z = (V1.x * V2.y) - (V1.y * V2.x);

	return glm::normalize(surfaceNormal);
}