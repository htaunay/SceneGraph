/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Transform.h"
#include "Utility.h"

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

	glPushMatrix();
	glLoadIdentity();
	glRotated( -angle, x, y, z );
	glLoadMatrixd( _iMatrix );
	glGetDoublev( GL_MODELVIEW_MATRIX, _iMatrix );
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
