/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <GL/glut.h>

//! Virtual generic class for all objects that represent a node in the SceneGraph.
class Node
{
public:
	Node() {};

	virtual int setupCamera() = 0;
	virtual int setupLights() = 0;
	virtual void render() = 0;
};

#endif
