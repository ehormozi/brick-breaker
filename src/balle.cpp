
#include "../header/balle.h"

Balle::Balle ( const Configuration &configuration ) {
	setDirection ( M_PI / 4 ) ;
	setVitesse ( configuration . balleVitesse ) ;
}

void Balle::setX ( const double &xBalle ) {
	x = xBalle ;
}

void Balle::setY ( const double &yBalle ) {
	y = yBalle ;
}

void Balle::setDirection ( const double &directionBalle ) {
	direction = directionBalle ;
}


void Balle::setVitesse ( const double &vitesseBalle ) {
	vitesse = vitesseBalle ;
}

double Balle::getX () const {
	return x ;
}

double Balle::getY () const {
	return y ;
}

double Balle::getDirection () const {
	return direction ;
}

double Balle::getVitesse () const {
	return vitesse ;
}

void Balle::moveBalle () {
	setY ( getY () - sin ( getDirection () ) ) ;
	setX ( getX () + cos ( getDirection () ) ) ;
}
