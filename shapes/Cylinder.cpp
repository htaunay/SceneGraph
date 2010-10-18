/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Cylinder.h"
#include "Utility.h"
#include "glut.h"

void Cylinder::draw()
{
	double m[16];
	Utility::initVectord( m, 16 );

	glPushMatrix();

	// Draws the solid cylinder
	GLUquadric *cyQuad = gluNewQuadric();
	gluCylinder( cyQuad, _topRadius, _baseRadius, _height, _slices, _stacks );

	if( _closed )
	{
		// Draws the cylinder's top
		glPushMatrix();

		glRotated( 180, 1, 0, 0 );
		glGetDoublev( GL_MODELVIEW_MATRIX, m );

		GLUquadric *dskQuad = gluNewQuadric();
		gluDisk( dskQuad, 0, _topRadius, _slices, _stacks );

		glPopMatrix();

		// Draws the cylinder's bottom
		glPushMatrix();

		glTranslated( 0, 0, _height );
		glGetDoublev( GL_MODELVIEW_MATRIX, m );

		GLUquadric *dskQuad2 = gluNewQuadric();
		gluDisk( dskQuad2, 0, _baseRadius, _slices, _stacks );

		glPopMatrix();
	}

	glPopMatrix();
}

Cylinder::Cylinder( double baseRadius, double topRadius, double height,
					bool closed, int slices, int stacks )
{
	_baseRadius = baseRadius;
	_topRadius	= topRadius;
	_height		= height;
	_closed		= closed;
	_slices		= slices;
	_stacks		= stacks;
}
