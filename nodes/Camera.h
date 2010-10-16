/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Node.h"
#include "Manipulator.h"

/*!
	Configures, defines and manipulates everything that is viewed in the given
	canvas.
	By default, the Camera object should be the first node added in the
	SceneGraph, after the main Scene Node, so that any change in the scene
	doesn't get missed, but if necessary, multiple camera's can be distributed
	throughout the scene, if configurated corectly.
 */
class Camera : public Node
{
public:
	//! Method inherited from Node object and implemented according to the
	//! Camera specifications.
	virtual int setupCamera();

	// Methods inherited by Node object. No changes.
	virtual inline int setupLights() { return 1; }
	virtual inline void render() {;}

public:
	//! Constructor that initializes all of Camera's attributes.
	Camera();

	//! Set's the camera's eye position attribute.
	void setEye( double x, double y, double z );

	//! Set's the camera's center/direction attribute.
	void setCenter( double x, double y, double z );

	//! Set's the camera's up attribute.
	void setUp( double x, double y, double z );

	//! Set's the camera's fovy(angle opening) attribute.
	void setFovy( double fovy ) { _fovy = fovy; }

	//! Set's the camera's near clipping distance attribute.
	void setZNear( double znear ) { _znear = znear; }

	//! Set's the camera's far clipping distance attribute.
	void setZFar( double zfar ) { _zfar = zfar; }

private:
	double _eye[3];
	double _center[3];
	double _up[3];

	double _fovy;
	double _znear;
	double _zfar;

	Manipulator *_manipulator;
};

#endif
