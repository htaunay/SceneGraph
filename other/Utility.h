#ifndef _UTILITY_H_
#define _UTILITY_H_

class Utility
{
public:
	static bool initVectorf( float *vec, int size );

	static bool initVectord( double *vec, int size );

	static bool copyVectorf( float *src, float* dest, int size );

	static bool copyVectord( double *src, double* dest, int size );

public:
	static const int MATRIX_SIZE;
};

#endif
