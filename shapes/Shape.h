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
