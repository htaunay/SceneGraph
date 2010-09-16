#include "Cube.h"

Cube::Cube( float x, float y, float z, int slices )
{
	_x = x;
	_y = y;
	_z = z;

	_slices = slices;
}
/*
void Cube::draw()
{
	glPushMatrix();
	glScalef( _x, _y, _z );
	glutSolidCube( 1 );
	glPopMatrix();
}*/

void Cube::draw()
{
	int i, j;

	float xpot;
	float ypot;
	float zpot;

	float xslice = _x/_slices;
	float yslice = _y/_slices;
	float zslice = _z/_slices;

	glPushMatrix();


	//Draw Up Face
	xpot = _x/2;
	ypot = _y/2;

	for( i = 0; i < _slices; i++ )
	{
		zpot = _z/2;
		for( j = 0; j < _slices; j++ )
		{
			glBegin( GL_QUADS );
			{
				glNormal3f( 0, 1, 0 );
				glVertex3f( xpot,		 ypot, zpot );
				glVertex3f( xpot,		 ypot, zpot-zslice );
				glVertex3f( xpot-xslice, ypot, zpot-zslice );
				glVertex3f( xpot-xslice, ypot, zpot );
			}
			glEnd();

			zpot -= zslice;
		}
		xpot -= xslice;
	}

	//Draw Down Face
	xpot = _x/2;
	ypot = _y/2;

	for( i = 0; i < _slices; i++ )
	{
		zpot = _z/2;
		for( j = 0; j < _slices; j++ )
		{
			glBegin( GL_QUADS );
			{
				glNormal3f( 0, -1, 0 );
				glVertex3f( xpot,		 -ypot, zpot );
				glVertex3f( xpot,		 -ypot, zpot-zslice );
				glVertex3f( xpot-xslice, -ypot, zpot-zslice );
				glVertex3f( xpot-xslice, -ypot, zpot );
			}
			glEnd();

			zpot -= zslice;
		}
		xpot -= xslice;
	}

	//Draw Front Face
	xpot = _x/2;
	zpot = _z/2;

	for( i = 0; i < _slices; i++ )
	{
		ypot = _y/2;
		for( j = 0; j < _slices; j++ )
		{
			glBegin( GL_QUADS );
			{
				glNormal3f( 0, 0, 1 );
				glVertex3f( xpot,		 -ypot,		   zpot );
				glVertex3f( xpot,		 -ypot+yslice, zpot );
				glVertex3f( xpot-xslice, -ypot+yslice, zpot );
				glVertex3f( xpot-xslice, -ypot,		   zpot );
			}
			glEnd();

			ypot -= yslice;
		}
		xpot -= xslice;
	}

	//Draw Back Face
	xpot = _x/2;
	zpot = _z/2;

	for( i = 0; i < _slices; i++ )
	{
		ypot = _y/2;
		for( j = 0; j < _slices; j++ )
		{
			glBegin( GL_QUADS );
			{
				glNormal3f( 0, 0, -1 );
				glVertex3f( xpot,		 -ypot,		   -zpot );
				glVertex3f( xpot,		 -ypot+yslice, -zpot );
				glVertex3f( xpot-xslice, -ypot+yslice, -zpot );
				glVertex3f( xpot-xslice, -ypot,		   -zpot );
			}
			glEnd();

			ypot -= yslice;
		}
		xpot -= xslice;
	}

	//Draw Left Face
	xpot = _x/2;
	zpot = _z/2;

	for( i = 0; i < _slices; i++ )
	{
		ypot = _y/2;
		for( j = 0; j < _slices; j++ )
		{
			glBegin( GL_QUADS );
			{
				glNormal3f( -1, 0, 0 );
				glVertex3f( -xpot, -ypot,		 zpot );
				glVertex3f( -xpot, -ypot+yslice, zpot );
				glVertex3f( -xpot, -ypot+yslice, zpot-zslice );
				glVertex3f( -xpot, -ypot,		 zpot-zslice );
			}
			glEnd();

			ypot -= yslice;
		}
		zpot -= zslice;
	}

	//Draw Right Face
	xpot = _x/2;
	zpot = _z/2;

	for( i = 0; i < _slices; i++ )
	{
		ypot = _y/2;
		for( j = 0; j < _slices; j++ )
		{
			glBegin( GL_QUADS );
			{
				glNormal3f( 1, 0, 0 );
				glVertex3f( xpot, -ypot,		-zpot );
				glVertex3f( xpot, -ypot+yslice, -zpot );
				glVertex3f( xpot, -ypot+yslice, -zpot+zslice );
				glVertex3f( xpot, -ypot,	    -zpot+zslice );
			}
			glEnd();

			ypot -= yslice;
		}
		zpot -= zslice;
	}

	glPopMatrix();
}

