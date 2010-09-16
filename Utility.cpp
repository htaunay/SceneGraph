#include "Utility.h"

const int Utility::MATRIX_SIZE = 16;

bool Utility::initVectorf( float *vec, int size )
{
	for( int i = 0; i < size; i++ )
		vec[i] = 0;
}

bool Utility::initVectord( double *vec, int size )
{
	for( int i = 0; i < size; i++ )
		vec[i] = 0;
}

bool Utility::copyVectorf( float *src, float* dest, int size )
{
	for( int i = 0; i < size; i++ )
		dest[i] = src[i];
}

bool Utility::copyVectord( double *src, double* dest, int size )
{
	for( int i = 0; i < size; i++ )
		dest[i] = src[i];
}
