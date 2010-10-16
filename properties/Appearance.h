/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _APPEARANCE_H_
#define _APPEARANCE_H_

//! Virtual generic class for all objects that represent an appearance object.
class Appearance
{
public:
	Appearance() {};

	virtual void load()   = 0;
	virtual void unLoad() = 0;
};
#endif
