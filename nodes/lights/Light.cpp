/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Light.h"
#include "Utility.h"

Light::Light()
{
	Utility::initVectorf( _ambient,  Utility::VECTOR_SIZE );
	Utility::initVectorf( _diffuse,  Utility::VECTOR_SIZE );
	Utility::initVectorf( _specular, Utility::VECTOR_SIZE );
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
