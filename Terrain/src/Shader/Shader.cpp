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

#include "Shader.h"
#include <string>
#include <fstream>
#include <vector>
#include <minmax.h>

Shader::Shader(const char* vertex_file_path, const char* fragment_file_path)
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if (VertexShaderStream.is_open())
	{
		std::string Line = "";
		while (getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if (FragmentShaderStream.is_open()){
		std::string Line = "";
		while (getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Compile Fragment Shader
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	// Link the program
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	m_programID = ProgramID;

	location_mv = glGetUniformLocation(Shader::m_programID, "M_V");
	location_mm = glGetUniformLocation(Shader::m_programID, "M_M");
	location_mp = glGetUniformLocation(Shader::m_programID, "M_P");
}

Shader::~Shader()
{
	glDeleteProgram(m_programID);
}

void Shader::useShader()
{
	glUseProgram(m_programID);
}

void Shader::disableShader()
{
	glUseProgram(0);
}

void Shader::sendMatreciesToShader(glm::mat4 M_P, glm::mat4 M_V, glm::mat4 M_M)
{
	glUniformMatrix4fv(location_mm, 1, GL_FALSE, &M_M[0][0]);
	glUniformMatrix4fv(location_mv, 1, GL_FALSE, &M_V[0][0]);
	glUniformMatrix4fv(location_mp, 1, GL_FALSE, &M_P[0][0]);
}