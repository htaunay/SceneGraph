#include "Cube.h"
#include "Scene.h"
#include "Light.h"
#include "Camera.h"
#include "Entity.h"
#include "Material.h"

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
	camera->setZFar( 10 );
	camera->setFovy( 50);
	camera->setEye( 3, 3, 3 );
	camera->setCenter( 0, 0, 0 );
	camera->setUp( 0, 1, 0 );
	scene->addNode( camera );

	Light *light = new Light();

	light->setAmbient( 0.2, 0.2, 0.2, 1 );
	light->setDiffuse( 0.2, 0.2, 0.2, 1 );
	light->setSpecular( 0.2, 0.2, 0.2, 1 );
	light->setPosition( 0, 5, 0 );

	scene->addNode( light );
}

void generateTable()
{
	Material *material = new Material();
	material->setAmbient( 0, 1, 0, 1 );
	material->setDiffuse( 0, 1, 0, 1 );
	material->setSpecular( 0, 1, 0, 1 );
	material->setShineness( 1 );

	Cube *cube = new Cube( 2, 0.5, 2 );

	Entity *test = new Entity();
	test->setShape( cube );
	test->setMaterial( material );
	Scene::getInstance()->addNode(test);
}

static void redrawScene()
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable(GL_DEPTH_TEST);

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

	generateScene();
	generateTable();

	glutDisplayFunc( redrawScene );
	glutMainLoop();
}
