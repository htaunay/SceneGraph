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
#include "Environ.h"
#include "Texture.h"
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
	camera->setZFar( 50 );
	camera->setFovy( 50);
	camera->setEye( 8, 8, 8 );
	camera->setCenter( 0, 0, 0 );
	camera->setUp( 0, 1, 0 );
	scene->addNode( camera );

	/*PositionalLight *posLight = new PositionalLight();
	posLight->setAmbient( 0.2, 0.2, 0.2, 1 );
	posLight->setDiffuse( 0.4, 0.4, 0.4, 1 );
	posLight->setSpecular( 0.4, 0.4, 0.4, 1 );
	posLight->setPosition( 0, 8, 0 );
	scene->addNode( posLight );*/

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
	SpotLight *spotLight = new SpotLight();
	spotLight->setAmbient( 0.8, 0.8, 0.2, 1 );
	spotLight->setDiffuse( 0.8, 0.8, 0.2, 1 );
	spotLight->setCutOff( 60 );
	spotLight->setExpoent( 64 );
	spotLight->setupAttenuation( 1, 0, 0 );

	Transform *table = new Transform();
	table->translate( 0, 2, 0 );
	Scene::getInstance()->addNode( table );

	Group *tableBase = new Group();
	table->addNode( tableBase );

	/*Material *woodMaterial = new Material();
	woodMaterial->setAmbient( 0.545, 0.27, 0.0745, 1 );
	woodMaterial->setDiffuse( 0.545, 0.27, 0.0745, 1 );
	woodMaterial->setSpecular( 0.1, 0.1, 0.1, 1 );
	woodMaterial->setShineness( 0.1 );*/

	Texture *floor_tex = new Texture();
	if( !floor_tex->LoadImage( 128, 128, "/media/Barcelona/PUC/PUC 2010.2/Computação Gráfica Tridimensional/SceneGraph/data/floor.raw" ) )
		exit(0);
	floor_tex->SetGenerateTextureCoord( true );
	floor_tex->SetTextureParameters();

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

	Material *bunnyMaterial = new Material();
	bunnyMaterial->setAmbient( 1, 1, 1, 1 );
	bunnyMaterial->setDiffuse( 1, 1, 1, 1 );
	bunnyMaterial->setSpecular( 1, 1, 1, 1 );
	bunnyMaterial->setShineness( 1 );

	Cube *tableTopShape = new Cube( 6, 0.5, 10 );
	Cube *tableFootShape = new Cube( 0.5, 4, 0.5 );
	Sphere *ballShape = new Sphere( 0.5 );
	Cylinder *cupShape = new Cylinder( 0.2, 0.2, 0.4 );
	Cylinder *lampBaseShape = new Cylinder( 0.75, 0.75, 0.2 );
	Cylinder *lampHasteShape = new Cylinder( 0.085, 0.085, 1.5 );
	Cylinder *lampHeadShape = new Cylinder( 0.05, 0.4, 0.6, false );
	Sphere *lampBulbShape = new Sphere( 0.15 );
	Mesh *bunnyShape = new Mesh();
	bunnyShape->loadGeometry( "/media/Barcelona/PUC/PUC 2010.2/Computação Gráfica Tridimensional/SceneGraph/data/bunny.msh" );

	Entity *tableTopEntity = new Entity();
	tableTopEntity->setShape( tableTopShape );
	tableTopEntity->setAppearance( floor_tex );

	Entity *tableFootEntity = new Entity();
	tableFootEntity->setShape( tableFootShape );
	tableFootEntity->setAppearance( floor_tex );

	Entity *ballEntity = new Entity();
	ballEntity->setShape( ballShape );
	ballEntity->setAppearance( ballMaterial );

	Entity *cupEntity = new Entity();
	cupEntity->setShape( cupShape );
	cupEntity->setAppearance( cupMaterial );

	Entity *lampBaseEntity = new Entity();
	lampBaseEntity->setShape( lampBaseShape );
	lampBaseEntity->setAppearance( lampBaseMaterial );

	Entity *lampHasteEntity = new Entity();
	lampHasteEntity->setShape( lampHasteShape );
	lampHasteEntity->setAppearance( lampBaseMaterial );

	Entity *lampHeadEntity = new Entity();
	lampHeadEntity->setShape( lampHeadShape );
	lampHeadEntity->setAppearance( lampHeadMaterial );

	Entity *lampBulbEntity = new Entity();
	lampBulbEntity->setShape( lampBulbShape );
	lampBulbEntity->setAppearance( lampBulbMaterial );

	Entity *bunnyEntity = new Entity();
	bunnyEntity->setShape( bunnyShape );
	bunnyEntity->setAppearance( bunnyMaterial );

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

	Transform *ball = new Transform();
	ball->translate( -1.5, 0.75, 2 );
	ball->addNode( ballEntity );
	table->addNode( ball );

	Transform *cup = new Transform();
	cup->translate( -1.5, 0.25, -2 );
	cup->rotate( -90, 1, 0, 0 );
	cup->addNode( cupEntity );
	table->addNode( cup );

	Transform *lampBase = new Transform();
	lampBase->translate( 1.5, 0.25, -1.5 );
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

	spotLight->setDirection( 0, 0, -1);
	spotLight->setPosition( 0, 0, 0 );
	lampBulb->addNode( spotLight );

	Transform *bunny = new Transform();
	bunny->translate( 0.8, 0.2, 1.5 );
	bunny->scale( 1.5, 1.5, 1.5 );
	bunny->addNode( bunnyEntity );
	table->addNode( bunny );
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
	glutMainLoop();
}
