#ifndef _NODE_H_
#define _NODE_H_

#include "glut.h"

class Node
{
public:
	Node();

	virtual int setupCamera() = 0;

	virtual int setupLights() = 0;

	virtual void render() = 0;
};

#endif
