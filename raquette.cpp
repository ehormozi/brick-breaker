#include "raquette.h"

Raquette::Raquette ( const Configuration &configuration ) {}

void Raquette::setX ( const size_t &xRaquette ) {
	x = xRaquette ;
}

void Raquette::setY ( const size_t &yRaquette ) {
	y = yRaquette ;
}

void Raquette::setMaxX ( const size_t &maxXRaquette ) {
	maxX = maxXRaquette ;
}

size_t Raquette::getX () const {
	return x ;
}

size_t Raquette::getY () const {
	return y ;
}

size_t Raquette::getLongeur () const {
	return longeur ;
}

size_t Raquette::getHauteur () const {
	return hauteur ;
}

size_t Raquette::getMaxX () const {
	return maxX ;
}

void Raquette::moveDroit () {
	if ( getX () != getMaxX () ) {
		setX ( getX () + 1 ) ;
	}
}

void Raquette::moveGauche () {
	if ( getX () != 0 ) {
		setX ( getX () - 1 ) ;
	}
}
