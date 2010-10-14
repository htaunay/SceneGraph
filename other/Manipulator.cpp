// Manipulator.cpp
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Set 2010

#include "Manipulator.h"
#include "Vector.h"

#include "glut.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1459
#define TORAD(x) (x*180.0f/PI)

Manipulator* Manipulator::_current = 0;

// internal control
static char g_state = ' ';
static int g_x0, g_y0;

static VVector map( int x, int y )
{
	VVector v;
	int vp[4];

	glGetIntegerv( GL_VIEWPORT, vp );

	int radius = vp[2] < vp[3] ? vp[2]/2 : vp[3]/2;

	v.x = (float)((x-vp[0]) - vp[2]/2) / radius;
	v.y = (float)((vp[3]-y-vp[0]) - vp[3]/2) / radius;

	float len = sqrt(v.x*v.x + v.y*v.y);
	if (len > 1.0)
	{
		v.x /= len;
		v.y /= len;
		v.z = 0.0f;
	}
	else
	{
		v.z = sqrt(1 - v.x*v.x - v.y*v.y);
	}

	return v;
}

static void mouse( int button, int state, int x, int y )
{
	if( !Manipulator::getInstance() )
		return;

	if( state == GLUT_DOWN )
	{
		g_x0 = x; g_y0 = y;

		if( button == GLUT_LEFT_BUTTON )
			g_state = 'l';
		else if( button == GLUT_RIGHT_BUTTON )
			g_state = 'r';
		else
			g_state = ' ';
	}
}

static void keyboard( unsigned char key, int x, int y )
{
	if( !Manipulator::getInstance() )
		return;

	if( key == 'w' )
		Manipulator::getInstance()->translate( 0, 0, 0.1 );

	else if( key == 's' )
		Manipulator::getInstance()->translate( 0, 0, -0.1 );

	else if( key == 'a' )
		Manipulator::getInstance()->translate( 0.1, 0, 0 );

	else if( key == 'd' )
		Manipulator::getInstance()->translate( -0.1, 0, 0 );

	glutPostRedisplay();
}

static void motion( int x, int y )
{
	if( !Manipulator::getInstance() )
		return;

	int dx = abs(x-g_x0);
	int dy = abs(y-g_y0);

	if ( dx > 1 || dy > 1)
	{
		if( g_state == 'l' )
		{
			VVector v0 = map(g_x0, g_y0);
			VVector v1 = map(x, y);
			VVector r = Cross(v0, v1);
			Manipulator::getInstance()->rotate(TORAD(2*asin(r.Length())),r.x,r.y,r.z);
		}
		else if( g_state == 'r' )
		{
			int vp[4];
			glGetIntegerv(GL_VIEWPORT,vp);
			float f = dx > dy ? (float)(x-g_x0) / vp[2] : (float) (-y+g_y0) / vp[3];
			Manipulator::getInstance()->scale(1-f, 1-f, 1-f);
		}

		g_x0 = x; g_y0 = y;
		glutPostRedisplay();
	}
}

void Manipulator::setCurrent( Manipulator* manip )
{
	_current = manip;
}

Manipulator* Manipulator::getInstance()
{
	if( _current == NULL )
		_current = new Manipulator();
	else
		return _current;
}

Manipulator::Manipulator()
{
	identity();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
	setCurrent(this);
}

void Manipulator::setCenter( double *center )
{
	_center.x = center[0];
	_center.y = center[1];
	_center.z = center[2];
}

void Manipulator::setOrigin( double *origin )
{
	_origin.x = origin[0];
	_origin.y = origin[1];
	_origin.z = origin[2];
}

void Manipulator::identity()
{
	glPushAttrib(GL_TRANSFORM_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glGetFloatv(GL_MODELVIEW_MATRIX, _matrix);
	glPopMatrix();
	glPopAttrib();
}

void Manipulator::rotate( float angle, float rx, float ry, float rz )
{
	glPushAttrib(GL_TRANSFORM_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRotatef( angle, rx, ry, rz );
	glMultMatrixf( _matrix );
	glGetFloatv(GL_MODELVIEW_MATRIX, _matrix);
	glPopMatrix();
	glPopAttrib();
}

void Manipulator::scale( float sx, float sy, float sz )
{
	glPushAttrib(GL_TRANSFORM_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glScalef( sx, sy, sz );
	glMultMatrixf( _matrix);
	glGetFloatv(GL_MODELVIEW_MATRIX,  _matrix);
	glPopMatrix();
	glPopAttrib();
}

void Manipulator::translate( float tx, float ty, float tz )
{
	float nx = _center.x - _origin.x;
	float nz = _center.z - _origin.z;
	float hip = sqrt( nx*nx + nz*nz );
	float cos = nz/hip;
	float radians = cos * 90;

	glPushMatrix();
	glLoadMatrixf( _matrix );
	glRotatef( -radians, 0, 1, 0 );
	glTranslatef( tx, ty, tz );
	glRotatef( radians, 0, 1, 0 );
	glGetFloatv( GL_MODELVIEW_MATRIX, _matrix );
	glPopMatrix();
}

void Manipulator::load()
{
	glTranslatef(0.0f, 0.0f, -_center.y );
	glMultMatrixf( _matrix);
	glTranslatef(0.0f, 0.0f, _center.y );
}
