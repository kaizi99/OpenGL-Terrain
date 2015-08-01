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

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 M_V;
uniform mat4 M_M;
uniform mat4 M_P;

out vec4 clipSpace;
out vec3 normal;

void main()
{
	vec4 v = vec4(vertexPosition_modelspace, 1);
	clipSpace = M_P * M_V * M_M * v;
	normal = (M_V * M_M * vec4(vertexPosition_modelspace, 0)).xyz;
	gl_Position = clipSpace;
}