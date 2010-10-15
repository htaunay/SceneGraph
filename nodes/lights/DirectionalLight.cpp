#include "DirectionalLight.h"
#include "Utility.h"

int DirectionalLight::setupLights()
{
	glEnable( _lightID );
	glLightfv( _lightID, GL_POSITION, _direction );
	glLightfv( _lightID, GL_AMBIENT,  _ambient );
	glLightfv( _lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( _lightID, GL_SPECULAR, _specular );
	return 1;
}

DirectionalLight::DirectionalLight()
{
	_lightID = GL_LIGHT1;
	Utility::initVectorf( _direction, Utility::VECTOR_SIZE );
}

void DirectionalLight::setDirection( float x, float y, float z )
{
	_direction[0] = x;
	_direction[1] = y;
	_direction[2] = z;
	_direction[3] = 0;
}
