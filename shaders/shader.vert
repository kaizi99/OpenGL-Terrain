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

#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 M_V;
uniform mat4 M_M;
uniform mat4 M_P;

void main()
{
	vec4 v = vec4(vertexPosition_modelspace, 1.0f);
	vec4 clipSpace = M_P * M_V * M_M * v;
	gl_Position = clipSpace;
	//gl_Position = v;
}
