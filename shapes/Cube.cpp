/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Cube.h"
#include "Utility.h"

Cube::Cube( float x, float y, float z, int slices )
{
	_x = x;
	_y = y;
	_z = z;

	_slices = slices;
}

void Cube::draw()
{
	int i, j;

	float xpot;
	float ypot;
	float zpot;

	float xslice = _x/_slices;
	float yslice = _y/_slices;
	float zslice = _z/_slices;

	GLfloat _s_gen_plane[4];
	GLfloat _t_gen_plane[4];

	Utility::initVectorgf( _s_gen_plane, 4, 0.0 );
	Utility::initVectorgf( _t_gen_plane, 4, 0.0 );

	glPushMatrix();

	//Draw Up Face
	_s_gen_plane[0] = 1.0;
	_t_gen_plane[2] = 1.0;
	glTexGenfv( GL_S, GL_OBJECT_PLANE, &_s_gen_plane[0] );
	glTexGenfv( GL_T, GL_OBJECT_PLANE, &_t_gen_plane[0] );
	_s_gen_plane[0] = 0.0;
	_t_gen_plane[2] = 0.0;

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

                                glVertex3f( xpot,	 ypot, zpot );
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
	_s_gen_plane[0] = 1.0;
	_t_gen_plane[1] = 1.0;
	glTexGenfv( GL_S, GL_OBJECT_PLANE, &_s_gen_plane[0] );
	glTexGenfv( GL_T, GL_OBJECT_PLANE, &_t_gen_plane[0] );
	_s_gen_plane[0] = 0.0;
	_t_gen_plane[1] = 0.0;

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
	_s_gen_plane[1] = 1.0;
	_t_gen_plane[2] = 1.0;
	glTexGenfv( GL_S, GL_OBJECT_PLANE, &_s_gen_plane[0] );
	glTexGenfv( GL_T, GL_OBJECT_PLANE, &_t_gen_plane[0] );
	_s_gen_plane[1] = 0.0;
	_t_gen_plane[2] = 0.0;

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

