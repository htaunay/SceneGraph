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

	inline float getPosX() { return _position.x; }
	inline float getPosY() { return _position.y; }
	inline float getPosZ() { return _position.z; }

	inline void setPosX( float x ) { _position.x = x; }
	inline void setPosY( float y ) { _position.y = y; }
	inline void setPosZ( float z ) { _position.z = z; }

	void setPosition( float x, float y, float z );
	inline void setPosition( VVector position ) { _position = position; }
	inline VVector getPosition() { return _position; }

	void generateRandPosition( float height, float width );

	inline float getMovX() { return _movement.x; }
	inline float getMovY() { return _movement.y; }
	inline float getMovZ() { return _movement.z; }

	inline void setMovX( float x ) { _movement.x = x; }
	inline void setMovY( float y ) { _movement.y = y; }
	inline void setMovZ( float z ) { _movement.z = z; }

	void setMovement( float x, float y, float z );
	inline void setMovement( VVector movement ) { _movement = movement; }
	inline VVector getMovement() { return _movement; }

	void applyGravity( float gravity );

	void applyMovementLoss( float loss );

	inline GLfloat getColorR() { return _color[0]; }
	inline GLfloat getColorG() { return _color[1]; }
	inline GLfloat getColorB() { return _color[2]; }

	inline GLfloat* getColor() { return _color; }

	void generateRandColor();

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
