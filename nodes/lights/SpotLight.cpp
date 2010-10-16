/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "SpotLight.h"
#include "Utility.h"


int SpotLight::setupLights()
{
	glEnable( _lightID );
	glLightfv( _lightID, GL_AMBIENT,  _ambient );
	glLightfv( _lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( _lightID, GL_SPECULAR, _specular );

	glLightfv( _lightID, GL_POSITION,			   _position );
	glLightfv( _lightID, GL_SPOT_DIRECTION,		   _direction );
	glLightf(  _lightID, GL_SPOT_CUTOFF,		   _cutOff );
	glLightf(  _lightID, GL_SPOT_EXPONENT,		   _expoent );
	glLightf(  _lightID, GL_CONSTANT_ATTENUATION,  _constantAtt );
	glLightf(  _lightID, GL_LINEAR_ATTENUATION,	   _linearAtt );
	glLightf(  _lightID, GL_QUADRATIC_ATTENUATION, _quadAtt );

	return 1;
}

SpotLight::SpotLight()
{
	_lightID = GL_LIGHT2;

	Utility::initVectorf( _direction, 3 );
	Utility::initVectorf( _position, Utility::VECTOR_SIZE );
	_position[3] = 1;

	_cutOff		 = 90.0f;
	_expoent     = 64.0f;
	_constantAtt = 1.0f;
	_linearAtt   = 0.0f;
	_quadAtt	 = 0.0f;
}

void SpotLight::setPosition( float x, float y, float z )
{
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
	_position[3] = 1;
}

void SpotLight::setDirection( float x, float y, float z )
{
	_direction[0] = x;
	_direction[1] = y;
	_direction[2] = z;
}

void SpotLight::setupAttenuation( float constAtt, float linearAt, float quadAtt )
{
	_constantAtt = constAtt;
	_linearAtt   = linearAt;
	_quadAtt     = quadAtt;
}
