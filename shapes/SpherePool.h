/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Shape.h"
#include "VVector.h"

#include <vector>

/*******************************************************************************
  Physics Sphere
*******************************************************************************/

/*!
	Sphere like object, that presents three properites: movement, postion and
	color (even though thiss class doenst handle any rendering). Its ment to
	be manipulated by the SpherePool class.
 */
class PhysicsSphere
{
public:
	//! Simple constructor, initializes the objects properties and random seed.
	PhysicsSphere();

	//! Sets the sphere's position.
	inline void setPosition( VVector position ) { _position = position; }
	//! Returns the sphere's positon.
	inline VVector getPosition() { return _position; }

	//! Generates a random positon, at the given height, between a square space
	//! of the given width.
	void generateRandPosition( float height, float width );

	//! Sets the sphere's movement value.
	inline void setMovement( VVector movement ) { _movement = movement; }
	//! Gets the sphere's movement value.
	inline VVector getMovement() { return _movement; }

	/*!
		Generates a random movement, normally used for defining a initial
		movement for a new PhysicsSphere. Uses the given height a value for
		generating reasonable intiial movement.
	 */
	void generateRandMovement( float height, float width );

	//! Applys a movement to the PhysicsSphere, changing its postion.
	void applyMovement( VVector movement );

	//! Returns the Sphere's current color.
	inline GLfloat* getColor() { return _color; }

	//! Generate's a random color for the Sphere.
	void generateRandColor();

	//! Applys a gravity force over the PhysicsSphere, changing it's current
	//! movement.
	void applyGravity( float gravity );

	//! Applys a movement loss over the PhysicsSphere, normally caused by a
	//! collision, changing it's current movement.
	void applyMovementLoss( float loss );

private:
	GLfloat _color[4];
	VVector _movement;
	VVector _position;
};

/*******************************************************************************
  Sphere Pool
*******************************************************************************/

/*!
	Object that simulates multiple elestic spheres falling/bouncing/colliding
	inside a cube shaped recepient(pool). Basically it works by itself, the user
	only defines the recepients height/width.
 */
class SpherePool : public Shape
{
public:
	/*!
		Updates the number of spheres in the scene, as well as their postions.
		After the final state of the frame is generated, this method also draws
		all the spheres in the scene.
	 */
	virtual void draw();

public:
	//! Creates a empty SpherePool, with the given width/height dimensions.
	SpherePool( float width = 3, float height = 6 );

private:
	// Performs all of the scenes updates
	void step();

	void updateFrameTime();

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

	int sphereCounter;
	std::vector<PhysicsSphere*> _spheres;

	float lastTime;
	float currentTime;
	float totalTime;
	float fps;
	unsigned int numFrames;
};
