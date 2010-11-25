/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"
#include "VVector.h"

#include <vector>

class PhysicsSphere
{
public:
	PhysicsSphere();

	inline void setPosition( VVector position ) { _position = position; }
	inline VVector getPosition() { return _position; }
	void generateRandPosition( float height, float width );

	inline void setMovement( VVector movement ) { _movement = movement; }
	inline VVector getMovement() { return _movement; }
	void generateRandMovement( float height, float width );
	void applyMovement( VVector movement );

	inline GLfloat* getColor() { return _color; }
	void generateRandColor();

	void applyGravity( float gravity );
	void applyMovementLoss( float loss );

private:
	GLfloat _color[4];
	VVector _movement;
	VVector _position;
};

//! Shape object in the from of a Sphere
class SpherePool : public Shape
{
public:
	//! TODO
	virtual void draw();

public:
	SpherePool( float width = 3, float height = 6 );

private:
	void step();

	void updateNumSpheres();

	void updateMovement();

	void updatePoolCollisions();

	void updateSphereCollisions();

	void updateRender();

private:
	float _width;
	float _height;
	float _gravity;

	float _sideLimit;
	float _floorLimit;

	std::vector<PhysicsSphere*> _spheres;
};
