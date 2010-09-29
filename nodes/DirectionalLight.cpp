#include "DirectionalLight.h"
#include "Utility.h"

int DirectionalLight::setupLights()
{
	GLenum lightID = GL_LIGHT1;
	glEnable( lightID );
	glLightfv( lightID, GL_POSITION, _direction );
	glLightfv( lightID, GL_AMBIENT,  _ambient );
	glLightfv( lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( lightID, GL_SPECULAR, _specular );
	return 1;
}

void DirectionalLight::setAmbient( float r, float g, float b, float alpha )
{
	Light::setAmbient( r, g, b, alpha );
}

void DirectionalLight::setDiffuse( float r, float g, float b, float alpha )
{
	Light::setDiffuse( r, g, b, alpha );
}

void DirectionalLight::setSpecular( float r, float g, float b, float alpha )
{
	Light::setSpecular( r, g, b, alpha );
}

DirectionalLight::DirectionalLight()
{
	Utility::initVectorf( _direction, Utility::MATRIX_SIZE );
}

void DirectionalLight::setDirection( float x, float y, float z )
{
	_direction[0] = x;
	_direction[1] = y;
	_direction[2] = z;
	_direction[3] = 0;
}
