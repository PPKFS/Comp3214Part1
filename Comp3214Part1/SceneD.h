#pragma once
#include "Scene.h"
#include <vector>
#include "Sphere.h"
class SceneD :
	public Scene
{
public:
	SceneD();
	~SceneD();
	void Init();
	void Draw(double time);

private:
	std::vector<Object*> shapes;
	std::vector<float> times;
};

