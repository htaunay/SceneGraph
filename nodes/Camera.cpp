#include "Camera.h"

int Camera::setupCamera()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( _fovy, 16/9, _znear, _zfar );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt( _eye[0],		_eye[1],	_eye[2],
			   _center[0],	_center[1], _center[2],
			   _up[0],		_up[1],		_up[2] );

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
