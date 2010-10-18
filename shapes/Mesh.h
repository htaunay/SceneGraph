/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _MESH_H_
#define _MESH_H_

#include "Shape.h"
#include "VVector.h"

/*!
	Custom shape objet represented in the form of a tringle mesh. Meshes are
	read from a *.mesh file, containing a list of vertexes and vertex normals,
	as well as a list of tringles, using 3 of the previously defined vertexes.

	Mesh file format:

	- (int: numVertexes) (int: numTriangles)
	- (int: vertexIndex) (double: xpos) (double: ypos) (double: zpos) (double: xnormal) (double: ynormal) (double: znormal)
	- repeat numVertexes times
	- (int: triangleIndex) (int: vertex1index) (int: vertex2index) (int: vertex3index)
	- repeat numTriangles times
*/
class Mesh : public Shape
{
public:
	//! Draws a solid mesh object in the scene, with the origin at the 0,0,0
	//! positon of the objects boundingbox.
	virtual void draw();

public:
	//! Empty constructor
	Mesh() {};

	~Mesh();

	//! Loads the mesh file data to the Mesh object attributes.
	bool loadGeometry( const char* filepath );

private:
	int _numVertexes;
	int _numTriangles;

	unsigned int *_triangleList;
	VVector *_vertexList;
	VVector *_vertexNormalList;
};

#endif
