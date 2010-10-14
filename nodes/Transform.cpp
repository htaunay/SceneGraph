#include "Transform.h"
#include "Utility.h"

// Class Methods

int Transform::setupCamera()
{
	glPushMatrix();
	glMultMatrixd( _tMatrix );
	Group::setupCamera();
	glPopMatrix();
}

int Transform::setupLights()
{
	glPushMatrix();
	glMultMatrixd( _tMatrix );
	Group::setupLights();
	glPopMatrix();
}

void Transform::render()
{
	glPushMatrix();
	glMultMatrixd( _tMatrix );
	Group::render();
	glPopMatrix();
}

Transform::Transform()
{
	glPushMatrix();
	glLoadIdentity();
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	Utility::copyVectord( _tMatrix, _iMatrix, Utility::MATRIX_SIZE );
	glPopMatrix();
}

void Transform::translate( double x, double y, double z )
{
	glPushMatrix();
	glLoadMatrixd( _tMatrix );
	glTranslated( x, y, z );
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	glLoadIdentity();
	glPopMatrix();
}

void Transform::rotate( double angle, double x, double y, double z )
{
	glPushMatrix();
	glLoadMatrixd( _tMatrix );
	glRotated( angle, x, y, z );
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();
}

void Transform::scale( double x, double y, double z )
{
	glPushMatrix();
	glLoadMatrixd( _tMatrix );
	glScalef( x, y, z );
	glGetDoublev( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();
}
