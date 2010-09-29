#include <stdio.h>
#include "Utility.h"
#include "Texture.h"

Texture::Texture()
{
	generate_tex_coord = false;
	image = NULL;

	Utility::initVectorgf( material_color, 3, 1 );
	material_color[3] = 0.0;

	Utility::initVectorgf( border_color, 4 );
}

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void Texture::load()
{
	glPushAttrib(GL_TEXTURE_BIT);

	glBindTexture(GL_TEXTURE_2D, id);

	glEnable(GL_TEXTURE_2D);
	if(generate_tex_coord)
	{
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);

		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGenfv(GL_S, GL_OBJECT_PLANE, &s_gen_plane[0]);
		glTexGenfv(GL_T, GL_OBJECT_PLANE, &t_gen_plane[0]);
	}

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
	glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, (const GLfloat*)&material_color);
}

void Texture::unLoad()
{
	glPopAttrib();
}

void Texture::SetGenerateTextureCoord(bool g)
{
	generate_tex_coord = g;
}

void Texture::SetTextureParameters( GLfloat* borderColor )
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
}

void Texture::SetPlanes( GLfloat *s_plane, GLfloat *t_plane )
{
	Utility::copyVectorgf( s_plane, s_gen_plane, 4 );
	Utility::copyVectorgf( t_plane, t_gen_plane, 4 );
}

bool Texture::LoadImage( const int width, const int height, const char *filepath )
{
	// Checks if there is already an image loaded.
	// The previously loaded image must be freed before the new image is loaded.
	if( image != NULL )
		return false;

	image_width = width;
	image_height = height;

	FILE *img_file = fopen( filepath, "rb" );

	if( !img_file )
		return false;

	const int img_size = image_width * image_height * 3;

	image = new unsigned char[img_size];

	if( !image )
		return false;

	fread( image, img_size, 1, img_file );

	fclose( img_file );

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

	return true;
}
