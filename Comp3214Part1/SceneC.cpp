#include "SceneC.h"
#include "Window.h"


SceneC::SceneC()
{
	SetWireframe(false);
	SetLight(true);
	SetTexture(false);
	s = MakeObject(SPHERE);
}

void SceneC::Init()
{

}

void SceneC::Draw(double time)
{
	s->Draw();
}

SceneC::~SceneC()
{
	if (s != NULL)
		delete s;
}
