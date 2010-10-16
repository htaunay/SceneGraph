/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _ENVIRON_H_
#define _ENVIRON_H_

#include "gl.h"
#include "Group.h"

/*!
	Property that applies to the entire scene (differently from Materials and
	Textures, that only apply to specified Entitys).
	At the moment, the only property implmented in the Environ class in the
	fog effect, that makes the transition of objects in the scene being clipped
	at the zfar limit gradient.
 */
class Environ : public Group
{
public:
	//! Constructor that initializes all of Environ's attributes.
	Environ();

	//! Set's the color in which the objects being clipped will gradiently turn into.
	void setFogColor( float r, float g, float b, float a );

	//! Set's the begining and end of the fog effect, where at start distance
	//! the object will be 100% visible, and at the end distance, 100% the fog color.
	void setFogDistance( float start, float end );

	//! Enable's the fog effect in the Envrion.
	void enableFog();

	//! Disable's the fog effect in the Envrion.
	void disableFog();

protected:
	float _fogColor[4];
	float _fogStart;
	float _fogEnd;
	GLenum _fogMode;
};
#endif
