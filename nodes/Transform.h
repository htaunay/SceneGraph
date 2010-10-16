/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Group.h"

/*!
	Manipulates it's children's object size, position and orientation in the
	world space.
	It is common that practically all Entity's have a Transform father node
	in the SceneGraph, since it is unlikely that to objets occupy the exact
	same space.
 */
class Transform : public Group
{
public:
	//! Performs the trasnformation, call's the setupCamera() method for all of
	//! the Transform node's children, and returns to the original state.
	virtual int setupCamera();

	//! Performs the trasnformation, call's the setupLights() method for all of
	//! the Transform node's children, and returns to the original state.
	virtual int setupLights();

	//! Performs the trasnformation, call's the render() method for all of
	//! the Transform node's children, and returns to the original state.
	virtual void render();

public:
	//! Constructor that loads an identity matrix to the OpenGL stack and
	//! initializes the transformation and inverse matrixes.
	Transform();

	//! Translate's all of the nodes children in the world space.
	void translate( double x, double y, double z );

	//! Rotate's all of the nodes children in the world space.
	void rotate( double angle, double x, double y, double z );

	//! Scale's all of the nodes children in the world space.
	void scale( double x, double y, double z );

private:
	double _tMatrix[16];
	double _iMatrix[16];
};

#endif
