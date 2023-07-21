#ifndef __SELECTOR_H
#define __SELECTOR_H

#include <string>
#include "configuration.h"

class Selector {
	private :
	size_t x ;
	size_t y ;
	const size_t longeur = 2 ;
	const size_t hauteur = 1 ;
	size_t menuItemIndex ;
	const std::string chars = ">>" ;
	public :
	Selector ( const Configuration & ) ;
	void setX ( const size_t & ) ;
	void setY ( const size_t & ) ;
	void setMenuItemIndex ( const size_t & ) ;
	size_t getX () const ;
	size_t getY () const ;
	size_t getLongeur () const ;
	size_t getHauteur () const ;
	size_t getMenuItemIndex () const ;
	std::string getChars () const ;
	void moveUp () ;
	void moveDown () ;
} ;

#endif
