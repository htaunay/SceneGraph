#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "gl.h"
#include "Appearance.h"

class Texture : public Appearance
{
public:
	virtual void load();

	virtual void unLoad();

public:
	Texture( const char *filename );

protected:
	GLuint _texture;
	const char *_filename;
};

#endif
