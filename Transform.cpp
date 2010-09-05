#include "Transform.h"

Transform::Transform()
{
	glPushMatrix();
	glLoadIdentity();
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	// calc matriz inversa
	glPopMatrix();
}

int Transform::setupCamera()
{
	int r = Group::setupCamera();

	if( r )
		glMultMatrixd( _iMatrix );

	return r;
}

int Transform::setupLights()
{
	//TODO
	return 1;
}

void Transform::render()
{
	glPushMatrix();
	glMultMatrixd( _tMatrix );
	Group::render();
	glPopMatrix();
}

void Transform::translate( double x, double y, double z )
{
	glPushMatrix();
	glLoadMatrixd( _tMatrix );
	glTranslated( x, y, z );
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();
}

void Transform::rotate( double angle, double x, double y, double z )
{
	glPushMatrix();
	glLoadMatrixd( _tMatrix );
	glRotated( angle, x, y, z );
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glRotated( -angle, x, y, z );
	glMultMatrixd( _iMatrix );
	glGetDoublev( GL_MODELVIEW_MATRIX, _iMatrix );
	glPopMatrix();
}

void Transform::scale( double x, double y, double z )
{
	_tMatrix[0] *= x;
	_tMatrix[1] *= y;
	_tMatrix[2] *= z;
}

double* loadIdentity()
{
	//TODO
	return 0;
}
