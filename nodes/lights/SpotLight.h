/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _SPOT_LIGHT_H_
#define _SPOT_LIGHT_H_

#include "Light.h"

/*!
	Specific implementation of a Light object, that creates infinite light
	rays projecting from a specified origin, and limited to a specified opening
	in the format of a cone(angle) in a given direction.

	It is possible to define the attenuation of the light, or in other words,
	how much of it's intensity varies considering the distance to the origin.
	The default attenuation is constant, but it can also vary linarly and exponentialy.
 */
class SpotLight : public Light
{
public:
	//! Method inherited from Node object and implemented according to the
	//! SpotLight specifications.
	virtual int setupLights();

	// Methods inherited by Node object. No changes.
	virtual inline void render() {;}
	virtual inline int setupCamera() { return 1; }

public:
	//! Constructor that initializes all of SpotLight's attributes.
	SpotLight();

	//! Set's the light's position attribute.
	void setPosition( float x, float y, float z );

	//! Set's the light's direction attribute.
	void setDirection( float x, float y, float z );

	/*!
		Set's the spotlight's 'cut off' attribute. The 'cut off' represents the
		angle radius of the light's cone. The cone's total spread will be 2x
		the radius. The radius can vary from 0 (closed cone) to 180 degress
		(completely open cone).
	 */
	void setCutOff( float cutOff ) { _cutOff = cutOff; }

	/*!
		Set's the spotlight's expoent attribute. The expoent represents how much
		the light is concentrated in the center of the spotlight projection. The
		expoent value can vary from 0 (completely spread spotlight projection)
		to 128 (completely concentrated spotlight).
	 */
	void setExpoent( float expoent ) { _expoent = expoent; }

	/*!
		Set's the light's constant attenuation attribute. The constant
		attenuation varies from 0 to 1, and represents the proportion of the
		light's intensity that doesn't vary with the distance of the origin.
	 */
	void setConstantAttenuation( float constAtt ) { _constantAtt = constAtt; }

	/*!
		Set's the light's linear attenuation attribute. The linear
		attenuation varies from 0 to 1, and represents the proportion of the
		light's intensity that varies linearly with the distance of the origin.
	 */
	void setLinearAttenuation( float linearAtt ) { _linearAtt = linearAtt; }

	/*!
		Set's the light's quadratic attenuation attribute. The quadratic
		attenuation varies from 0 to 1, and represents the proportion of the
		light's intensity that varies exponentially with the distance of the origin.
	 */
	void setQuadraticAttenuation( float quadAtt ) { _quadAtt = quadAtt; }

	//! Set's the lights constant, linear and quadratic attenuations at once.
	//! This method only exists to facilitate the spotlight configuration process.
	void setupAttenuation( float constAtt, float linearAt, float quadAtt );

private:
	float _direction[3];
	float _position[4];
	float _cutOff;
	float _expoent;
	float _constantAtt;
	float _linearAtt;
	float _quadAtt;
};

#endif
