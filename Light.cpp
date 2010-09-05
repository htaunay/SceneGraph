#include "Light.h"

int Light::setupLights()
{
	GLenum lightID = GL_LIGHT0 + 0;
	glEnable( lightID );
	glLightfv( lightID, GL_POSITION, _position );
	glLightfv( lightID, GL_AMBIENT,  _ambient );
	glLightfv( lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( lightID, GL_SPECULAR, _specular );
	return 1;
}

Light::Light()
{
	//TODO
}

void Light::setAmbient( float r, float g, float b, float alpha )
{
	_ambient[0] = r;
	_ambient[1] = g;
	_ambient[2] = b;
	_ambient[3] = alpha;
}

void Light::setDiffuse( float r, float g, float b, float alpha )
{
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = alpha;
}

void Light::setSpecular( float r, float g, float b, float alpha )
{
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = alpha;
}

void Light::setPosition( float x, float y, float z )
{
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
	_position[3] = 1;
}
