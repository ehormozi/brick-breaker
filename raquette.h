#ifndef __RAQUETTE_H
#define __RAQUETTE_H

#include <cstddef>
#include "configuration.h"

class Raquette {
	private :
	size_t x ;
	size_t y ;
	const size_t longeur = 7 ;
	const size_t hauteur = 1 ;
	size_t maxX ;
	public :
	Raquette ( const Configuration & ) ;
	void setX ( const size_t &xRaquette ) ;
	void setY ( const size_t &yRaquette ) ;
	void setLongeur ( const size_t &longeurRaquette ) ;
	void setHauteur ( const size_t &hauteurRaquette ) ;
	void setMaxX ( const size_t &maxXRaquette ) ;
	size_t getX () const ;
	size_t getY () const ;
	size_t getLongeur () const ;
	size_t getHauteur () const ;
	size_t getMaxX () const ;
	void moveDroit () ;
	void moveGauche () ;
} ;

#endif