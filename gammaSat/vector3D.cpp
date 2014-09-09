
#include "masterHeader.h"

// This class sets the vector in one go
void vector3D::setVector( double X, double Y, double Z ):
	x(X) , y(Y) , z(Z)
{}

// This class gets a particular component and returns it's value
double vector3D::getComponent( component request ){
	if ( request == X_COM )
		return x;
	else if ( request == Y_COM )
		return y;
	else
		return z;
}

// Sets a particular component without affecting the others
void vector3D::setComponent( component inputComponent, double value ){
	if ( inputComponent == X_COM )
		x = value;
	else if ( inputComponent == Y_COM )
		y = value;
	else	
		z = value;	
}

