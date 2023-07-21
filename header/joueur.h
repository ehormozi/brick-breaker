#ifndef __JOUEUR_H
#define __JOUEUR_H

#include <string>
#include "partie.h"
#include "configuration.h"

class Joueur {
	private :
	std::string nom ;
	int meilleureScore ;
	unsigned int rang ;
	public :
	Partie partie ;
	Joueur ( const Configuration & ) ;
	void setNom ( std::string nomJoueur ) ;
	void setMeilleureScore ( int meilleureScoreJoueur ) ;
	void setRang ( unsigned int rangJoueur ) ;
	std::string getNom () ;
	int getMeilleureScore () ;
	unsigned int getRang () ;
	void reset () ;
} ;

#endif