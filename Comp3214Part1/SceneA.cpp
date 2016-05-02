#include "SceneA.h"
#include <glm/glm.hpp>
#include "Window.h"
extern Window* programWindow;

SceneA::SceneA()
{
	SetWireframe(true);
	SetLight(false);
	SetTexture(false);
	s = MakeObject(SPHERE);
}


SceneA::~SceneA()
{
	delete s;
}

void SceneA::Draw(double time)
{
	s->Draw();
}