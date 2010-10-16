/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Material.h"
#include "glut.h"

void Material::load()
{
	glPushAttrib( GL_LIGHTING_BIT );
	glMaterialfv( GL_FRONT, GL_AMBIENT, _ambient );
	glMaterialfv( GL_FRONT, GL_DIFFUSE, _diffuse );
	glMaterialfv( GL_FRONT, GL_SPECULAR, _specular );
	glMaterialf( GL_FRONT, GL_SHININESS, _shineness );
}

void Material::unLoad()
{
	glPopAttrib();
}

Material::Material()
{
	//empty
}

void Material::setAmbient( float r, float g, float b, float alpha )
{
	_ambient[0] = r;
	_ambient[1] = g;
	_ambient[2] = b;
	_ambient[3] = alpha;
}

void Material::setDiffuse( float r, float g, float b, float alpha )
{
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = alpha;
}

void Material::setSpecular( float r, float g, float b, float alpha )
{
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = alpha;
}

void Material::setShineness( float shineness )
{
	_shineness = shineness;
}
