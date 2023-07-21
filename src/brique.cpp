#include "../header/brique.h"

Brique::Brique () {}

void Brique::setX ( const size_t &xBrique ) {
	x = xBrique ;
}

void Brique::setY ( const size_t &yBrique ) {
	y = yBrique ;
}

void Brique::setLongeur ( const size_t &longeurBrique ) {
	longeur = longeurBrique ;
}

void Brique::setHauteur ( const size_t &hauteurBrique ) {
	hauteur = hauteurBrique ;
}

void Brique::setResistence ( const size_t &resistenceBrique ) {
	resistence = resistenceBrique ;
}

void Brique::setResistenceActuelle ( const size_t &resistenceActuelleBrique ) {
	resistenceActuelle = resistenceActuelleBrique ;
}

size_t Brique::getX () const {
	return x ;
}

size_t Brique::getY () const {
	return y ;
}

size_t Brique::getLongeur () const {
	return longeur ;
}

size_t Brique::getHauteur () const {
	return hauteur ;
}

size_t Brique::getResistence () const {
	return resistence ;
}

size_t Brique::getResistenceActuelle () const {
	return resistenceActuelle ;
}
