/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "PositionalLight.h"
#include "Utility.h"

int PositionalLight::setupLights()
{
	glEnable( _lightID );
	glLightfv( _lightID, GL_POSITION, _position );
	glLightfv( _lightID, GL_AMBIENT,  _ambient );
	glLightfv( _lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( _lightID, GL_SPECULAR, _specular );
	return 1;
}

PositionalLight::PositionalLight()
{
	_lightID = GL_LIGHT0;
	Utility::initVectorf( _position, Utility::VECTOR_SIZE );
}

void PositionalLight::setPosition( float x, float y, float z )
{
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
	_position[3] = 1;
}
