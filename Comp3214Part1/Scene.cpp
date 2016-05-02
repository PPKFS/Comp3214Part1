#include "Scene.h"
#include "Window.h"


std::unique_ptr<Cone> Scene::cone;
std::unique_ptr<Sphere> Scene::sphere;
std::unique_ptr<Sphere> Scene::normalSphere;
std::unique_ptr<TexturedPlane> Scene::plane;

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::BuildGeometryMeshes()
{
	Scene::cone = std::unique_ptr<Cone>(new Cone());
	Scene::cone->Build();
	Scene::sphere = std::unique_ptr<Sphere>(new Sphere(30, 30, 2.f));
	Scene::sphere->Build();
	Scene::normalSphere = std::unique_ptr<Sphere>(new Sphere(30, 30, 2.f, true));
	Scene::normalSphere->Build();
	Scene::plane = std::unique_ptr<TexturedPlane>(new TexturedPlane());
	Scene::plane->Build();
}
Object* Scene::MakeObject(ObjType obj, bool isNormalSphere)
{
	return new Object(isNormalSphere ? normalSphere.get() : (obj == SPHERE ? (Mesh*)sphere.get() : obj == CONE ? (Mesh*)cone.get() : (Mesh*)plane.get()));
}

void Scene::SetLight(bool l)
{
	if (programWindow != NULL && programWindow->GetProgram() != NULL)
		glUniform1i(glGetUniformLocation(programWindow->GetProgram(), "isLit"), (GLint)l);
}

void Scene::SetTexture(bool l)
{
	if (programWindow != NULL && programWindow->GetProgram() != NULL)
		glUniform1i(glGetUniformLocation(programWindow->GetProgram(), "isTexture"), (GLint)l);
}
void Scene::PreRender()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::PostRender()
{

}
