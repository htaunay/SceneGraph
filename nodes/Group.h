/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _GROUP_H_
#define _GROUP_H_

#include "Node.h"
#include <vector>

/*!
	Generic Node object, which only purpose is to propagate its father's
	transformations and definitions to more than one child.
	Basically, you can add several children to the Group node, and when you pass
	through it in the sceneGraph, it will call all of the main Node methods
	for all of its children.
 */
class Group : public Node
{
public:
	//! Call's the setupCamera() method of all of the Group's children.
	virtual int setupCamera();

	//! Call's the setupLights() method of all of the Group's children.
	virtual int setupLights();

	//! Call's the rebder() method of all of the Group's children.
	virtual void render();

public:
	//! Empty constructor.
	Group();

	//! Add's a a node to the Group's child list.
	bool addNode( Node* newNode );

private:
	std::vector<Node*> _children;
};

#endif
