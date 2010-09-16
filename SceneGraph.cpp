#include "Cube.h"
#include "Group.h"
#include "Scene.h"
#include "Camera.h"
#include "Entity.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Material.h"
#include "Transform.h"
#include "SpotLight.h"
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
	camera->setZFar( 100 );
	camera->setFovy( 50);
	camera->setEye( 10, 10, 10 );
	camera->setCenter( 0, 0, 0 );
	camera->setUp( 0, 1, 0 );
	scene->addNode( camera );

	PositionalLight *posLight = new PositionalLight();

	posLight->setAmbient( 0.2, 0.2, 0.2, 1 );
	posLight->setDiffuse( 0.2, 0.2, 0.2, 1 );
	posLight->setSpecular( 0.2, 0.2, 0.2, 1 );
	posLight->setPosition( 0, 8, 0 );

	scene->addNode( posLight );

	/*DirectionalLight *dirLight = new DirectionalLight();

	dirLight->setAmbient( 0.2, 0.2, 0.2, 1 );
	dirLight->setDiffuse( 0.2, 0.2, 0.2, 1 );
	dirLight->setSpecular( 0.2, 0.2, 0.2, 1 );
	dirLight->setDirection( -1, 1, -1 );

	scene->addNode( dirLight );*/
}

void generateTable()
{
	SpotLight *spotLight = new SpotLight();
	spotLight->setAmbient( 0.0, 0.2, 0.0, 1 );
	spotLight->setDiffuse( 0.2, 1, 0.2, 1 );
	spotLight->setCutOff( 60 );
	spotLight->setExpoent( 16 );
	spotLight->setupAttenuation( 1, 0, 0 );

	Transform *table = new Transform();
	table->translate( 0, 2, 0 );
	Scene::getInstance()->addNode( table );

	Group *tableBase = new Group();
	table->addNode( tableBase );

	Material *woodMaterial = new Material();
	woodMaterial->setAmbient( 0.545, 0.27, 0.0745, 1 );
	woodMaterial->setDiffuse( 0.545, 0.27, 0.0745, 1 );
	woodMaterial->setSpecular( 0.1, 0.1, 0.1, 1 );
	woodMaterial->setShineness( 0.1 );

	Material *ballMaterial = new Material();
	ballMaterial->setAmbient( 0.698, 0.133, 0.133, 1 );
	ballMaterial->setDiffuse( 0.698, 0.133, 0.133, 1 );
	ballMaterial->setSpecular( 0.5, 0.5, 0.5, 1 );
	ballMaterial->setShineness( 0.8 );

	Material *cupMaterial = new Material();
	cupMaterial->setAmbient( 0.2549, 0.4117, 1, 1 );
	cupMaterial->setDiffuse( 1, 1, 1, 1 );
	cupMaterial->setSpecular( 0.2, 0.2, 0.2, 1 );
	cupMaterial->setShineness( 0.4 );

	Material *lampBaseMaterial = new Material();
	lampBaseMaterial->setAmbient( 0.3, 0.3, 0.3, 1 );
	lampBaseMaterial->setDiffuse( 1, 1, 1, 1 );
	lampBaseMaterial->setSpecular( 0.2, 0.2, 0.2, 1 );
	lampBaseMaterial->setShineness( 0.4 );

	Material *lampHeadMaterial = new Material();
	lampHeadMaterial->setAmbient( 0.5, 0.5, 0.5, 1 );
	lampHeadMaterial->setDiffuse( 1, 1, 1, 1 );
	lampHeadMaterial->setSpecular( 0.2, 0.2, 0.2, 1 );
	lampHeadMaterial->setShineness( 0.4 );

	Material *lampBulbMaterial = new Material();
	lampBulbMaterial->setAmbient( 0.8, 0.8, 0, 0.8 );
	lampBulbMaterial->setDiffuse( 0.8, 0.8, 0, 0.8 );
	lampBulbMaterial->setSpecular( 0.8, 0.8, 0, 1 );
	lampBulbMaterial->setShineness( 0.7 );

	Cube *tableTopShape = new Cube( 6, 0.5, 8 );
	Cube *tableFootShape = new Cube( 0.5, 4, 0.5 );
	Sphere *ballShape = new Sphere( 0.5 );
	Cylinder *cupShape = new Cylinder( 0.2, 0.2, 0.4 );
	Cylinder *lampBaseShape = new Cylinder( 0.75, 0.75, 0.2 );
	Cylinder *lampHasteShape = new Cylinder( 0.085, 0.085, 1.5 );
	Cylinder *lampHeadShape = new Cylinder( 0.05, 0.4, 0.6, false );
	Sphere *lampBulbShape = new Sphere( 0.15 );

	Entity *tableTopEntity = new Entity();
	tableTopEntity->setShape( tableTopShape );
	tableTopEntity->setMaterial( woodMaterial );

	Entity *tableFootEntity = new Entity();
	tableFootEntity->setShape( tableFootShape );
	tableFootEntity->setMaterial( woodMaterial );

	Entity *ballEntity = new Entity();
	ballEntity->setShape( ballShape );
	ballEntity->setMaterial( ballMaterial );

	Entity *cupEntity = new Entity();
	cupEntity->setShape( cupShape );
	cupEntity->setMaterial( cupMaterial );

	Entity *lampBaseEntity = new Entity();
	lampBaseEntity->setShape( lampBaseShape );
	lampBaseEntity->setMaterial( lampBaseMaterial );

	Entity *lampHasteEntity = new Entity();
	lampHasteEntity->setShape( lampHasteShape );
	lampHasteEntity->setMaterial( lampBaseMaterial );

	Entity *lampHeadEntity = new Entity();
	lampHeadEntity->setShape( lampHeadShape );
	lampHeadEntity->setMaterial( lampHeadMaterial );

	Entity *lampBulbEntity = new Entity();
	lampBulbEntity->setShape( lampBulbShape );
	lampBulbEntity->setMaterial( lampBulbMaterial );

	Transform *tableTop = new Transform();
	tableBase->addNode( tableTop );
	tableTop->addNode( tableTopEntity );

	Transform *tableFoot1 = new Transform();
	tableFoot1->translate( -2.75, -2.25, -3.75 );
	tableFoot1->addNode( tableFootEntity );
	tableBase->addNode( tableFoot1 );

	Transform *tableFoot2 = new Transform();
	tableFoot2->translate( -2.75, -2.25, 3.75 );
	tableFoot2->addNode( tableFootEntity );
	tableBase->addNode( tableFoot2 );

	Transform *tableFoot3 = new Transform();
	tableFoot3->translate( 2.75, -2.25, -3.75 );
	tableFoot3->addNode( tableFootEntity );
	tableBase->addNode( tableFoot3 );

	Transform *tableFoot4 = new Transform();
	tableFoot4->translate( 2.75, -2.25, 3.75 );
	tableFoot4->addNode( tableFootEntity );
	tableBase->addNode( tableFoot4 );

	Transform *ball = new Transform();
	ball->translate( -1.5, 0.75, 2 );
	ball->addNode( ballEntity );
	table->addNode( ball );

	Transform *cup = new Transform();
	cup->translate( -1.5, 0.75, -2 );
	cup->rotate( -90, 1, 0, 0 );
	cup->addNode( cupEntity );
	table->addNode( cup );

	Transform *lampBase = new Transform();
	lampBase->translate( 1.5, 0.75, -1.5 );
	lampBase->addNode( lampBaseEntity );
	lampBase->rotate( -90, 1, 0, 0 );
	table->addNode( lampBase );

	Transform *lampHaste1 = new Transform();
	lampHaste1->translate( 0, 0.2, 0 );
	lampHaste1->rotate( -30, 1, 0, 0 );
	lampHaste1->addNode( lampHasteEntity );
	lampBase->addNode( lampHaste1 );

	Transform *lampHaste2 = new Transform();
	lampHaste2->translate( 0, 0, 1.5 );
	lampHaste2->rotate( 60, 1, 0, 0 );
	lampHaste2->addNode( lampHasteEntity );
	lampHaste1->addNode( lampHaste2 );

	Transform *lampHead = new Transform();
	lampHead->translate( 0, -0.6, 1.5 );
	lampHead->rotate( -80, 1, 0, 0 );
	lampHead->addNode( lampHeadEntity );
	lampHaste2->addNode( lampHead );

	Transform *lampBulb = new Transform();
	lampBulb->translate( 0, 0, 0.1 );
	lampBulb->addNode( lampBulbEntity );
	lampHead->addNode( lampBulb );

	//spotLight->setPosition( 1, 2.35, -1.4 );
	//spotLight->setDirection( 0, 1, 1 );
	spotLight->setPosition( 1, 4, -1.5 );
	spotLight->setDirection( 0, -1, 1 );
	lampHead->addNode( spotLight );
}

static void redrawScene()
{
	glEnable(GL_DEPTH_TEST);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	Scene* scene = Scene::getInstance();

	scene->setupCamera();
	scene->setupLights();
	scene->render();

	glutSwapBuffers();
}

void showScene( int argc, char* argv[] )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
	glutInitWindowSize( 640, 480 );
	glutCreateWindow( "SceneGraph" );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glutSwapBuffers();

	generateScene();
	generateTable();

	glutDisplayFunc( redrawScene );
	glutMainLoop();
}
