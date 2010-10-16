/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

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
