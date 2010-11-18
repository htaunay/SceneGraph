/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "Utility.h"
#include "SpherePool.h"

#include "glut.h"
#include <math.h>
#include <time.h>
#include <cstdlib>

static const int	NUM_SPHERES		= 30;
static const float	SPHERE_RADIUS	= 0.25;
static const float	DEFAULT_LOSS	= 0.8;
static const float	DEFAULT_GRAVITY	= 0.005;
static const float	MOVEMENT_THREASHOLD = 0.0001;

/*******************************************************************************
  Physics Sphere
*******************************************************************************/

PhysicsSphere::PhysicsSphere()
{
	Utility::initVectorgf( _color, 3, 0.0 );

	_movement.Set( 0, 0, 0 );
	_position.Set( 0, 0, 0 );

	srand((unsigned)time(NULL));
}

void PhysicsSphere::generateRandColor()
{
	for( int i = 0; i < 3; i++ )
	{
		srand((unsigned)time(NULL)*rand());
		_color[i] = ( rand() % 256 )/256.0;
	}
	_color[3] = 1.0;
}

void PhysicsSphere::generateRandPosition( float height, float width )
{
	srand((unsigned)time(NULL) * rand() );
	float x = ( rand() % ((int)width*100) )/100.0 - ( width/2.0 );

	srand((unsigned)time(NULL) * rand() );
	float z = ( rand() % ((int)width*100) )/100.0 - ( width/2.0 );

	_position.x = x;
	_position.z = z;
	_position.y = height;
}

void PhysicsSphere::setPosition( float x, float y, float z )
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

void PhysicsSphere::setMovement( float x, float y, float z )
{
	_movement.x = x;
	_movement.y = y;
	_movement.z = z;
}

void PhysicsSphere::applyGravity( float gravity )
{
	_movement.y -= gravity;
}

void PhysicsSphere::applyMovementLoss( float loss )
{
	_movement.x *= DEFAULT_LOSS;
	_movement.y *= DEFAULT_LOSS;
	_movement.z *= DEFAULT_LOSS;

	if( Utility::abs( _movement.x ) < MOVEMENT_THREASHOLD )
		_movement.x = 0.0;

	if( Utility::abs( _movement.y ) < MOVEMENT_THREASHOLD )
		_movement.y = 0.0;

	if( Utility::abs( _movement.z ) < MOVEMENT_THREASHOLD )
		_movement.z = 0.0;
}

/*******************************************************************************
  Sphere Pool
*******************************************************************************/

SpherePool::SpherePool( float width, float height )
{
	_width = width;
	_height = height;

	_gravity = DEFAULT_GRAVITY;

	_sideLimit = ( _width/2.0 ) - SPHERE_RADIUS;
	_floorLimit = SPHERE_RADIUS;
}

void SpherePool::draw()
{
	updateNumSpheres();
	updateMovement();
	updatePoolCollisions();
	updateSphereCollisions();
	updateRender();
}

int counter = 0;
void SpherePool::updateNumSpheres()
{
	counter++;

	if( counter == 50 )
		counter = 0;
	else
		return;

	// Create new PhysicsSphere
	if( _spheres.size() < NUM_SPHERES )
	{
		PhysicsSphere* ps = new PhysicsSphere();
		ps->generateRandColor();
		ps->generateRandPosition( _height, _width );
		//ps->setPosition( 0, _height, 0 );

		_spheres.push_back( ps );
	}
}

void SpherePool::updateMovement()
{
	PhysicsSphere* aux;

	for( int i = 0; i < _spheres.size(); i++ )
	{
		aux = _spheres.at(i);

		aux->applyGravity( DEFAULT_GRAVITY );

		aux->setPosX( aux->getPosX() + aux->getMovX() );
		aux->setPosY( aux->getPosY() + aux->getMovY() );
		aux->setPosZ( aux->getPosZ() + aux->getMovZ() );
	}
}

void SpherePool::updatePoolCollisions()
{
	bool collisionDetected;
	PhysicsSphere* aux;

	for( int i = 0; i < _spheres.size(); i++ )
	{
		aux = _spheres.at(i);
		collisionDetected = false;

		if( aux->getPosX() > _sideLimit )
		{
			aux->setPosX( _sideLimit );
			aux->setMovX( -aux->getMovX() );
			collisionDetected = true;
		}
		if( aux->getPosX() < (-_sideLimit) )
		{
			aux->setPosX( (-_sideLimit) );
			aux->setMovX( -aux->getMovX() );
			collisionDetected = true;
		}

		if( aux->getPosY() < _floorLimit )
		{
			aux->setPosY( _floorLimit );
			aux->setMovY( -aux->getMovY() );
			collisionDetected = true;
		}

		if( aux->getPosZ() > _sideLimit )
		{
			aux->setPosZ( _sideLimit );
			aux->setMovZ( -aux->getMovZ() );
			collisionDetected = true;
		}
		if( aux->getPosZ() < (-_sideLimit) )
		{
			aux->setPosZ( (-_sideLimit) );
			aux->setMovZ( -aux->getMovZ() );
			collisionDetected = true;
		}

		if( collisionDetected )
			aux->applyMovementLoss( DEFAULT_LOSS );
	}
}

void SpherePool::updateSphereCollisions()
{
	PhysicsSphere  *sphere1, *sphere2;

	for( int i = 0; i < _spheres.size(); i++ )
	{
		for( int j = i+1; j < _spheres.size(); j++ )
		{
			if( i != j )
			{
				sphere1 = _spheres.at(i);
				sphere2 = _spheres.at(j);

				VVector pos1 = sphere1->getPosition();
				VVector pos2 = sphere2->getPosition();

				VVector distance = pos1; distance -= pos2;

				if( distance.Length() < ( 2*SPHERE_RADIUS ) )
				{
					// Removes the invasion between two spheres
					VVector invasion = distance;
					float diff = ( ( 2*SPHERE_RADIUS ) - invasion.Normalize() );

					invasion *= diff;
					invasion *= 0.5f;

					pos1 += invasion; sphere1->setPosition( pos1 );
					pos2 -= invasion; sphere2->setPosition( pos2 );

					VVector mov1 = sphere1->getMovement();
					VVector mov2 = sphere2->getMovement();

					mov1 *= DEFAULT_LOSS;
					mov2 *= DEFAULT_LOSS;

					sphere1->setMovement( mov2 );
					sphere2->setMovement( mov1 );
				}
			}
		}
	}
}

void SpherePool::updateRender()
{
	PhysicsSphere* aux;

	for( int i = 0; i < _spheres.size(); i++ )
	{
		aux = _spheres.at(i);

		glPushAttrib(GL_LIGHTING_BIT);
		glColor3f( aux->getColorR(), aux->getColorG(), aux->getColorB() );
		glMaterialfv( GL_FRONT, GL_AMBIENT, aux->getColor() );
		glPushMatrix();
		glTranslatef( aux->getPosX(), aux->getPosY(), aux->getPosZ() );
		glutSolidSphere( SPHERE_RADIUS, 64, 64 );
		glPopMatrix();
		glPopAttrib();
	}
}
