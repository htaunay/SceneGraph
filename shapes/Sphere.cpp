/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Sphere.h"
#include <GL/glut.h>

void Sphere::draw()
{
	glutSolidSphere( _radius, _slices, _stacks );
}
