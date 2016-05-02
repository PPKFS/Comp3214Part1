#pragma once
#include "Scene.h"
#include "Sphere.h"

class SceneA :
	public Scene
{
public:
	SceneA();
	~SceneA();
	void Draw(double time);
	void Init() {};
private:
	Object* s;
};

