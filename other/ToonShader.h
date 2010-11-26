/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _TOON_SHADER_H_
#define _TOON_SHADER_H_

#include "GLee.h"
#include <GL/gl.h>

/*
	Singleton-render class, that renders all geometry's added between the
	disble/deisable commands as a cartoon(toon). In other words, with limited
	color variation, and a black colored border.
	If the sceens's main light(id=0) is directional, all geometry's with toon
	shading applied will be shown always the same, like a billboard. On the
	other hand, if the main light is positional, the illumination render will
	take in consideration the light source position.
 */
class ToonShader
{
public:	
	~ToonShader();

	//! Returns the only instance of the Scene object.
	static ToonShader* getInstance();

	//! Initializes the shader-object
	bool init();

	//! Enables toon-shading rendering
	void enable();
	//! Disables toon-shading rendering
	void disable();

	//! Set's the color of the object being rendered
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
