#ifndef _SCENE_H_
#define _SCENE_H_

#include "Group.h"
#include "Environ.h"

class Scene : public Group
{
public:
	virtual int setupCamera();

	virtual int setupLights();

	virtual void render();

public:
	~Scene();

	static Scene* getInstance();

private:
	Scene();

private:
	static Scene* _instance;
	Environ* globalEnv;
};

#endif
