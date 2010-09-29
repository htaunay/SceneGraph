#ifndef _APPEARANCE_H_
#define _APPEARANCE_H_

class Appearance
{
public:
	Appearance();

	virtual void load()   = 0;

	virtual void unLoad() = 0;
};
#endif
