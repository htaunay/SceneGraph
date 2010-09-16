#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

#include "Light.h"

class DirectionalLight : public Light
{
public:
	virtual inline int setupCamera() { return 1; }

	virtual int setupLights();

	virtual inline void render() {;}

public:
	DirectionalLight();

	virtual void setAmbient( float r, float g, float b, float alpha );

	virtual void setDiffuse( float r, float g, float b, float alpha );

	virtual void setSpecular( float r, float g, float b, float alpha );

	void setDirection( float x, float y, float z );

private:
	float _direction[16];
};

#endif
