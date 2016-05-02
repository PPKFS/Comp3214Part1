#pragma once
#include <glm/glm.hpp>
#include "Mesh.h"

class Object
{
public:
	Object(Mesh* mesh);
	~Object();
	void Draw();
	inline glm::mat4 GetTransform() { return transform; }
	inline Mesh* GetMesh() { return mesh; }
	void Move(glm::vec3 pos);
	void SetPos(glm::vec3 pos);
	void Scale(float scale);
	void UpdateMatrix();
private:
	Mesh* mesh;
	glm::mat4 transform;
	glm::vec3 pos;
	float scale;
};

