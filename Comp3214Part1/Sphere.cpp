#include "Sphere.h"
#include <GL/glew.h>
#include <iostream>


Sphere::Sphere(int rings, int sectors, float radius, bool showNormals)
{
	const double invSectors = 1. / (float)(sectors - 1);
	const double invRings = 1. / (float)(rings - 1);
	for (int i = 0; i < rings; ++i)
	{
		for (int j = 0; j < sectors; ++j)
		{
			float x = (float)(cos(2 * PI * j * invSectors) * sin(PI * i * invRings)),
				y = (float)(sin(-(PI / 2.f) + PI * i * invRings)),
				z = (float)(sin(2 * PI * j * invSectors) * sin(PI * i * invRings));
			vertices.push_back(x * radius);
			vertices.push_back(y * radius);
			vertices.push_back(z * radius);

			normals.push_back(x);
			normals.push_back(y);
			normals.push_back(z);
			
			for (int c = 0; c < 6; ++c)
				colors.push_back(1.f);//*/(rand() % 100)/100.f);

			int currRow = i * sectors;
			int nextRow = currRow + sectors;
			int nextJ = (j + 1) % sectors;
			if (i < rings - 1)
			{
				indices.push_back(currRow + j);
				indices.push_back(nextRow + j);
				indices.push_back(nextRow + nextJ);
				indices.push_back(currRow + j);
				indices.push_back(nextRow + nextJ);
				indices.push_back(currRow + nextJ);
			}

			if (showNormals)
			{
				normalDisplay.push_back(x * radius);
				normalDisplay.push_back(y * radius);
				normalDisplay.push_back(z * radius);

				normalDisplay.push_back(x * radius * 1.2f);
				normalDisplay.push_back(y * radius * 1.2f);
				normalDisplay.push_back(z * radius * 1.2f);

				for (int c = 0; c < 2; ++c)
				{
					normalColors.push_back(1.f);
					normalColors.push_back(0.f);
					normalColors.push_back(0.f);
				}
			}
		}
	}

	if (showNormals)
	{
		glGenVertexArrays(1, &normalDisplayVAO);
		glBindVertexArray(normalDisplayVAO);

		glGenBuffers(1, &normalDisplayVBO);

		glBindBuffer(GL_ARRAY_BUFFER, normalDisplayVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(normalDisplay.size() + normalColors.size() + 1), NULL, GL_STATIC_DRAW);

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GLfloat)*normalDisplay.size(), &normalDisplay[0]);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*normalDisplay.size(), sizeof(GLfloat)*normalColors.size(), &normalColors[0]);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(GLfloat)*normalDisplay.size()));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
}

void Sphere::Draw()
{
	Mesh::Draw();
	if (normalDisplay.size() > 0)
	{
		glBindVertexArray(normalDisplayVAO);
		glDrawArrays(GL_LINES, 0, (GLsizei)normalDisplay.size());
		glBindVertexArray(0);
	}
}

Sphere::~Sphere()
{
	if (normalDisplayVAO != NULL)
		glDeleteVertexArrays(1, &normalDisplayVAO);
	if (normalDisplayVBO != NULL)
		glDeleteBuffers(1, &normalDisplayVBO);
}
