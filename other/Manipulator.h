// Manipulator.h
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Jan 2008

// Class provided by Prof. Waldemar Celes for camera manipulation.

#ifndef V_MANIPULATOR_H
#define V_MANIPULATOR_H

#include "VVector.h"

/*!
	As the name says, manipulates the scene's camera, rotating around the camera's
	center, zooming in and out, and translating on the x,z axis. However, the
	translation implementation is trivial, moving only in the worlds coordinates.
	This class also offer's auxiliary user commands, such as turning on/off
	the wireframe view.
	Since there is no reason to exist more than one manipulators, it is a Singleton.

	Commands:
	Mouse left-click + moving mouse		- Rotate's scene
	Mouse right-click + moving mouse	- Zoom's in/out
	Keyboard WASD						- Moves on the x,z plane of the world space
	Keyboard L							- Turns on/off wireframe view
 */
class Manipulator
{
public:
	//! Returns the only instance of the Scene object.
	static Manipulator* getInstance();

public:
	//! Set's the Manipulator's center distance attribute.
	void setCenter( double *center );

	//! Set's the Manipulator's origin distance attribute.
	void setOrigin( double *origin );

	//! Load's the Manipulator, should be called inside the Camera object 
	//! setupCamera() method.
	void load();

	//! Rotate's the Camera's orientation around the specified center distance.
	void rotate( float angle, float rx, float ry, float rz );

	//! Scale's the whole scene, to give a impression of a zoom effect.
	void scale( float sx, float sy, float sz );

	//! Translate's the scene around the x,z plane in the world coordinates.
	void translate( float tx, float ty, float tz );

	//! Turns on/off(varying on each call) the wireframe view.
	void setWireframe();

private:
	// Contructor that initializes the object attributes and I/O callbacks.
	Manipulator();

	// Load's a identity matrix to the OpenGL stack.
	void identity();

private:
	static Manipulator* _instance;

	bool _wireframe;
	float _matrix[16];
	VVector _center;
	VVector _origin;
};

#endif
