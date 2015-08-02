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

#include "Terrain.h"

Terrain::Terrain(int terrainSize, int chunkSize, Renderer* renderer)
{
	this->renderer = renderer;
	this->chunkSize = chunkSize;
	for(int i = 0; i <= terrainSize; i++)
	{
		for(int j = 0; j <= terrainSize; j++)
		{
			Chunk* c = new Chunk(i, j, chunkSize, 8);
			chunks.push_back(c);
			generatedChunks.push_back(glm::vec2(i, j));
			renderer->push_back_entities(c);
		}
	}	
}

void Terrain::generateNewChunk(glm::vec2 position)
{
	for each(glm::vec2 chunk in generatedChunks)
		if(chunk == position)
			return;
			
	Chunk* c = new Chunk(position.x, position.y, chunkSize, 8);
	chunks.push_back(c);
	generatedChunks.push_back(position);
	renderer->push_back_entities(c);
}