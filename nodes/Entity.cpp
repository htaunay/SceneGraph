#include "Entity.h"

Entity::Entity()
{
	_appearance = NULL;
	_shape = NULL;
}

void Entity::render()
{
	_appearance->load();
	_shape->draw();
	_appearance->unLoad();
}
