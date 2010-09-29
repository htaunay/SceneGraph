#include "SpotLight.h"
#include "Utility.h"

#include <stdio.h>

int SpotLight::setupLights()
{
	GLenum lightID = GL_LIGHT2;
	glEnable( lightID );
	glLightfv( lightID, GL_AMBIENT,  _ambient );
	glLightfv( lightID, GL_DIFFUSE,  _diffuse );
	glLightfv( lightID, GL_SPECULAR, _specular );

	glLightfv( lightID, GL_POSITION,			  _position );
	glLightfv( lightID, GL_SPOT_DIRECTION,		  _direction );
	glLightf(  lightID, GL_SPOT_CUTOFF,			  _cutOff );
	glLightf(  lightID, GL_SPOT_EXPONENT,		  _expoent );
	glLightf(  lightID, GL_CONSTANT_ATTENUATION,  _constantAtt );
	glLightf(  lightID, GL_LINEAR_ATTENUATION,	  _linearAtt );
	glLightf(  lightID, GL_QUADRATIC_ATTENUATION, _quadAtt );

	return 1;
}

SpotLight::SpotLight()
{
	Utility::initVectorf( _position, 3 );
	_position[3] = 1;

	Utility::initVectorf( _direction, 3 );
	_cutOff		 = 90.0f;
	_expoent     = 64.0f;
	_constantAtt = 1.0f;
	_linearAtt   = 0.0f;
	_quadAtt	 = 0.0f;
}

void SpotLight::setAmbient( float r, float g, float b, float alpha )
{
	Light::setAmbient( r, g, b, alpha );
}

void SpotLight::setDiffuse( float r, float g, float b, float alpha )
{
	Light::setDiffuse( r, g, b, alpha );
}

void SpotLight::setSpecular( float r, float g, float b, float alpha )
{
	Light::setSpecular( r, g, b, alpha );
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
