#include "../header/menu.h"

Menu::Menu ( const Configuration &configuration ) : selector ( configuration ) {
	setFirstOption ( 1 ) ;
	options [ 0 ] = "Reprendre Le Jeu" ;
	options [ 1 ] = "Nouvelle Partie" ;
	options [ 2 ] = "Partie Enregistree" ;
	options [ 3 ] = "Enregistrer" ;
	options [ 4 ] = "Meilleures Scores" ;
	options [ 5 ] = "A propos" ;
	options [ 6 ] = "Exit" ;
	selector . setX ( getX () ) ;
	selector . setMenuItemIndex ( getFirstOption () ) ;
}

void Menu::setX ( const size_t &xMenu ) {
	x = xMenu ;
}

void Menu::setY ( const size_t &yMenu ) {
	y = yMenu ;
}

void Menu::setLongeur ( const size_t &longeurMenu ) {
	longeur = longeurMenu ;
}

void Menu::setHauteur ( const size_t &hauteurMenu ) {
	hauteur = hauteurMenu ;
}

void Menu::setFirstOption ( const size_t &firstOptionMenu ) {
	firstOption = firstOptionMenu ;
}

size_t Menu::getX () const {
	return x ;
}

size_t Menu::getY () const {
	return y ;
}

size_t Menu::getLongeur () const {
	return longeur ;
}

size_t Menu::getHauteur () const {
	return hauteur ;
}

size_t Menu::getFirstOption () const {
	return firstOption ;
}

size_t Menu::getNbOptions () const {
	return nbOptions ;
}

std::string Menu::getOption ( size_t i ) const {
	return options [ i ] ;
}
