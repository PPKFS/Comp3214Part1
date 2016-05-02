#include "Object.h"
#include "Window.h"
#include "Sphere.h"
#include <glm/gtx/transform.hpp>

extern Window* programWindow;

Object::Object(Mesh* mesh)
{
	this->mesh = mesh;
	this->pos = glm::vec3(0, 0, 0);
	this->scale = 1.f;
	this->transform = glm::mat4(1.f);
}

void Object::Move(glm::vec3 pos)
{
	this->pos += pos;
	UpdateMatrix();
}

void Object::SetPos(glm::vec3 pos)
{
	this->pos = pos;
	UpdateMatrix();
}

void Object::Scale(float scale)
{
	this->scale = scale;
	UpdateMatrix();
}


Object::~Object()
{
}

void Object::UpdateMatrix()
{
	transform = glm::mat4(1.f);
	transform = glm::translate(transform, pos);
	transform = glm::scale(transform, glm::vec3(scale, scale, scale));
}

void Object::Draw()
{
	UpdateMatrix();
	GLuint matrixID = glGetUniformLocation(programWindow->GetProgram(), "model");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &(transform[0][0]));
	mesh->Draw();
}