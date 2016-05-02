#include "SceneB.h"


SceneB::SceneB()
{
	SetWireframe(true);
	SetLight(false);
	SetTexture(false);
	s = MakeObject(SPHERE, true);
}


SceneB::~SceneB()
{
	delete s;
}

void SceneB::Draw(double time)
{
	s->Draw();
}
