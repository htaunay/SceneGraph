#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"
#include "Texture.h"

void Texture::load()
{
	glPushAttrib( GL_TEXTURE_BIT );

	glBindTexture( GL_TEXTURE_2D, _id );

	glEnable( GL_TEXTURE_2D );
	if( _generate_tex_coord )
	{
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );

		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
	}

	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
}

void Texture::unLoad()
{
	glPopAttrib();
}

Texture::Texture()
{
	_generate_tex_coord = false;
	_image = NULL;

	Utility::initVectorgf( _material_color, 3, 1 );
	_material_color[3] = 0.0;

	Utility::initVectorgf( _border_color, 4 );
}

Texture::~Texture()
{
	glDeleteTextures( 1, &_id );
}

void Texture::SetGenerateTextureCoord(bool g)
{
	_generate_tex_coord = g;
}

void Texture::SetTextureParameters( GLfloat *borderColor, GLfloat *materialColor )
{
	if( borderColor )
		Utility::copyVectorgf( borderColor, _border_color, 4 );

	if( materialColor )
		Utility::copyVectorgf( materialColor, _material_color, 4 );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST) ;
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

	glTexParameterfv( GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, _border_color );
	glTexEnvfv( GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, (const GLfloat*)&_material_color );
}

void Texture::SetPlanes( GLfloat *s_plane, GLfloat *t_plane )
{
	Utility::copyVectorgf( s_plane, _s_gen_plane, 4 );
	Utility::copyVectorgf( t_plane, _t_gen_plane, 4 );
}

bool Texture::LoadImage( const int width, const int height, const char *filepath )
{
	if( _image != NULL )
		return false;
	
	_image_width = width;
	_image_height = height;

	FILE *img_file = fopen( filepath, "rb" );

	if( !img_file )
		return false;

	const int img_size = _image_width * _image_height * 3;

	_image = new unsigned char[img_size];

	if( !_image )
		return false;

	fread( _image, img_size, 1, img_file );

	fclose( img_file );

	glGenTextures( 1, &_id );
	glBindTexture( GL_TEXTURE_2D, _id );
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, _image );

	return true;
}
