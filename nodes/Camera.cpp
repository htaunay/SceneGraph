/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Camera.h"
#include <stdio.h>

// Default aspect ratio value, considering there will be no window resizing.
static const float ASPECT_RATIO = 16.0/9.0;

int Camera::setupCamera()
{
	// Configures/updates the camera's state.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( _fovy, ASPECT_RATIO, _znear, _zfar );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt( _eye[0],		_eye[1],	_eye[2],
			   _center[0],	_center[1], _center[2],
			   _up[0],		_up[1],		_up[2] );

	// Update's the manipulator object.
	_manipulator->setCenter( _center );
	_manipulator->setOrigin( _eye );
	_manipulator->load();

	return 1;
}

Camera::Camera()
{
	_eye[0]    = 0;	_eye[1]    = 0;	_eye[2]    = 0;
	_center[0] = 0;	_center[1] = 0; _center[2] = 0;
	_up[0]     = 0;	_up[1]     = 0;	_up[2]     = 0;

	_fovy  = 0;
	_znear = 0;
	_zfar  = 0;
	
	_manipulator = Manipulator::getInstance();
}

void Camera::setEye( double x, double y, double z )
{
	_eye[0] = x;
	_eye[1] = y;
	_eye[2] = z;
}

void Camera::setCenter( double x, double y, double z )
{
	_center[0] = x;
	_center[1] = y;
	_center[2] = z;
}

void Camera::setUp( double x, double y, double z )
{
	_up[0] = x;
	_up[1] = y;
	_up[2] = z;
}
