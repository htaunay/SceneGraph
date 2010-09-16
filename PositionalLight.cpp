#include "PositionalLight.h"
#include "Utility.h"

int PositionalLight::setupLights()
{
	GLenum lightID = GL_LIGHT0;
	glEnable( lightID );
	glLightfv( lightID, GL_POSITION, _position );
	glLightfv( lightID, GL_AMBIENT,  _ambient );
	glLightfv( lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( lightID, GL_SPECULAR, _specular );
	return 1;
}

PositionalLight::PositionalLight()
{
	Utility::initVectorf( _position, 4 );
}

void PositionalLight::setAmbient( float r, float g, float b, float alpha )
{
	Light::setAmbient( r, g, b, alpha );
}

void PositionalLight::setDiffuse( float r, float g, float b, float alpha )
{
	Light::setDiffuse( r, g, b, alpha );
}

void PositionalLight::setSpecular( float r, float g, float b, float alpha )
{
	Light::setSpecular( r, g, b, alpha );
}

void PositionalLight::setPosition( float x, float y, float z )
{
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
	_position[3] = 1;
}
