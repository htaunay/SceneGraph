#ifndef _TEXTURE_H
#define	_TEXTURE_H

#include "gl.h"
#include "Appearance.h"

class Texture : public Appearance
{
public:
	virtual void load();

	virtual void unLoad();

public:
	Texture();

	~Texture();

	bool LoadImage( const int width, const int height, const char *filepath );

	void SetGenerateTextureCoord(bool g);

	void SetTextureParameters( GLfloat* borderColor = NULL, GLfloat* materialColor = NULL );

	void SetPlanes( GLfloat *s_plane, GLfloat *t_plane);

private:
	bool _generate_tex_coord;

	GLfloat _material_color[4];
	GLfloat _border_color[4];

	unsigned int _id;
	void *_image;
	int _image_width;
	int _image_height;

	GLfloat _s_gen_plane[4];
	GLfloat _t_gen_plane[4];
};

#endif
