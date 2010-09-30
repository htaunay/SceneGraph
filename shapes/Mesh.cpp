#include "gl.h"
#include <math.h>
#include <stdio.h>
#include "Mesh.h"
#include "Utility.h"

Mesh::Mesh()
{
	_scale.x = 0;
	_scale.y = 0;
	_scale.z = 0;
}

Mesh::~Mesh()
{
	// empty
}

bool Mesh::loadGeometry( const char *filepath )
{
	FILE *meshFile = fopen( filepath, "rt" );

	if( meshFile == NULL )
		return false;

	int num; //dummy
	int numVertexes, numTriangles;
	fscanf( meshFile, "%d %d", &numVertexes, &numTriangles );

	int i;
	Vertex v;
	for( i = 0; i < numVertexes; i++ )
	{
		fscanf( meshFile, "%d %lf %lf %lf", &num, &v.x, &v.y, &v.z );
		v.x *= 12;
		v.y *= 12;
		v.z *= 12;
		_listaVertices.push_back( v );
	}

	Triangle t;
	for( i = 0; i < numTriangles; i++ )
	{
		fscanf( meshFile, "%d %d %d %d", &num, &t.v1, &t.v2, &t.v3 );
		_listaTriangulos.push_back( t );
	}

	calculaNormal();
	return true;
}


void Mesh::calculaNormal()
{
	int i;
	double factor;
	Vertex aux, normal;
	Vertex vertex1, vertex2, vertex3;
	Vertex mid1, mid2;
	Triangle t;

	/*for( i = 0; i < _listaVertices.size(); i++ )
	{
		aux.x = aux.y = aux.z = 0;
		_listaNormalVertice.push_back( aux );
	}*/

	for( i = 0; i < _listaTriangulos.size(); i ++ )
	{
		// olhar slide!!!
		t.v1 = _listaTriangulos.at(i).v1;
		t.v2 = _listaTriangulos.at(i).v2;
		t.v3 = _listaTriangulos.at(i).v3;

		vertex1 = _listaVertices.at( t.v1 );
		vertex2 = _listaVertices.at( t.v2 );
		vertex3 = _listaVertices.at( t.v3 );

		mid1.x = vertex1.x - vertex2.x;		mid2.x = vertex2.x - vertex3.x;
		mid1.y = vertex1.y - vertex2.y;		mid2.y = vertex2.y - vertex3.y;
		mid1.z = vertex1.z - vertex2.z;		mid2.z = vertex2.z - vertex3.z;

		normal.x = ( vertex1.y * vertex2.z ) - ( vertex1.z * vertex2.y );
		normal.y = ( vertex1.z * vertex2.x ) - ( vertex1.x * vertex2.z );
		normal.z = ( vertex1.x * vertex2.y ) - ( vertex1.y * vertex2.x );

		double length = sqrt( normal.x * normal.x +
							  normal.y * normal.y +
							  normal.z * normal.z );

		if( length != 0 )
		{
			factor = 1.0/length;
			normal.x *= factor;
			normal.y *= factor;
			normal.z *= factor;
		}

		_listaNormalFace.push_back( normal );
	}
}

void Mesh::setScale(double x, double y, double z)
{
	_scale.x = x;
	_scale.y = y;
	_scale.z = z;
	glScaled( x, y, z );
}

bool Mesh::scaleSet()
{
	if( _scale.x = 0 && _scale.y == 0 && _scale.z == 0 )
		return false;

	return true;
}

void Mesh::draw()
{
	glBegin( GL_TRIANGLES );

	int i;
	Triangle t;
	Vertex v;
	for( i = 0; i < _listaTriangulos.size(); i++ )
	{
		v = _listaNormalFace.at(i);
		glNormal3f( v.x, v.y, v.z );

		t = _listaTriangulos.at(i);

		glVertex3f( _listaVertices.at( t.v1 ).x,
					_listaVertices.at( t.v1 ).y,
					_listaVertices.at( t.v1 ).z );

		glVertex3f( _listaVertices.at( t.v2 ).x,
					_listaVertices.at( t.v2 ).y,
					_listaVertices.at( t.v2 ).z );

		glVertex3f( _listaVertices.at( t.v3 ).x,
					_listaVertices.at( t.v3 ).y,
					_listaVertices.at( t.v3 ).z );

	}
	glEnd();
}
