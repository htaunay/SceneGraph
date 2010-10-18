/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include "Texture.h"

// All BMP loading methods provided by Prof. Waldemar Celes.

/***** Internal auxiliary functions for BMP texture loading *****/

static void reverseRGB( int n, unsigned char *pixels )
{
	unsigned char aux;
	unsigned char *rgb;

	for( int i = 0; i < n; i++ )
	{
		rgb = pixels + ( i * 3 );

		aux    = rgb[0];
		rgb[0] = rgb[2];
		rgb[2] = aux;
	}
}

static unsigned int bmpRead2Bytes( FILE *fp )
{
	unsigned char c[2];
	unsigned int v = 0;

	fread( &c, 1, 2, fp );
	v = c[0]+ (( unsigned int)c[1] << 8 );

	return v;
}

static unsigned int bmpRead4Bytes( FILE *fp )
{
	unsigned char c[4];
	unsigned int v = 0;

	fread( &c, 1, 4, fp );
	v = c[0]+
		(( unsigned int)c[1] << 8 )+
		(( unsigned int)c[2] << 16)+
		(( unsigned int)c[3] << 24);

	return v;
}

static unsigned char* bmpReadPalette( FILE *fp, int palettesize )
{
	static unsigned char palette[256];
	char red, green, blue, zero;

	for( int i = 0; i < palettesize/4; i++ )
	{
		fread( &red,   1, 1, fp );
		fread( &green, 1, 1, fp );
		fread( &blue,  1, 1, fp );
		fread( &zero,  1, 1, fp );

		if( red != green || red != blue )
			return 0;

		palette[i] = red;
	}

	return palette;
}

/***** Class functions *****/

void Texture::load()
{
	glPushAttrib( GL_TEXTURE_BIT );

	glBindTexture( GL_TEXTURE_2D, _id );

	glEnable( GL_TEXTURE_2D );

	glEnable( GL_TEXTURE_GEN_S );
	glEnable( GL_TEXTURE_GEN_T );

	glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
	glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );

	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

void Texture::unLoad()
{
	glPopAttrib();
}

Texture::Texture()
{
	_image = NULL;

	Utility::initVectorgf( _materialColor, 3 );
	Utility::initVectorgf( _borderColor, 4 );
}

Texture::~Texture()
{
	if( _id != 0 )
		glDeleteTextures( 1, &_id );
}

void Texture::setTextGenParameters( GLfloat *borderColor, GLfloat *materialColor )
{
	if( borderColor )
		Utility::copyVectorgf( borderColor, _borderColor, 4 );

	if( materialColor )
		Utility::copyVectorgf( materialColor, _materialColor, 4 );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST) ;
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, _borderColor );
	glTexEnvfv( GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, (const GLfloat*)&_materialColor[0] );
}

bool Texture::loadImage( const char *filepath )
{
	// Return if a image has already been loaded
	if( _image != NULL )
		return false;
	
	// Declaring method variables
	char filetype[2];
	unsigned int filesize;
	unsigned int imgsize;
	unsigned int garbage;
	unsigned int offset;
	unsigned int width;
	unsigned int height;
	unsigned int nbits;
	unsigned char *palette;

	// Opening bmp file
	FILE* fp = fopen( filepath, "rb" );
	if( fp == NULL )
		return NULL;

	// Verifying if file is really bmp
	fread( filetype, 1, 2, fp );
	if( filetype[0] != 'B' || filetype[1] != 'M' )
		return false;

	// Reading basic image data
	filesize = bmpRead4Bytes(fp);
	garbage  = bmpRead4Bytes(fp);
	offset   = bmpRead4Bytes(fp);
	garbage  = bmpRead4Bytes(fp);
	width    = bmpRead4Bytes(fp);
	height   = bmpRead4Bytes(fp);
	garbage  = bmpRead2Bytes(fp);
	nbits    = bmpRead2Bytes(fp);

	// Verifying if image pixels have exactly 24 or 8 bits
	if( nbits != 24 && nbits != 8 )
		return false;

	// Reading more data and allocating memory for image
	garbage  = bmpRead4Bytes(fp);
	imgsize  = bmpRead4Bytes(fp);
	_image   = (unsigned char*)malloc( imgsize );
	if( _image == NULL )
		return false;


	// Reading the image palette, and closing file connection
	garbage = bmpRead4Bytes(fp);
	garbage = bmpRead4Bytes(fp);
	garbage = bmpRead4Bytes(fp);
	garbage = bmpRead4Bytes(fp);
	palette = bmpReadPalette( fp, offset-54 );
	fread( _image, 1, imgsize, fp );
	if( nbits == 24 )
		reverseRGB(imgsize/3,_image);
	else
	{
		for( int i = 0; i < imgsize; i++ )
			_image[i] = _image[_image[i]];
	}
	fclose(fp);

	// Aplying loaded image as a texture to OpenGL
	glGenTextures( 1, &_id );
	glBindTexture( GL_TEXTURE_2D, _id );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, _image );

	return true;
}
