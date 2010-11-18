/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

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
	camera->setZFar( 50 );
	camera->setFovy( 50);
	camera->setEye( 8, 8, 8 );
	camera->setCenter( 0, 0, 0 );
	camera->setUp( 0, 1, 0 );
	scene->addNode( camera );

	Environ *environ = new Environ();
	environ->setFogDistance( 25.0, 50.0 );
	scene->addNode( environ );
	environ->enableFog();

	DirectionalLight *dirLight = new DirectionalLight();
	dirLight->setAmbient( 0.2, 0.2, 0.2, 1 );
	dirLight->setDiffuse( 0.2, 0.2, 0.2, 1 );
	dirLight->setSpecular( 0.2, 0.2, 0.2, 1 );
	dirLight->setDirection( 0, 1, 1 );
	scene->addNode( dirLight );
}

void generateTable()
{
	Texture *tableTexture = new Texture();
	tableTexture->loadImage( "../data/wood.bmp" );
	tableTexture->setTextGenParameters();

	Texture *floorTexture = new Texture();
	floorTexture->loadImage( "../data/bricks.bmp" );
	floorTexture->setTextGenParameters();

	Material *poolMaterial = new Material();
	//poolMaterial->setAmbient( 1.0, 1.0, 1.0, 1.0 );
	poolMaterial->setDiffuse( 0.7, 0.7, 0.7, 1.0 );
	poolMaterial->setSpecular( 0.7, 0.7, 0.7, 1.0 );
	poolMaterial->setShineness( 0.7 );

	Cube *tableTopShape = new Cube( 6, 0.5, 10 );
	Cube *tableFootShape = new Cube( 0.5, 4, 0.5 );
	Cube *floorShape = new Cube( 10, 0.05, 14, 1 );
	SpherePool *poolShape = new SpherePool();

	Entity *tableTopEntity = new Entity();
	tableTopEntity->setShape( tableTopShape );
	tableTopEntity->setAppearance( tableTexture );

	Entity *tableFootEntity = new Entity();
	tableFootEntity->setShape( tableFootShape );
	tableFootEntity->setAppearance( tableTexture );

	Entity *floorEntity = new Entity();
	floorEntity->setShape( floorShape );
	floorEntity->setAppearance( floorTexture );

	Entity *poolEntity = new Entity();
	poolEntity->setShape( poolShape );
	poolEntity->setAppearance( poolMaterial );

	Transform *table = new Transform();
	table->translate( 0, 2, 0 );
	Scene::getInstance()->addNode( table );

	Group *tableBase = new Group();
	table->addNode( tableBase );

	Transform *tableTop = new Transform();
	tableBase->addNode( tableTop );
	tableTop->addNode( tableTopEntity );

	Transform *tableFoot1 = new Transform();
	tableFoot1->translate( -2.75, -2.25, -4.75 );
	tableFoot1->addNode( tableFootEntity );
	tableBase->addNode( tableFoot1 );

	Transform *tableFoot2 = new Transform();
	tableFoot2->translate( -2.75, -2.25, 4.75 );
	tableFoot2->addNode( tableFootEntity );
	tableBase->addNode( tableFoot2 );

	Transform *tableFoot3 = new Transform();
	tableFoot3->translate( 2.75, -2.25, -4.75 );
	tableFoot3->addNode( tableFootEntity );
	tableBase->addNode( tableFoot3 );

	Transform *tableFoot4 = new Transform();
	tableFoot4->translate( 2.75, -2.25, 4.75 );
	tableFoot4->addNode( tableFootEntity );
	tableBase->addNode( tableFoot4 );

	Transform *floor = new Transform();
	floor->translate( 0, -4.25, 0 );
	floor->addNode( floorEntity );
	table->addNode( floor );

	Transform *spherePool = new Transform();
	spherePool->translate( 0, 0.25, 0 );
	spherePool->addNode( poolEntity );
	tableBase->addNode( spherePool );
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
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glutSwapBuffers();

	glPolygonMode(GL_FRONT,GL_FILL);

	generateScene();
	generateTable();

	glutDisplayFunc( redrawScene );
	glutIdleFunc( redrawScene );
	glutMainLoop();
}
