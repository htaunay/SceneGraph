#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Group.h"

class Transform : public Group
{
public:
	virtual int setupCamera();

	virtual int setupLights();

	virtual void render();

public:
	Transform();

	void translate( double x, double y, double z );

	void rotate( double angle, double x, double y, double z );

	void scale( double x, double y, double z );

private:
	double _tMatrix[16];
	double _iMatrix[16];
};

#endif
