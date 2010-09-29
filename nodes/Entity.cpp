#include "Entity.h"

Entity::Entity()
{
	//empty
}

void Entity::render()
{
	_appearance->load();
	_shape->draw();
	_appearance->unLoad();
}
