#ifndef _GROUP_H_
#define _GROUP_H_

#include "Node.h"
#include <vector>

class Group : public Node
{
public:
	Group();

	virtual int setupCamera();

	virtual int setupLights();

	virtual void render();

	bool addNode( Node* newNode );

private:
	std::vector<Node*> _children;
};

#endif
