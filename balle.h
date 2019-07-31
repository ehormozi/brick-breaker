#ifndef __BALLE_H
#define __BALLE_H

#include <cstddef>
#include <cmath>
#include "configuration.h"

class Balle {
	private :
	double x ;
	double y ;
	double direction = M_PI / 4 ;
	double vitesse ;
	public :
	Balle ( const Configuration & ) ;
	void setX ( const double &xBalle ) ;
	void setY ( const double &yBalle ) ;
	void setDirection ( const double &directionBalle ) ;
	void setVitesse ( const double &vitesseBalle ) ;
	double getX () const ;
	double getY () const ;
	double getDirection () const ;
	double getVitesse () const ;
	void moveBalle () ;
} ;

#endif
