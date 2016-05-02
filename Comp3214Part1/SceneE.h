#pragma once

#include "Scene.h"
#include <vector>



class SceneE :
	public Scene
{
public:
	SceneE();
	~SceneE();
	void Init();
	void Draw(double time);

private:
	Object* plane;
};