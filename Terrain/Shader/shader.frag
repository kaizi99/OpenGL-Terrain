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

#version 420 core

out vec3 color;
in vec3 normal;

void main()
{
	//vec3 light = cos(cross(normal, vec3(1, -3, 4)));
	//color = vec3(0, 1, 0) * light;
	color = vec3(1, 0, 0);
}