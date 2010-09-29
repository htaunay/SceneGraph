#include "Group.h"

Group::Group()
{
	//empty
}

int Group::setupCamera()
{
	for( int i = 0; i < _children.size(); i++ )
	{
		_children[i]->setupCamera();
	}

	return 1;
}

int Group::setupLights()
{
	for( int i = 0; i < _children.size(); i++ )
	{
		_children[i]->setupLights();
	}

	return 1;
}

void Group::render()
{
	for( int i = 0; i < _children.size(); i++ )
	{
		_children[i]->render();
	}
}

bool Group::addNode( Node* newNode )
{
	_children.push_back( newNode );

	return true;
}
