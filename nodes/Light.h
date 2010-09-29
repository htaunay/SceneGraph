#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Node.h"

class Light : public Node
{
public:
	virtual inline int setupCamera() { return 1; }

	virtual int setupLights();

	virtual inline void render() {;}

public:
	Light();

	virtual void setAmbient( float r, float g, float b, float alpha );

	virtual void setDiffuse( float r, float g, float b, float alpha );

	virtual void setSpecular( float r, float g, float b, float alpha );

protected:
	float _ambient[16];
	float _diffuse[16];
	float _specular[16];
};

#endif
