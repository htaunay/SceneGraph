/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "ToonShader.h"
#include "Utility.h"
#include "SpherePool.h"

#include "glut.h"
#include <math.h>
#include <time.h>
#include <cstdlib>

static const int	NUM_SPHERES		= 75;
static const float	SPHERE_RADIUS	= 0.45;
static const float	DEFAULT_SOLID_LOSS	= 1.5;
static const float	DEFAULT_SPHERE_LOSS	= 0.1;
static const float	DEFAULT_GRAVITY	= 0.05;
static const float	MOVEMENT_THREASHOLD = 0.05;

VVector auxPos;
VVector auxMov;
GLfloat* auxColor;
PhysicsSphere *auxSph;

float lastTime         = 0.0;
float currentTime      = 0.0;
float diffTime         = 0.0;
float totalTime        = 0.0;
float fps			   = 0.0;
unsigned int numFrames = 0;

float sphereCounter = 0.0;

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

void PhysicsSphere::generateRandMovement( float height, float width )
{
	srand((unsigned)time(NULL) * rand() );
	float x = ( rand() % ((int)width*100) )/100.0 - ( width/2.0 );

	srand((unsigned)time(NULL) * rand() );
	float z = ( rand() % ((int)width*100) )/100.0 - ( width/2.0 );

	_movement.x = x/5;
	_movement.z = z/5;
	_movement.y = height/100;
}

void PhysicsSphere::applyGravity( float gravity )
{
	_movement.y -= ( gravity * (diffTime/30.0) );
}

void PhysicsSphere::applyMovement( VVector movement )
{
	_position.x += ( movement.x * (diffTime/30.0) );
	_position.y += ( movement.y * (diffTime/30.0) );
	_position.z += ( movement.z * (diffTime/30.0) );
}

void PhysicsSphere::applyMovementLoss( float loss )
{
	float nloss = 1 - ( loss * (diffTime/30.0) );
	_movement.x *= nloss;
	_movement.y *= nloss;
	_movement.z *= nloss;

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

	_sideLimit = ( _width/2.0 ) - SPHERE_RADIUS - 0.05;
	_floorLimit = SPHERE_RADIUS;
}

void SpherePool::draw()
{
	step();
}

void SpherePool::step()
{
	currentTime = glutGet( GLUT_ELAPSED_TIME );
	diffTime = currentTime - lastTime;
	lastTime = currentTime;
	totalTime += diffTime;
	sphereCounter += diffTime;
	numFrames++;

	if( totalTime > 1000 )
	{
		fps = (numFrames * 1000.0)/( totalTime );
		totalTime = 0;
		numFrames = 0;
		printf( "FPS: %f\n", fps, diffTime );
	}

	updateNumSpheres();
	updateMovement();
	updatePoolCollisions();
	updateSphereCollisions();
	updateRender();
}

void SpherePool::updateNumSpheres()
{
	if( sphereCounter > 500 )
		sphereCounter = 0.0;
	else
		return;

	// Create new PhysicsSphere
	if( _spheres.size() < NUM_SPHERES )
	{
		PhysicsSphere* ps = new PhysicsSphere();
		ps->generateRandColor();
		ps->generateRandPosition( _height, _width );
		ps->generateRandMovement( _height, _width );
		//ps->setPosition( 0, _height, 0 );

		_spheres.push_back( ps );
	}
}

void SpherePool::updateMovement()
{
	for( int i = 0; i < _spheres.size(); i++ )
	{
		auxSph = _spheres.at(i);
		auxSph->applyGravity( DEFAULT_GRAVITY );

		auxPos = auxSph->getPosition();
		auxMov = auxSph->getMovement();

		auxSph->applyMovement( auxMov );
		//auxSph->setPosition( auxPos );
	}
}

void SpherePool::updatePoolCollisions()
{
	bool collisionDetected;

	for( int i = 0; i < _spheres.size(); i++ )
	{
		auxSph = _spheres.at(i);
		auxPos = auxSph->getPosition();
		auxMov = auxSph->getMovement();

		collisionDetected = false;

		if( auxPos.x > _sideLimit )
		{
			auxPos.x = _sideLimit;
			auxMov.x *= -1;
			collisionDetected = true;
		}
		if( auxPos.x < -(_sideLimit) )
		{
			auxPos.x = -(_sideLimit);
			auxMov.x *= -1;
			collisionDetected = true;
		}

		if( auxPos.y < _floorLimit )
		{
			auxPos.y = _floorLimit;
			auxMov.y *= -1;
			collisionDetected = true;
		}

		if( auxPos.z > _sideLimit )
		{
			auxPos.z = _sideLimit;
			auxMov.z *= -1;
			collisionDetected = true;
		}
		if( auxPos.z < -(_sideLimit) )
		{
			auxPos.z = -(_sideLimit);
			auxMov.z *= -1;
			collisionDetected = true;
		}

		auxSph->setPosition( auxPos );
		auxSph->setMovement( auxMov );

		if( collisionDetected )
			auxSph->applyMovementLoss( DEFAULT_SOLID_LOSS );
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

					// Switches spheres directions/speeds
					VVector dir2 = distance;
					dir2.Normalize();
					VVector dir1 = dir2;
					dir1.invert();

					VVector mov1 = sphere1->getMovement();
					VVector mov2 = sphere2->getMovement();

					float speed1 = mov1.Length();
					float speed2 = mov2.Length();

					dir1 *= speed1;
					dir2 *= speed2;

					sphere1->setMovement( dir2 );
					sphere2->setMovement( dir1 );

					double loss = DEFAULT_SPHERE_LOSS / (_spheres.size()*_spheres.size());
					sphere1->applyMovementLoss( loss );
					sphere2->applyMovementLoss( loss );
				}
			}
		}
	}
}

void SpherePool::updateRender()
{
	ToonShader::getInstance()->enable();

	for( int i = 0; i < _spheres.size(); i++ )
	{
		auxSph = _spheres.at(i);
		auxPos = auxSph->getPosition();
		auxColor = auxSph->getColor();

		ToonShader::getInstance()->setColor( auxColor );

		glPushAttrib(GL_LIGHTING_BIT);
		glColor3f( auxColor[0], auxColor[1], auxColor[2] );
		glMaterialfv( GL_FRONT, GL_AMBIENT, auxColor );
		glPushMatrix();
		glTranslatef( auxPos.x, auxPos.y, auxPos.z );
		glutSolidSphere( SPHERE_RADIUS, 64, 64 );
		glPopMatrix();
		glPopAttrib();
	}

	ToonShader::getInstance()->disable();
}
