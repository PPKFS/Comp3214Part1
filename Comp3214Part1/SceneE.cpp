#include "SceneE.h"



SceneE::SceneE()
{
	SetWireframe(false);
	SetLight(false);
	SetTexture(true);
}

void SceneE::Init()
{
	plane = MakeObject(PLANE);
	plane->Move(glm::vec3(0, 2, 0));
	plane->Scale(2.f);
}

void SceneE::Draw(double time)
{
	plane->Draw();
}

SceneE::~SceneE()
{
	if (plane != NULL)
		delete plane;
}
