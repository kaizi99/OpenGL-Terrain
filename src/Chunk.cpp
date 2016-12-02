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

#include "Chunk.h"

#include <FastNoise.h>
#include <vector>
#include <iostream>

namespace Terrain {
  Chunk::Chunk(int x, int y, int size, int resolution) {
    this->size = size;

    std::cout << "Chunk generated at x=" << x << " y=" << y << std::endl;

    FastNoise noise;
    noise.SetNoiseType(FastNoise::SimplexFractal);
    noise.SetFrequency(.06);

    std::vector<glm::vec3> vertecies;
    std::vector<int> indices;

    for (double i = 0; i <= size; i += (1 / (double)resolution))
		{
			for (double j = 0; j <= size; j += (1 / (double)resolution))
			{
				//vertex.y = noise.GetValue(j + .5 + x * (sizeOfChunk - 1), .5,
				//	i + .5 + y * (sizeOfChunk - 1));
				vertecies.push_back(glm::vec3(i, noise.GetNoise(i + (x * size),
          j + (y * size)) * 5, j));
			}
		}

    for (double i = 1; i <= size * resolution; i++)
		{
			for (double j = 1; j <= size * resolution; j++)
			{
				int i1 = (size * resolution + 1) * (j - 1) + i;
				int i2 = (size * resolution + 1) * j + i;
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

    model = new Rendering::Model(vertecies, indices);
    position = glm::vec2(x, y);
  }

  Rendering::Model Chunk::getModel() {
    return *model;
  }

  glm::vec3 Chunk::getWorldPosition() {
    return glm::vec3(position.x * size, 0.0f, position.y * size);
  }

}
