/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

#include "Light.h"

/*!
	Specific implementation of a Light object, that creates infinite light
	rays projecting in a specified direction for the whole scene.
 */
class DirectionalLight : public Light
{
public:
	//! Method inherited from Node object and implemented according to the
	//! DirectionalLight specifications.
	virtual int setupLights();

	// Methods inherited by Node object. No changes.
	virtual inline void render() {;}
	virtual inline int setupCamera() { return 1; }

public:
	//! Constructor that initializes all of DirectionalLight's attributes.
	DirectionalLight();

	//! Set's the light's direction attribute.
	void setDirection( float x, float y, float z );

private:
	float _direction[4];
};

#endif
