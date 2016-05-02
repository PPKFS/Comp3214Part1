#pragma once
#include "Scene.h"
#include "Object.h"
class SceneC :
	public Scene
{
public:
	SceneC();
	~SceneC();
	void Init();
	void Draw(double time);
private:
	Object* s;
};

