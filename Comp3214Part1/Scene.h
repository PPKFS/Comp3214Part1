#pragma once

#include <GL/glew.h>
#include "Object.h"
#include <memory>
#include "Cone.h"
#include "TexturedPlane.h"

class Sphere;

enum ObjType
{
	SPHERE,
	CONE,
	PLANE
};
class Scene
{
public:
	static std::unique_ptr<Sphere> sphere, normalSphere;
	static std::unique_ptr<Cone> cone;
	static std::unique_ptr<TexturedPlane> plane;
	Scene();
	~Scene();
	static void BuildGeometryMeshes();
	virtual void Init() = 0;
	virtual void Draw(double time) = 0;
	void PreRender();
	void PostRender();
	Object* MakeObject(ObjType obj, bool isNormalSphere = false);
	inline void SetWireframe(bool w) { glPolygonMode(GL_FRONT_AND_BACK, w ? GL_LINE : GL_FILL); }
	void SetLight(bool l);
	void SetTexture(bool b);
};

