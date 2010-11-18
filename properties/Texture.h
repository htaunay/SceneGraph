/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _TEXTURE_H
#define	_TEXTURE_H

#include "gl.h"
#include "Appearance.h"

//! Defines the texture appearance property used in Entity's.
//! At the moment, only BMP images can be loaded as textures.
class Texture : public Appearance
{
public:
	//! Loads and configures the texture attribute to the OpengL state.
	virtual void load();

	//! Unloads the texture attribute from the OpengL state.
	virtual void unLoad();

public:
	//! Constructor that initializes all of Texture's attributes.
	Texture();

	//! Delete's any loaded texture from the OpenGL state.
	~Texture();

	//! Set's the autmoatic texture generation paramenters to OpenGL.
	void setTextGenParameters( GLfloat* borderColor = NULL, GLfloat* materialColor = NULL );

	//! Set's if the texture genration is automatic or manual.
	inline void useAutmoaticGeneration( bool autoGen ) { _autoGen = autoGen; }

	//! Loads a BMP image as a texture.
	bool loadImage( const char *filepath );

private:
	GLfloat _materialColor[4];
	GLfloat _borderColor[4];

	bool _autoGen;

	unsigned int _id;
	unsigned int _imgWidth;
	unsigned int _imgHeight;
	unsigned char *_image;
};

#endif
