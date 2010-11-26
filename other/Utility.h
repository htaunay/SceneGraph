/*
  SceneGraph - 2010, PUC-Rio
  Student/Developer: Henrique d'Escragnolle-Taunay
  Teacher: Waldemar Celes
 */

#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <GL/gl.h>

/*!
	Auxiliary static class for utility methods, for the sole purpurse of
	making writing code cleaner and faster.
 */
class Utility
{
public:
	static int abs( int value );
	static float abs( float value );
	static double abs( double value );

	//! Initialize's a float vector of a given size with a given value (default is 0).
	static void initVectorf( float *vec, int size, int value = 0 );

	//! Initialize's a double vector of a given size with a given value (default is 0).
	static void initVectord( double *vec, int size, int value = 0 );

	//! Initialize's a GLfloat vector of a given size with a given value (default is 0).
	static void initVectorgf( GLfloat *vec, int size, int value = 0 );

	//! Copie's a float vector values to another similiar structre vector.
	//! The vector's sizes must be defined.
	static void copyVectorf( float *src, float* dest, int size );

	//! Copie's a double vector values to another similiar structre vector.
	//! The vector's sizes must be defined.
	static void copyVectord( double *src, double* dest, int size );

	//! Copie's a GLfloat vector values to another similiar structre vector.
	//! The vector's sizes must be defined.
	static void copyVectorgf( GLfloat *src, GLfloat* dest, int size );

public:
	//! Default Matrix size = 16
	static const int MATRIX_SIZE;

	//! Default Vector size = 4
	static const int VECTOR_SIZE;
};

#endif
