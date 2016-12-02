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


namespace Terrain {
	Terrain::Terrain(int terrainSize, int chunkSize, int resolution)
	{
		this->chunkSize = chunkSize;
		this->resolution = resolution;

		for(int i = 0; i <= terrainSize; i++)
		{
			for(int j = 0; j <= terrainSize; j++)
			{
				GenerateNewChunk(glm::vec2(i, j));
			}
		}
	}

	void Terrain::GenerateNewChunk(glm::vec2 position)
	{
		for(glm::vec2 chunk : generatedChunks)
			if(chunk == position)
				return;

		Chunk chunk(position.x, position.y, chunkSize, resolution);
		chunks.push_back(chunk);
		generatedChunks.push_back(position);
	}

	std::vector<Chunk> Terrain::getChunks() {
		return chunks;
	}
}
