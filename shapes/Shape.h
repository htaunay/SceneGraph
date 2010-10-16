/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "glut.h"

class Shape
{
public:
    Shape();

	virtual void draw() = 0;
};

#endif
