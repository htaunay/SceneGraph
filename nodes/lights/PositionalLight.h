/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _POSITIONAL_LIGHT_H_
#define _POSITIONAL_LIGHT_H_

#include "Light.h"

/*!
	Specific implementation of a Light object, that creates infinite light
	rays projecting from a specified origin in all directions, for the whole scene.
 */
class PositionalLight : public Light
{
public:
	//! Method inherited from Node object and implemented according to the
	//! PositionalLight specifications.
	virtual int setupLights();

	// Methods inherited by Node object. No changes.
	virtual inline void render() {;}
	virtual inline int setupCamera() { return 1; }

public:
	//! Constructor that initializes all of PositionalLight's attributes.
	PositionalLight();

	//! Set's the light's position attribute.
	void setPosition( float x, float y, float z );

private:
	float _position[16];
};

#endif
