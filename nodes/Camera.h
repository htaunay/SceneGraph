#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Node.h"

class Camera : public Node
{
public:
	virtual int setupCamera();

	virtual inline int setupLights() { return 1; }

	virtual inline void render() {;}

public:
	Camera();

	void setEye( double x, double y, double z );

	void setCenter( double x, double y, double z );

	void setUp( double x, double y, double z );

	void setFovy( double fovy ) { _fovy = fovy; }

	void setZNear( double znear ) { _znear = znear; }

	void setZFar( double zfar ) { _zfar = zfar; }

private:
	double _eye[3];
	double _center[3];
	double _up[3];

	double _fovy;
	double _znear;
	double _zfar;
};

#endif
