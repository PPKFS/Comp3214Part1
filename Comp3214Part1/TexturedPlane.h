#pragma once
#include "Mesh.h"

class Texture
{
public:
	int width, height, bpp;
	GLuint textureID;
	unsigned char* rgb;
};

class TexturedPlane : public Mesh
{
public:
	TexturedPlane();
	~TexturedPlane();
	void Build();
private:
	std::vector<GLfloat> uvs;
	Texture tex;
	GLuint uvVBO;
};

