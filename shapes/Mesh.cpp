/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include <GL/gl.h>
#include <stdlib.h>

#include "Mesh.h"

void Mesh::draw()
{
	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );

	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_NORMAL_ARRAY );

		glNormalPointer(    GL_FLOAT, 0, _vertexNormalList );
		glVertexPointer( 3, GL_FLOAT, 0, _vertexList );

		glDrawElements( GL_TRIANGLES, _numTriangles*3, GL_UNSIGNED_INT, _triangleList );

	glPopClientAttrib();
}

Mesh::~Mesh()
{
	delete _triangleList;
	delete _vertexList;
	delete _vertexNormalList;
}

bool Mesh::loadGeometry( const char* filepath )
{
	// Opens mesh file.
	FILE * file = fopen(filepath, "rt");

	if( file == NULL )
	{
		printf("Error - open file: %s\n\n", filepath);
		delete _vertexList;
		delete _triangleList;
		return false;
	}

	// Reads the number of triangles and vertexes available in the file, and
	// initializes the class attributes accordingly.
	fscanf( file, "%d %d", &_numVertexes, &_numTriangles );

	_vertexList = new VVector[_numVertexes];
	_triangleList = new unsigned int[_numTriangles*3];
	_vertexNormalList = new VVector[_numVertexes];

	int dummy, i;

	// Loads all of the mesh data to the class attributes.
	for( i = 0; i < _numVertexes; i++ )
		fscanf( file, "%d %f %f %f %f %f %f", &dummy, &_vertexList[i].x, &_vertexList[i].y, &_vertexList[i].z,
									&_vertexNormalList[i].x, &_vertexNormalList[i].y, &_vertexNormalList[i].z );

	for( i = 0; i < ( _numTriangles*3 ); i+=3 )
		fscanf( file, "%d %d %d %d", &dummy, &_triangleList[i], &_triangleList[i+1], &_triangleList[i+2] );

	return true;
}
