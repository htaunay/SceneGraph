#ifndef _SPOT_LIGHT_H_
#define _SPOT_LIGHT_H_

#include "Light.h"

class SpotLight : public Light
{
public:
	virtual inline int setupCamera() { return 1; }

	virtual int setupLights();

	virtual inline void render() {;}

	virtual void setAmbient( float r, float g, float b, float alpha );

	virtual void setDiffuse( float r, float g, float b, float alpha );

	virtual void setSpecular( float r, float g, float b, float alpha );

public:
	SpotLight();

	void setPosition( float x, float y, float z );

	void setDirection( float x, float y, float z );

	// 0, 180
	void setCutOff( float cutOff ) { _cutOff = cutOff; }

	// 0,128
	void setExpoent( float expoent ) { _expoent = expoent; }

	void setConstantAttenuation( float constAtt ) { _constantAtt = constAtt; }

	void setLinearAttenuation( float linearAtt ) { _linearAtt = linearAtt; }

	void setQuadraticAttenuation( float quadAtt ) { _quadAtt = quadAtt; }

	void setupAttenuation( float constAtt, float linearAt, float quadAtt );

private:
	float _position[4];
	float _direction[3];
	float _cutOff;
	float _expoent;
	float _constantAtt;
	float _linearAtt;
	float _quadAtt;
};

#endif
