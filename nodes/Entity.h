#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Node.h"
#include "Shape.h"
#include "Appearance.h"

class Entity : public Node
{
public:
	virtual inline int setupCamera() { return 1; }

	virtual inline int setupLights() { return 1; }

	virtual void render();

public:
	Entity();

	void inline setShape( Shape *shape ) { _shape = shape; }

	void inline setAppearance( Appearance *appearance ) { _appearance = appearance; }

protected:
	Shape *_shape;
	Appearance *_appearance;
};

#endif
