/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"
#include <GL/gl.h>

//! Shape object in the from of a Cube, with automatic texture geneartion support.
class Cube : public Shape
{
public:
	//! Draws a solid cube in the scene, with the origin at the center of the object.
	virtual void draw();

public:
	/*!
		Cube constructor. The number of slices can be specified, but
		by default it is 50, divided equally between both sides of the Quads.
		Also initializes of the Cube's attributes.
	*/
	Cube( float x, float y, float z, int slices = 50 );

private:
	// Sets which plane will be used for the automatic texture generation.
	void configTexturePlanes( int splane, int tplane );

private:
	float _x, _y, _z;
	int _slices;

	GLfloat _sGenPlane[4];
	GLfloat _tGenPlane[4];
};
