#ifndef _POSITIONAL_LIGHT_H_
#define _POSITIONAL_LIGHT_H_

#include "Light.h"

class PositionalLight : public Light
{
public:
	virtual inline int setupCamera() { return 1; }

	virtual int setupLights();

	virtual inline void render() {;}

public:
	PositionalLight();

	virtual void setAmbient( float r, float g, float b, float alpha );

	virtual void setDiffuse( float r, float g, float b, float alpha );

	virtual void setSpecular( float r, float g, float b, float alpha );

	void setPosition( float x, float y, float z );

private:
	float _position[16];
};

#endif
