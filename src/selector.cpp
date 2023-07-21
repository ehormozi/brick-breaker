#include "../header/selector.h"

Selector::Selector ( const Configuration &configuration ) {}

void Selector::setX ( const size_t &xSelector ) {
	x = xSelector ;
}

void Selector::setY ( const size_t &ySelector ) {
	y = ySelector ;
}

void Selector::setMenuItemIndex ( const size_t &menuItemIndexSelector ) {
	if ( menuItemIndexSelector < 7 ) {
		menuItemIndex = menuItemIndexSelector ;
		setY ( menuItemIndexSelector * 3 ) ;
	}
}

size_t Selector::getX () const {
	return x ;
}

size_t Selector::getY () const {
	return y ;
}

size_t Selector::getLongeur () const {
	return longeur ;
}

size_t Selector::getHauteur () const {
	return hauteur ;
}

size_t Selector::getMenuItemIndex () const {
	return menuItemIndex ;
}

std::string Selector::getChars () const {
	return chars ;
}

void Selector::moveUp () {
	if ( getY () > 0 ) {
		setY ( getY () - 3 ) ;
	}
	if ( getMenuItemIndex () > 0 ) {
		setMenuItemIndex ( getMenuItemIndex () - 1 ) ;
	}
}

void Selector::moveDown () {
	if ( getY () < 18 ) {
		setY ( getY () + 3 ) ;
	}
	if ( getMenuItemIndex () < 7 ) {
		setMenuItemIndex ( getMenuItemIndex () + 1 ) ;
	}
}
