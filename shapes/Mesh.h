#ifndef _MESH_H_
#define _MESH_H_

#include "Shape.h"

#include <vector>
using std::vector;

typedef struct vertex
{
	double x;
	double y;
	double z;
} Vertex;

typedef struct triangle
{
	int v1;
	int v2;
	int v3;
} Triangle;

class Mesh : public Shape
{
public:
	void draw();

public:
	Mesh();

	~Mesh();

	bool loadGeometry( const char *filepath );

	void calculaNormal();

	void setScale( double x, double y, double z);

	bool scaleSet();

private:
	vector<Triangle> _listaTriangulos;//Lista de triangulos//

	vector<Vertex> _listaVertices;//Lista de vertices//
	vector<Vertex> _listaNormalFace;//Lista de normais de cada triangulo//

	Vertex _scale;


};
#endif
