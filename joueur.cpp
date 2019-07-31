#include "joueur.h"

Joueur::Joueur ( const Configuration &configuration ) : partie ( configuration ) {}

void Joueur::setNom ( std::string nomJoueur ) {
	nom = nomJoueur ;
}

void Joueur::setMeilleureScore ( int meilleureScoreJoueur ) {
	meilleureScore = meilleureScoreJoueur ;
}

void Joueur::setRang ( unsigned int rangJoueur ) {
	rang = rangJoueur ;
}

std::string Joueur::getNom () {
	return nom ;
}

int Joueur::getMeilleureScore () {
	return meilleureScore ;
}

unsigned int Joueur::getRang () {
	return rang ;
}

void Joueur::reset () {
	setNom ( "" ) ;
	partie . setScore ( 0 ) ;
	partie . setNbBalles ( 10 ) ;
}
