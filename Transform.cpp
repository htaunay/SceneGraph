#include "Transform.h"
#include "Utility.h"

// Internal Methods
void copyMatrix( double mSrc[], double mDest[] )
{
	for( int i = 0; i < 16; i++ )
		mDest[i] = mSrc[i];
}

// Class Methods

int Transform::setupCamera()
{
	Group::setupCamera();
}

int Transform::setupLights()
{
	Group::setupLights();
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
