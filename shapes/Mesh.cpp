#include "gl.h"
#include <stdlib.h>

#include "Vector.h"
#include "Mesh.h"

void Mesh::draw()
{
	/*glBegin(GL_TRIANGLES);
	for(int i = 0, j = 0; i < _numTriangles*3; i++, j++)
	{
		glNormal3f( _faceNormalList[j].x, _faceNormalList[j].y, _faceNormalList[j].z );
		glVertex3f( _vertexList[_triangleList[i]].x, _vertexList[_triangleList[i]].y, _vertexList[_triangleList[i]].z ); i++;
		glVertex3f( _vertexList[_triangleList[i]].x, _vertexList[_triangleList[i]].y, _vertexList[_triangleList[i]].z ); i++;
		glVertex3f( _vertexList[_triangleList[i]].x, _vertexList[_triangleList[i]].y, _vertexList[_triangleList[i]].z );
	}
	glEnd();*/

	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );

	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_NORMAL_ARRAY );

		glNormalPointer(    GL_FLOAT, 0, _vertexNormalList );
		glVertexPointer( 3, GL_FLOAT, 0, _vertexList );

		glDrawElements( GL_TRIANGLES, _numTriangles*3, GL_UNSIGNED_INT, _triangleList );

	glPopClientAttrib();
}

Mesh::Mesh()
{
	//empty
}

Mesh::~Mesh()
{
	delete _faceNormalList;
	delete _triangleList;
	delete _vertexList;
	delete _vertexNormalList;
}

bool Mesh::loadGeometry( const char* filepath )
{
	FILE * file = fopen(filepath, "rt");

	if( file == NULL )
	{
		printf("Error - open file: %s\n\n", filepath);
		delete _vertexList;
		delete _triangleList;
		delete _faceNormalList;
		return false;
	}

	fscanf( file, "%d %d", &_numVertexes, &_numTriangles );

	_vertexList = new VVector[_numVertexes];
	_triangleList = new unsigned int[_numTriangles*3];
	_faceNormalList = new VVector[_numTriangles];
	_vertexNormalList = new VVector[_numVertexes];

	int dummy, i;

	for( i = 0; i < _numVertexes; i++ )
		fscanf( file, "%d %f %f %f %f %f %f", &dummy, &_vertexList[i].x, &_vertexList[i].y, &_vertexList[i].z,
									&_vertexNormalList[i].x, &_vertexNormalList[i].y, &_vertexNormalList[i].z );

	for( i = 0; i < ( _numTriangles*3 ); i+=3 )
		fscanf( file, "%d %d %d %d", &dummy, &_triangleList[i], &_triangleList[i+1], &_triangleList[i+2] );

	//defineFaceNormals();
	//defineVertexNormals();

	return true;
}

void Mesh::defineFaceNormals()
{
	VVector v0, v1;
	VVector p1, p2, p3;
	VVector normal;
	int qtd_cont = 0;

	int i, j;
	for( i = 0, j = 0; i < _numTriangles*3; i += 3, j++ )
	{
		p1 = _vertexList[_triangleList[i]];
		p2 = _vertexList[_triangleList[i+1]];
		p3 = _vertexList[_triangleList[i+2]];

		v0.Set(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
		v1.Set(p2.x - p3.x, p2.y - p3.y, p2.z - p3.z);

		normal = Cross(v0, v1);
		normal.Normalize();

		_faceNormalList[j] = normal;
	}
}

void Mesh::defineVertexNormals()
{
	int i, j;
	for( i = 0, j = 0; i < _numTriangles*3; i++, j++ )
	{
		_vertexNormalList[_triangleList[i]] = _faceNormalList[j]; i++;
		_vertexNormalList[_triangleList[i]] = _faceNormalList[j]; i++;
		_vertexNormalList[_triangleList[i]] = _faceNormalList[j];
	}
}

void Mesh::scale( float x, float y, float z )
{
	for( int i = 0; i < _numVertexes; i++ )
	{
		_vertexList[i].x *= x;
		_vertexList[i].y *= y;
		_vertexList[i].z *= z;
	}
}
