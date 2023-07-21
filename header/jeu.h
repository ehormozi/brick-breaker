#ifndef __JEU_H
#define __JEU_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>
#include <unistd.h>
#include "window.h"
#include "menu.h"
#include "joueur.h"
#include "terrain.h"
#include "keys.h"
#include "configuration.h"

class Jeu {
	private :
	public :
	size_t meilleuresScores [ 5 ] ;
	std::string meilleuresJoueurs [ 5 ] ;
	std::string savedFile ;
	Configuration configuration ;
	Terrain terrain ;
	Menu menu ;
	Joueur joueur ;
	Jeu () ;
	bool estVide ( size_t , size_t ) ;
	void setMeilleures () ;
	void updateBriques ( Window & ) ;
	void updateScore ( Window & ) ;
	void updateNbBalles ( Window & ) ;
	void updateMeilleures () ;
	void start () ;
	Key afficherMenu ( Window & ) ;
	Key avantLancer ( Window & , Window & ) ;
	Key apresLancer ( Window & , Window & ) ;
	Key saisirNomJoueur ( Window & , Window & ) ;
	Key gameOver ( Window & , Window & ) ;
	Key afficherMeilleures ( Window & ) ;
	Key enregistrer () ;
	Key reprendre ( Window & , Window & ) ;
} ;

#endif
