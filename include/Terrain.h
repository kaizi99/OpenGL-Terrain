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

#include "OpenGL.h"

#include "Chunk.h"

#include <glm.hpp>

#include <vector>
namespace Terrain {
	class Terrain
	{
	public:
		Terrain(int terrainSize, int chunkSize, int resolution);
		void GenerateNewChunk(glm::vec2 position);
		std::vector<Chunk> getChunks();
	private:
		std::vector<Chunk> chunks;
		std::vector<glm::vec2> generatedChunks;
		int chunkSize;
		int resolution;
	};
}
