#include "partie.h"

Partie::Partie ( const Configuration &configuration ) {
	setScore ( getScoreInitiale () ) ;
	setNbBalles ( configuration . partieNbBallesInitiale ) ;
	setEnCours ( false ) ;
}

void Partie::setScore ( size_t scorePartie ) {
	score = scorePartie ;
}

void Partie::setNbBalles ( size_t nbBallesPartie ) {
	nbBalles = nbBallesPartie ;
}

void Partie::setEnCours ( bool enCoursPartie ) {
	enCours = enCoursPartie ;
}

size_t Partie::getScore () {
	return score ;
}

size_t Partie::getNbBalles () {
	return nbBalles ;
}

bool Partie::getEnCours () {
	return enCours ;
}

size_t Partie::getScoreInitiale () const {
	return scoreInitiale ;
}

bool Partie::getEnCoursInitiale () const {
	return enCoursInitiale ;
}
