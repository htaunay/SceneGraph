#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "Appearance.h"

class Material : public Appearance
{
public:
	virtual void load();

	virtual void unLoad();

public:
	Material();

	void setAmbient( float r, float g, float b, float alpha );

	void setDiffuse( float r, float g, float b, float alpha );

	void setSpecular( float r, float g, float b, float alpha );

	void setShineness( float shineness );

private:
	float _ambient[4];
	float _diffuse[4];
	float _specular[4];
	float _shineness;
};

#endif
