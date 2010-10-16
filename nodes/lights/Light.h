/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Node.h"

/*!
  Father class for all specific Light implementations. This virtual class should
  not be used directly (actually, it shouldn't even compile).
  Light only set's the main OpenGL attributes (ambient, diffuse, specular), and
  inherits the Node object's basic functions.
 */
class Light : public Node
{
public:
	//! Constructor that initializes all of Light's attributes.
	Light();

	//! Set's the light ambient attribute.
	virtual void setAmbient( float r, float g, float b, float alpha );

	//! Set's the light diffuse attribute.
	virtual void setDiffuse( float r, float g, float b, float alpha );

	//! Set's the light specular attribute.
	virtual void setSpecular( float r, float g, float b, float alpha );

protected:
	GLenum _lightID;

	float _ambient[4];
	float _diffuse[4];
	float _specular[4];
};

#endif
