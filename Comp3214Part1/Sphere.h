#pragma once
#include "Mesh.h"



class Sphere : public Mesh
{
public:
	Sphere(int rings, int sectors, float radius, bool showNormals=false);
	~Sphere();
	void Draw();
private:
	std::vector<GLfloat> normalDisplay, normalColors;
	GLuint normalDisplayVAO, normalDisplayVBO;
};

