/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Appearance.h"

//!	Defines and loads/unloads an Entity's material properties.
class Material : public Appearance
{
public:
	//! Loads the material properties to the OpengL state.
	virtual void load();

	//! Unloads the material properties from the OpengL state.
	virtual void unLoad();

public:
	//! Constructor that initializes all of the Materials attributes.
	Material();

	//! Set's the Material's ambient attribute.
	void setAmbient( float r, float g, float b, float alpha );

	//! Set's the Material's diffuse attribute.
	void setDiffuse( float r, float g, float b, float alpha );

	//! Set's the Material's specular attribute.
	void setSpecular( float r, float g, float b, float alpha );

	//! Set's the Material's shineness attribute.
	void setShineness( float shineness );

private:
	float _ambient[4];
	float _diffuse[4];
	float _specular[4];
	float _shineness;
};

#endif
