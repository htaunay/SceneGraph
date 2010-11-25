/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _TOON_SHADER_H_
#define _TOON_SHADER_H_

#include "gl.h"

class ToonShader
{
public:
	static ToonShader* getInstance();
	~ToonShader();

	void enable();
	void disable();

	bool init();

	void setColor( float* color );

private:
	ToonShader();

private:
	static ToonShader* _instance;
	bool _hasProgram;
	GLfloat _color[4];

	GLuint program_object;
	GLuint vertex_shader;
	GLuint fragment_shader;
};

#endif
