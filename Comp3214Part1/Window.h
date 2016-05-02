#pragma once

#include <GL/glew.h>
#include <GL/glfw3.h>
#include "SceneA.h"
#include "SceneB.h"
#include "SceneC.h"
enum SceneType
{
	SCENE_A,
	SCENE_B,
	SCENE_C,
	SCENE_D,
	SCENE_E
};

class Window
{

public:
	Window();
	~Window();
	void RunLoop();
	inline bool IsInit() { return init;  }
	inline float GetRatio() { return width / (float)height; }
	inline GLuint GetProgram() { return program; }
	void Destroy();
	void SetScene(SceneType sceneType);
private:
	GLFWwindow* window;
	bool init;
	int width, height;
	float ratio;
	SceneType sceneType;
	Scene* scene;
	GLuint program;
};

extern Window* programWindow;

