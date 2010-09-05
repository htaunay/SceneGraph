#ifndef _MATERIAL_H_
#define _MATERIAL_H_

class Material
{
public:
	Material();

	void setAmbient( float r, float g, float b, float alpha );

	void setDiffuse( float r, float g, float b, float alpha );

	void setSpecular( float r, float g, float b, float alpha );

	void setShineness( float shineness );

	void load();

	void unload();

private:
	float _ambient[4];
	float _diffuse[4];
	float _specular[4];
	float _shineness;
};

#endif
