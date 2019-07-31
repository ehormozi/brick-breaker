#ifndef __BRIQUE_H
#define __BRIQUE_H

#include <cstddef>
#include "configuration.h"

class Brique {
	private :
	size_t x ;
	size_t y ;
	size_t longeur ;
	size_t hauteur ;
	size_t resistence ;
	size_t resistenceActuelle ;
	public :
	Brique () ;
	void setX ( const size_t &xBrique ) ;
	void setY ( const size_t &yBrique ) ;
	void setLongeur ( const size_t & ) ;
	void setHauteur ( const size_t & ) ;
	void setResistence ( const size_t & ) ;
	void setResistenceActuelle ( const size_t &resistenceActuelleBrique ) ;
	size_t getX () const ;
	size_t getY () const ;
	size_t getLongeur () const ;
	size_t getHauteur () const ;
	size_t getResistence () const ;
	size_t getResistenceActuelle () const ;
} ;

#endif
