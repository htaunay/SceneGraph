/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "ToonShader.h"
#include "Utility.h"

const char* vertex_source = {
"varying vec3 normal;"
"varying vec3 lightDir;"
""
"void main(){"
"  normal = gl_NormalMatrix * gl_Normal;"
"  vec3 vVertex = vec3(gl_ModelViewMatrix * gl_Vertex);"
"  lightDir = vec3(gl_LightSource[0].position.xyz - vVertex);"
"  gl_Position = ftransform();"
"}"
};


const char* fragment_source = {
"varying vec3 normal;"
"varying vec3 lightDir;"
"uniform vec4 color;"
""
"void main(void){"
"   float intensity;"
"   vec4 ncolor;"
"   vec3 n = normalize(normal);"
"   vec3 normLightDir = normalize(lightDir);"
"   intensity = dot(normLightDir,n);"
"   int newIntensity = int(intensity*4);"
"   float finalIntensity = newIntensity/4.0;"
"   if( finalIntensity < 0.1 )"
"		finalIntensity = 0;"
"	ncolor = vec4(color[0]*finalIntensity,color[1]*finalIntensity,color[2]*finalIntensity,color[3]);"
""
"   gl_FragColor = ncolor;"
"}"
};

ToonShader* ToonShader::_instance = NULL;

ToonShader* ToonShader::getInstance()
{
	if( _instance == NULL )
		_instance = new ToonShader();

	return _instance;
}

ToonShader::~ToonShader()
{
	glDetachShader( program_object, vertex_shader );
	glDetachShader( program_object, fragment_shader );

	glDeleteShader( vertex_shader );
	glDeleteShader( fragment_shader );

	glDeleteProgram( program_object );

	delete _instance;
	_instance = NULL;
}

void ToonShader::enable(void)
{
	if( _hasProgram )
		glUseProgram( program_object );
}

void ToonShader::disable(void)
{
	glUseProgram(0);
}

bool ToonShader::init()
{
	// creating the program and shaders
	program_object  = glCreateProgram();
	vertex_shader   = glCreateShader( GL_VERTEX_SHADER );
	fragment_shader = glCreateShader( GL_FRAGMENT_SHADER );

	// setting the shdares sources
	glShaderSource( vertex_shader,	1, &vertex_source,	 NULL );
	glShaderSource( fragment_shader, 1, &fragment_source, NULL );

	// compiling and attaching the vertex shader onto program
	glCompileShader( vertex_shader );
	glAttachShader( program_object, vertex_shader );

	// compiling and attaching the fragment shader onto program
	glCompileShader( fragment_shader );
	glAttachShader( program_object, fragment_shader );

	// Link the shaders into a complete GLSL program.
	glLinkProgram( program_object );

	// exporting variables to GPU
	float normal[3];
	GLint normalLoc = glGetAttribLocation( program_object, "normal" );
	glVertexAttrib3fv( normalLoc, normal );

	float lightDir[3];
	GLint lightDirLoc = glGetAttribLocation( program_object, "lightDir" );
	glVertexAttrib3fv( lightDirLoc, lightDir );

	_hasProgram = true;
	return true;
}

void ToonShader::setColor( GLfloat* color )
{
	Utility::copyVectorgf( color, _color, 4 );
	GLint colorLoc = glGetUniformLocation( program_object, "color" );
	glUniform4fv( colorLoc, 1, _color );
}

ToonShader::ToonShader()
{
	_hasProgram = false;
	Utility::initVectorf( _color, 4, 1 );
}
