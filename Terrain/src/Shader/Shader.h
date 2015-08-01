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
#include <GL\glew.h>
#include <glm\glm.hpp>

class Shader
{
public:
	Shader(const char* vertex_file_path, const char* fragment_file_path);
	virtual ~Shader();
	void useShader();
	void disableShader();
	void sendMatreciesToShader(glm::mat4 M_P, glm::mat4 M_V, glm::mat4 M_M);
protected:
	GLuint m_programID;
	GLuint location_mp;
	GLuint location_mv;
	GLuint location_mm;
};

