/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _SCENE_H_
#define _SCENE_H_

#include "Group.h"
#include "Environ.h"

/*
	Father node of all nodes in the SceneGraph. At no moment there should exsit
	more than one Scene object in the SceneGraph, therefore, it is a Singleton.
	By default, the Camera node should be the scene's first child, and the main
	Light node the second child. After that, its up to the user, but if desired,
	the Scene can also be configured differently, but always with the Scene
	node as the father of all nodes.
 */
class Scene : public Group
{
public:
	//! Call's the setupCamera() method of all of the Scene's children.
	virtual int setupCamera();

	//! Call's the setupLights() method of all of the Scene's children.
	virtual int setupLights();

	//! Call's the render() method of all of the Scene's children.
	virtual void render();

public:
	~Scene();

	//! Returns the only instance of the Scene object.
	static Scene* getInstance();

private:
	Scene() {};

private:
	static Scene* _instance;
	Environ* globalEnv;
};

#endif
