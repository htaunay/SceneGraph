/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Node.h"
#include "Shape.h"
#include "Appearance.h"

/*!
	Represents an object in the Scene. At the moment, an Entity object contains
	a Shape and a Apperance, and is usually set as a child of Transform nodes,
	where the Transform father would define the position, orientation, etc, of
	the object, and the Entity defines the visual aspects of the object.
 */
class Entity : public Node
{
public:
	//! Method inherited from Node object and implemented according to the
	//! Entity specifications.
	virtual void render();

	// Methods inherited by Node object. No changes.
	virtual inline int setupCamera() { return 1; }
	virtual inline int setupLights() { return 1; }

public:
	//! Constructor that initializes all of Entity's attributes.
	Entity();

	//! Set's the Entity's encapsulated Shape object.
	void inline setShape( Shape *shape ) { _shape = shape; }

	//! Set's the Entity's encapsulated Appearance object.
	void inline setAppearance( Appearance *appearance ) { _appearance = appearance; }

protected:
	Shape *_shape;
	Appearance *_appearance;
};

#endif
