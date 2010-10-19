/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Cube.h"
#include "Utility.h"

// Auxiliary structures for defining which planes to be used during the
// automatic texture generation process.
enum sPlane{
	sx, sy, sz
};

enum tPlane{
	tx, ty, tz
};

/**** Class Methods *****/

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
	configTexturePlanes( sx, tz );

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
				glVertex3f( xpot,        ypot, zpot-zslice );
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
	configTexturePlanes( sx, ty );

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
	configTexturePlanes( sz, ty );

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

Cube::Cube( float x, float y, float z, int slices )
{
	_x = x;
	_y = y;
	_z = z;

	_slices = slices;

	Utility::initVectorgf( _sGenPlane, 4, 0.0 );
	Utility::initVectorgf( _tGenPlane, 4, 0.0 );
}

void Cube::configTexturePlanes( int sp, int tp )
{
	// Configures the plane vectors
	_sGenPlane[sp] = 0.5;
	_tGenPlane[tp] = 0.5;

	// Sets the s,t planes to OpenGL
	glTexGenfv( GL_S, GL_OBJECT_PLANE, &_sGenPlane[0] );
	glTexGenfv( GL_T, GL_OBJECT_PLANE, &_tGenPlane[0] );

	// Resets the plane values
	_sGenPlane[sp] = 0.0;
	_tGenPlane[tp] = 0.0;
}
