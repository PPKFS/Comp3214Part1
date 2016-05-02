#include "Shader.h"
#include <iostream>
#include <fstream>
#include <string>


GLuint LoadShader(std::string filename, GLenum type)
{
	std::ifstream shaderIn(filename);
	std::string src = "";
	std::string currentLine = "";
	while (std::getline(shaderIn, currentLine))
	{
		src += currentLine;
		src += "\n";
	}
	GLuint shader = glCreateShader(type);
	const char* str = src.c_str();
	glShaderSource(shader, 1, &str, NULL);
	glCompileShader(shader);
	if (!shader)
	{
		std::cerr << filename << " shader did not compile" << std::endl;
		return 0;
	}
	return shader;
}

GLuint CreateShaderProgram()
{
	GLuint vert = LoadShader("shaders/shader.vert", GL_VERTEX_SHADER), frag = LoadShader("shaders/shader.frag", GL_FRAGMENT_SHADER);
	if (!vert || !frag)
	{
		return 0;
	}
	GLuint program = glCreateProgram();
	if (!program)
	{
		std::cerr << "could not create program" << std::endl;
		return 0;
	}
	glAttachShader(program, vert);
	glAttachShader(program, frag);
	glBindAttribLocation(program, 0, "position");
	glLinkProgram(program);
	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked)
	{
		std::cerr << "could not link shader" << std::endl;
		return 0;
	}

	glUseProgram(program);
	return program;
}