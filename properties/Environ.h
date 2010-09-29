#ifndef _ENVIRON_H_
#define _ENVIRON_H_

#include "gl.h"
#include "Group.h"

class Environ : public Group
{
public:
	Environ();

	void setFogColor( float r, float g, float b, float a );

	void setFogDistance( float start, float end );

	void setFogMode( GLenum fogMode );

	void enableFog();

	void disableFog();

protected:
	float _fogColor[4];
	float _fogStart;
	float _fogEnd;
	GLenum _fogMode;
};
#endif
