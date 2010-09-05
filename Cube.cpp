#include "Cube.h"

void Cube::draw()
{
	glPushMatrix();
	glScalef( _x, _y, _z );
	glutSolidCube( 1.0 );
	glPopMatrix();
}
