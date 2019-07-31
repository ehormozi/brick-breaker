#ifndef __MENU_H
#define __MENU_H

#include <string>
#include "selector.h"
#include "configuration.h"

class Menu {
	private :
	size_t x ;
	size_t y ;
	size_t longeur ;
	size_t hauteur ;
	size_t firstOption ;
	static const size_t nbOptions = 7 ;
	std::string options [ nbOptions ] ;
	public :
	Selector selector ;
	Menu ( const Configuration & ) ;
	void setX ( const size_t &xMenu ) ;
	void setY ( const size_t &yMenu ) ;
	void setLongeur ( const size_t &longeurMenu ) ;
	void setHauteur ( const size_t &hauteurMenu ) ;
	void setFirstOption ( const size_t &firstOptionMenu ) ;
	size_t getX () const ;
	size_t getY () const ;
	size_t getLongeur () const ;
	size_t getHauteur () const ;
	size_t getFirstOption () const ;
	size_t getNbOptions () const ;
	std::string getOption ( size_t ) const ;
} ;

#endif
