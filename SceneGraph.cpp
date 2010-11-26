/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#include "GLee.h"
#include "Cube.h"
#include "Mesh.h"
#include "Group.h"
#include "Scene.h"
#include "Camera.h"
#include "Entity.h"
#include "Sphere.h"
#include "Utility.h"
#include "Environ.h"
#include "Texture.h"
#include "Cylinder.h"
#include "Material.h"
#include "Transform.h"
#include "SpotLight.h"
#include "SpherePool.h"
#include "ToonShader.h"
#include "PositionalLight.h"
#include "DirectionalLight.h"

void generateScene();
void generateTable();
void showScene( int argc, char* argv[] );

int main( int argc, char* argv[] )
{
	showScene( argc, argv );

	return 1;
}

void generateScene()
{
	Scene *scene = Scene::getInstance();

	Camera *camera = new Camera();
	camera->setZNear( 0.1 );
	camera->setZFar( 5000 );
	camera->setFovy( 50);
	camera->setEye( 10, 13, 10 );
	camera->setCenter( 0, 0, 0 );
	camera->setUp( 0, 1, 0 );
	scene->addNode( camera );

	Environ *environ = new Environ();
	environ->setFogDistance( 25.0, 50.0 );
	environ->setBgColor( 1.0, 1.0, 1.0 );
	scene->addNode( environ );
	environ->enableFog();

	DirectionalLight *dirLight = new DirectionalLight();
	dirLight->setAmbient( 0.2, 0.2, 0.2, 1 );
	dirLight->setDiffuse( 0.2, 0.2, 0.2, 1 );
	dirLight->setSpecular( 0.2, 0.2, 0.2, 1 );
	dirLight->setDirection( 0, 1, 1 );
	scene->addNode( dirLight );

	/*PositionalLight *posLight = new PositionalLight();
	posLight->setAmbient( 0.2, 0.2, 0.2, 1 );
	posLight->setDiffuse( 0.2, 0.2, 0.2, 1 );
	posLight->setSpecular( 0.2, 0.2, 0.2, 1 );
	posLight->setPosition( 0, 1, 1 );
	scene->addNode( posLight );*/
}

void generateTable()
{
	Material *recepientMaterial = new Material();
	recepientMaterial->setAmbient( 0, 0.2, 0.9, 0.1 );
	recepientMaterial->setDiffuse( 0, 0.2, 0.9, 0.1 );
	recepientMaterial->setSpecular( 0, 0.2, 0.9, 0.1 );

	//dummy
	Material *poolMaterial = new Material();

	Cube *recepientShape = new Cube( 5, 8, 5, 50 );
	SpherePool *poolShape = new SpherePool( 5, 7 );

	Entity *recepientEntity = new Entity();
	recepientEntity->setShape( recepientShape );
	recepientEntity->setAppearance( recepientMaterial );

	Entity *poolEntity = new Entity();
	poolEntity->setShape( poolShape );
	poolEntity->setAppearance( poolMaterial );

	Transform *root = new Transform();
	Scene::getInstance()->addNode( root );

	Transform *spherePool = new Transform();
	spherePool->addNode( poolEntity );
	root->addNode( spherePool );

	Transform *recepient = new Transform();
	recepient->translate( 0, 4, 0 );
	recepient->addNode( recepientEntity );
	root->addNode( recepient );
}

static void redrawScene()
{
	glEnable(GL_DEPTH_TEST | GL_LINE_SMOOTH );
	glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	Scene* scene = Scene::getInstance();

	scene->setupCamera();
	scene->setupLights();
	scene->render();

	glutSwapBuffers();
}

static void idle()
{
	redrawScene();
}

void showScene( int argc, char* argv[] )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
	glutInitWindowSize( 1200, 675 );
	glutCreateWindow( "SceneGraph" );

	ToonShader::getInstance()->init();

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glutSwapBuffers();

	glPolygonMode( GL_FRONT_AND_BACK,GL_FILL);

	generateScene();
	generateTable();

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc( redrawScene );
	glutIdleFunc( redrawScene );
	glutMainLoop();
}
