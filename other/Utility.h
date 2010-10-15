#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "gl.h"

class Utility
{
public:
	static void initVectorf( float *vec, int size, int value = 0 );

	static void initVectord( double *vec, int size, int value = 0 );

	static void initVectorgf( GLfloat *vec, int size, int value = 0 );

	static void copyVectorf( float *src, float* dest, int size );

	static void copyVectord( double *src, double* dest, int size );

	static void copyVectorgf( GLfloat *src, GLfloat* dest, int size );

public:
	static const int MATRIX_SIZE;
	static const int VECTOR_SIZE;
};

#endif
