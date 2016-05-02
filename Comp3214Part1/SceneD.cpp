#include "SceneD.h"

#define RADIUS 2.5f
#define NUM_STUFF 5
SceneD::SceneD()
{
	SetWireframe(true);
	SetLight(false);
	SetTexture(false);
	for (int i = 0; i < NUM_STUFF; ++i)
	{
		shapes.push_back(MakeObject(i % 2 ? SPHERE : CONE));
		shapes[i]->Scale(0.3f);
		shapes[i]->Move(glm::vec3(RADIUS*cos(2.f*i*PI / NUM_STUFF), RADIUS * sin(2.f*i*PI / NUM_STUFF), 0));
		times.push_back((float)(2.f*i*PI / RADIUS));
	}
}

void SceneD::Init()
{

}

void SceneD::Draw(double time)
{
	for (int i = 0; i < NUM_STUFF; ++i)
	{
		times[i] += (float)time;
		if (times[i] > 2 * PI)
			times[i] -= (float)(2 * PI);

		Object* o = shapes[i];
		glm::vec3 moved = glm::vec3(sin(times[i])*RADIUS, cos(times[i])*RADIUS, 0);

		o->SetPos(moved);
		o->Draw();
	}
}

SceneD::~SceneD()
{
	for (Object* o : shapes)
	{
		delete o;
	}
}
