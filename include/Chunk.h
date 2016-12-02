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

#include "Model.h"
#include <glm.hpp>

namespace Terrain {
	class Chunk {
	public:
		Chunk(int x, int y, int size, int resolution);
		Rendering::Model getModel();
		glm::vec3 getWorldPosition();
	private:
		Rendering::Model* model;
		glm::vec2 position;
		int size;
	};
}
