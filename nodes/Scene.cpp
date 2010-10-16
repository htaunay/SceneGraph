/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Scene.h"

Scene* Scene::_instance = NULL;

Scene* Scene::getInstance()
{
	if( _instance == NULL )
		_instance = new Scene();

	return _instance;
}

Scene::~Scene()
{
	delete _instance;
	_instance = NULL;
}

int Scene::setupCamera()
{
	Group::setupCamera();
	return 1;
}

int Scene::setupLights()
{
	glEnable( GL_LIGHTING );
	Group::setupLights();
	return 1;
}

void Scene::render()
{
	Group::render();
}
