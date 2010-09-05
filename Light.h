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

	void setAmbient( float r, float g, float b, float alpha );

	void setDiffuse( float r, float g, float b, float alpha );

	void setSpecular( float r, float g, float b, float alpha );

	void setPosition( float x, float y, float z );

private:
	float _ambient[4];
	float _diffuse[4];
	float _specular[4];
	float _position[4];

};

#endif
