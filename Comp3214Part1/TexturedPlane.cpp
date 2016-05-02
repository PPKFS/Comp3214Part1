#include "TexturedPlane.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture CreateTexture()
{
	Texture texture;
	int width, height, bpp;
	unsigned char* rgb = stbi_load("images/tex.png", &width, &height, &bpp, 3);
	texture.width = width;
	texture.height = height;
	texture.bpp = bpp;
	texture.rgb = rgb;

	GLuint textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	texture.textureID = textureID;
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture.rgb);
	return texture;
}

TexturedPlane::TexturedPlane()
{
	tex = CreateTexture();

	vertices.push_back(-1.f);
	vertices.push_back(-1.f);
	vertices.push_back(0.f);

	uvs.push_back(0.f);
	uvs.push_back(1.f);

	vertices.push_back(1.f);
	vertices.push_back(-1.f);
	vertices.push_back(0.f);

	uvs.push_back(1.f);
	uvs.push_back(1.f);

	vertices.push_back(-1.f);
	vertices.push_back(1.f);
	vertices.push_back(0.f);

	uvs.push_back(0.f);
	uvs.push_back(0.f);

	vertices.push_back(1.f);
	vertices.push_back(1.f);
	vertices.push_back(0.f);

	uvs.push_back(1.f);
	uvs.push_back(0.f);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);

	indices.push_back(0);
	indices.push_back(3);
	indices.push_back(2);

	for (int i = 0; i < vertices.size(); ++i)
	{
		colors.push_back(1.f);
		if (i % 3 == 0)
		{
			//normals face into the z axis
			normals.push_back(0.f);
			normals.push_back(0.f);
			normals.push_back(-1.f);
		}
	}
}

void TexturedPlane::Build()
{
	Mesh::Build();
	glBindVertexArray(vao);
	glGenBuffers(1, &uvVBO);

	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*uvs.size(), &uvs[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

TexturedPlane::~TexturedPlane()
{
	glDeleteTextures(1, &tex.textureID);
	stbi_image_free(tex.rgb);
}
