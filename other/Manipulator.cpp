// Manipulator.cpp
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Set 2010

// Class provided by Prof. Waldemar Celes for camera manipulation.

#include "Manipulator.h"
#include "Utility.h"

#include "glut.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1459
#define TORAD(x) (x*180.0f/PI)
#define ROTATION_SCALE 0.5
#define ZOOM_SCALE 0.5

Manipulator* Manipulator::_instance = 0;

/*** Static internal methods ***/

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
		Manipulator::getInstance()->translate( 0, 0, 0.25 );

	else if( key == 's' )
		Manipulator::getInstance()->translate( 0, 0, -0.25 );

	else if( key == 'a' )
		Manipulator::getInstance()->translate( 0.25, 0, 0 );

	else if( key == 'd' )
		Manipulator::getInstance()->translate( -0.25, 0, 0 );

	if( key == 'l' )
		Manipulator::getInstance()->setWireframe();

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
			Manipulator::getInstance()->rotate(TORAD(2*asin(r.Length()*ROTATION_SCALE)),r.x,r.y,r.z);
		}
		else if( g_state == 'r' )
		{
			int vp[4];
			glGetIntegerv(GL_VIEWPORT,vp);
			float f = dx > dy ? (float)(x-g_x0) / vp[2] : (float) (-y+g_y0) / vp[3];
			f *= ZOOM_SCALE;
			Manipulator::getInstance()->scale(1-f, 1-f, 1-f);
		}

		g_x0 = x; g_y0 = y;
		glutPostRedisplay();
	}
}

/*** Class methods ***/

Manipulator* Manipulator::getInstance()
{
	if( _instance == NULL )
		_instance = new Manipulator();

	return _instance;
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

void Manipulator::load()
{
	glTranslatef( 0.0f, 0.0f, -_center.y );
	glMultMatrixf( _tMatrix );
	glTranslatef( 0.0f, 0.0f, _center.y );
}

void Manipulator::identity()
{
	glPushAttrib( GL_TRANSFORM_BIT );
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();
	glGetFloatv( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();
	glPopAttrib();
}

void Manipulator::rotate( float angle, float rx, float ry, float rz )
{
	glPushAttrib( GL_TRANSFORM_BIT );
	glMatrixMode( GL_MODELVIEW );

	glPushMatrix();
	glLoadIdentity();
	glRotatef( angle, rx, ry, rz );
	glMultMatrixf( _tMatrix );
	glGetFloatv( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glRotated( -angle, rx, ry, rz );
	glLoadMatrixf( _iMatrix );
	glGetFloatv( GL_MODELVIEW_MATRIX, _iMatrix );
	glPopMatrix();

	glPopAttrib();
}

void Manipulator::scale( float sx, float sy, float sz )
{
	glPushAttrib( GL_TRANSFORM_BIT );
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity();
	glScalef( sx, sy, sz );
	glMultMatrixf( _tMatrix );
	glGetFloatv( GL_MODELVIEW_MATRIX,  _tMatrix );
	glPopMatrix();
	glPopAttrib();
}

void Manipulator::translate( float tx, float ty, float tz )
{
	glPushMatrix();
	glLoadMatrixf( _tMatrix );
	glTranslatef( tx, ty, tz );
	glGetFloatv( GL_MODELVIEW_MATRIX, _tMatrix );
	glPopMatrix();
}

void Manipulator::setWireframe()
{
	if( _wireframe )
	{
		_wireframe = false;
		glPolygonMode( GL_FRONT,GL_FILL );
	}
	else
	{
		_wireframe = true;
		glPolygonMode( GL_FRONT,GL_LINE );
	}
}

Manipulator::Manipulator()
{
	_wireframe = false;

	identity();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(motion);
}
