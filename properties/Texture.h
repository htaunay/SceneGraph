#ifndef _TEXTURE_H
#define	_TEXTURE_H

#include "gl.h"
#include "Appearance.h"

class Texture : public Appearance
{
private:

	bool generate_tex_coord;

	GLfloat material_color[4];

	GLfloat border_color[4];

	unsigned int id;

	void* image;

	int image_width;

	int image_height;

	GLfloat s_gen_plane[4];

	GLfloat t_gen_plane[4];

public:
	Texture();

	virtual ~Texture();

	void load();

	void unLoad();

	bool LoadImage(const int width, const int height, const char *filepath);

	void SetGenerateTextureCoord(bool g);

	void SetTextureParameters( GLfloat* borderColor );

	void SetPlanes( GLfloat *s_plane, GLfloat *t_plane);
};

#endif	/* _TEXTURE_H */
