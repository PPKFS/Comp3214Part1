#pragma once
#include "Scene.h"
#include "Sphere.h"

class SceneB :
	public Scene
{
public:
	SceneB();
	~SceneB();
	void Draw(double time);
	void Init() {};
private:
	Object* s;
};

