#include "Window.h"
#include "Sphere.h"
#include "Shader.h"
#include "SceneD.h"
#include "SceneE.h"
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>

Window* programWindow;

static void error_callback(int error, const char* description)
{
	std::cout << description << error << std::endl;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action != GLFW_PRESS)
		return;
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
	case GLFW_KEY_Q:
		glfwSetWindowShouldClose(window, GL_TRUE);
		break;
	case GLFW_KEY_A:
		programWindow->SetScene(SCENE_A);
		break;
	case GLFW_KEY_B:
		programWindow->SetScene(SCENE_B);
		break;
	case GLFW_KEY_C:
		programWindow->SetScene(SCENE_C);
		break;
	case GLFW_KEY_D:
		programWindow->SetScene(SCENE_D);
		break;
	case GLFW_KEY_E:
		programWindow->SetScene(SCENE_E);
		break;
	}

}

Window::Window()
{
	scene = NULL;
	init = false;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return;
	window = glfwCreateWindow(640, 640, "COMP3214", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	
	glewExperimental = GL_TRUE;
	int err = glewInit();
	if (GLEW_OK != err) {
		std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
		return;
	}
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	program = CreateShaderProgram();
	if(!program)
	{
		std::cerr << "Shaders are bork" << std::endl;
		return;
	}
	Scene::BuildGeometryMeshes();
	SetScene(SCENE_A);
	init = true;
	programWindow = this;
}

Window::~Window()
{
	if (scene != NULL)
		delete scene;
	if (program != NULL)
		glDeleteProgram(program);
}

void Window::SetScene(SceneType sceneType)
{
	if (sceneType == this->sceneType)
		return;
	if (scene != NULL)
		delete scene;
	this->sceneType = sceneType;
	switch (sceneType)
	{
	case SCENE_A:
		scene = new SceneA();
		break;
	case SCENE_B:
		scene = new SceneB();
		break;
	case SCENE_C:
		scene = new SceneC();
		break;
	case SCENE_D:
		scene = new SceneD();
		break;
	case SCENE_E:
		scene = new SceneE();
		break;
	}
	scene->Init();
}

void Window::RunLoop()
{
	glEnable(GL_CULL_FACE);
	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = this->GetRatio();
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), ratio, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 7,8), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 vp = projection * view;
	GLuint matrixID = glGetUniformLocation(program, "viewprojection");
	GLuint lit = glGetUniformLocation(program, "isLit");
	GLuint cam = glGetUniformLocation(program, "camera");
	glUniform3f(cam, 5, 5, 5);
	glUniform1i(lit, 0);
	double lastFrameTime = 0.f, lastTime = 0.f;
	
	while (!glfwWindowShouldClose(window))
	{
		double time = glfwGetTime();
		lastFrameTime = time - lastTime;
		lastTime = time;
		glUniformMatrix4fv(matrixID, 1, GL_FALSE, &vp[0][0]);
		scene->PreRender();
		scene->Draw(lastFrameTime);
		scene->PostRender();
		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}

void Window::Destroy()
{
	glfwDestroyWindow(this->window);
	glfwTerminate();
}