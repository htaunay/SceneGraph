// Manipulator.h
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Jan 2008

#ifndef V_MANIPULATOR_H
#define V_MANIPULATOR_H

#include "Vector.h"

class Manipulator
{
  static Manipulator* _current;

public:
  static Manipulator* getInstance();

  static void setCurrent (Manipulator* manip);

public:
  Manipulator ();

  void setCenter( double *center );

  void setOrigin( double *origin );

  void load();

  void identity();

  void rotate( float angle, float rx, float ry, float rz );

  void scale( float sx, float sy, float sz );

  void translate( float tx, float ty, float tz );

private:
  float _matrix[16];
  VVector _center;
  VVector _origin;

};

#endif
