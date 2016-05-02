#pragma once

#include <GL/glew.h>
#include <vector>

#define PI 3.14159265358979323846

class Mesh
{
public:
	Mesh();
	~Mesh();
	void Build();
	virtual void Draw();
protected:
	GLuint vao, vbo, ibo;
	std::vector<GLfloat> vertices, colors, normals;
	std::vector<GLushort> indices;
};

