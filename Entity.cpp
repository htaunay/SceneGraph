#include "Entity.h"

Entity::Entity()
{
	//empty
}

void Entity::render()
{
	_material->load();
	_shape->draw();
	_material->unload();
}
