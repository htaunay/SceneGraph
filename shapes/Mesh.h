/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _MESH_H_
#define _MESH_H_

#include "Shape.h"
#include "VVector.h"

class Mesh : public Shape
{
public:
	virtual void draw();

public:
	Mesh();

	~Mesh();

	bool loadGeometry( const char* filepath );

	void defineFaceNormals();

	void defineVertexNormals();

	void scale( float x, float y, float z );

private:
	int _numVertexes;
	int _numTriangles;

	unsigned int *_triangleList;
	VVector *_vertexList;
	VVector *_faceNormalList;
	VVector *_vertexNormalList;
};

#endif
