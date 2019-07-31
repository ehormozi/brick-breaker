#include "jeu.h"

using namespace std ;

Jeu::Jeu () : configuration () , terrain ( configuration ) , menu ( configuration ) , joueur ( configuration ) {
	menu . setX ( terrain . getX () ) ;
	menu . setY ( terrain . getY () ) ;
	menu . setLongeur ( terrain . getLongeur () / 2 ) ;
	menu . setHauteur ( terrain . getHauteur () ) ;
	setMeilleures () ;
}

size_t getNbChiffres ( size_t n ) {
	if ( n >= 0 && n < 10 ) {
		return 1 ;
	}
	else {
		return ( getNbChiffres ( n / 10 ) + 1 ) ;
	}
}

std::string toString ( size_t a ) {
    ostringstream tmp ;
    tmp << a ;
    return tmp . str () ;
}

bool Jeu::estVide ( size_t x , size_t y ) {
	if ( ! ( x >= 0 && x < terrain . getLongeur() && y >= 0 && y < terrain . getHauteur () ) ) {
		return false ;
	}
	if ( x >= terrain . raquette . getX () && x < terrain . raquette . getX () + terrain . raquette . getLongeur () &&
	y == terrain . raquette . getY () ) {
		return false		;
	}
	for ( size_t i = 0 ; i < terrain . getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < terrain . getBriqueColonnes () ; j++ ) {
			if ( x >= terrain . getBrique ( i , j ) . getX () &&
			x < terrain . getBrique ( i , j ) . getX () + terrain . getBrique ( i , j ) . getLongeur () &&
			y == terrain . getBrique ( i , j ) . getY () &&
			terrain . getBrique ( i , j ) . getResistenceActuelle () != 0 ) {
				return false ;
			}
		}
	}
	return true ;
}

void Jeu::setMeilleures () {
	ifstream is ;
	is . open ( "meilleures.txt" ) ;
	string nom ;
	size_t score ;
	for ( int i = 0 ; i < 5 ; i++ ) {
		getline ( is , nom , ':' ) ;
		is >> score ;
		meilleuresJoueurs [ i ] = nom ;
		meilleuresScores [ i ] = score ;
		getline ( is , nom ) ;
	}
	is . close () ;
}

void Jeu::updateBriques ( Window &plateau ) {
	for ( size_t i = 0 ; i < terrain . getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < terrain . getBriqueColonnes () ; j++ ) {
			if ( terrain . getBrique ( i , j ) . getResistenceActuelle () == 0 ) {
				plateau . erase ( terrain . getBrique ( i , j ) ) ;
			}	
		}
	}
}

void Jeu::updateScore ( Window &info ) {
	info . erase ( 1 , 10 , getNbChiffres ( joueur . partie . getScore () ) ) ;
	info . print ( 1 , 10 , toString ( joueur . partie . getScore () ) ) ;
}

void Jeu::updateNbBalles ( Window &info ) {
	info . erase ( 1 , 6 , getNbChiffres ( joueur . partie . getNbBalles () ) + 1 ) ;
	info . print ( 1 , 6 , toString ( joueur . partie . getNbBalles () ) ) ;
}

void Jeu::updateMeilleures () {
	if ( joueur . partie . getScore () < meilleuresScores [ 4 ] ) {
		return ;
	}
	meilleuresJoueurs [ 4 ] = joueur . getNom () ;
	meilleuresScores [ 4 ] = joueur . partie . getScore () ;
	int i = 4 ;
	while ( meilleuresScores [ i ] > meilleuresScores [ i - 1 ]  && i != 0 ) {
		size_t tmp = meilleuresScores [ i ] ;
		meilleuresScores [ i ] = meilleuresScores [ i - 1 ] ;
		meilleuresScores [ i - 1 ] = tmp ;
		string tmp2 = meilleuresJoueurs [ i ] ;
		meilleuresJoueurs [ i ] = meilleuresJoueurs [ i - 1 ] ;
		meilleuresJoueurs [ i - 1 ] = tmp2 ;
		i-- ;
	}
	ofstream os ;
	os . open ( "meilleures.txt" ) ;
	for ( int i = 0 ; i < 5 ; i++ ) {
		os << meilleuresJoueurs [ i ] << ':' << meilleuresScores [ i ] << endl ;
	}
	os . close () ;
}

Key Jeu::saisirNomJoueur ( Window & plateau , Window &info ) {
	plateau . clear () ;
	terrain . reset ( configuration ) ;
	info . print ( 1 , 1 , "Enter your name" ) ;
	info . print ( 1 , 2 , "and press Enter:" ) ;
	std::string tmp ;
	cin >> tmp ;
	joueur . setNom ( tmp ) ;
	info . clear () ;
	return KeyAvantLancer ;
}

Key Jeu::avantLancer ( Window &plateau , Window &info ) {
	joueur . partie . setEnCours ( true ) ;
	menu . setFirstOption  ( 0 ) ;
	menu . selector . setMenuItemIndex ( menu . getFirstOption () ) ;
	info . print ( 1 , 1 , "Player name :" , WBLACK ) ;
	info . print ( 1 , 2 , joueur . getNom () , WBLACK ) ;
	info . print ( 1 , 5 , "Number of balls :" , WBLACK ) ;
	info . print ( 1 , 6 , toString ( joueur . partie . getNbBalles () ) , WBLACK ) ;
	info . print ( 1 , 9 , "Score :" , WBLACK ) ;
	info . print ( 1 , 10 , toString ( joueur . partie . getScore () ) , WBLACK ) ;
	info . print ( 1 , 13 , "Space : launch the ball" , WBLACK ) ;
	terrain . balle . setX ( terrain . raquette . getX () + terrain . raquette . getLongeur () / 2 ) ;
	terrain . balle . setY ( terrain . raquette . getY () - 1 ) ;
	plateau . print ( terrain . raquette ) ;
	plateau . print ( terrain . balle ) ;
	for ( size_t i = 0 ; i < terrain . getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < terrain . getBriqueColonnes () ; j++ ) {
			plateau . print ( terrain . getBrique ( i , j ) ) ;
		}
	}
	updateBriques ( plateau ) ;
	if ( joueur . partie . getNbBalles () == 0 ) {
		joueur . partie . setEnCours ( false ) ;
		menu . setFirstOption ( 1 ) ;
		menu . selector . setMenuItemIndex ( menu . getFirstOption () ) ;
		return KeyGameOver ;
	}
	int key ;
	while ( ( key = getch () ) != 'q' ) {
		switch ( key ) {
		case KEY_LEFT :
			plateau . erase ( terrain . raquette ) ;
			plateau . erase ( terrain . balle ) ;
			terrain . raquette . moveGauche () ;
			terrain . balle . setX ( terrain . raquette . getX () + terrain . raquette . getLongeur () / 2 ) ;
			plateau . print ( terrain . raquette ) ;
			plateau . print ( terrain . balle ) ;
		break ;
		case KEY_RIGHT :
			plateau . erase ( terrain . raquette ) ;
			plateau . erase ( terrain . balle ) ;
			terrain . raquette . moveDroit () ;
			terrain . balle . setX ( terrain . raquette . getX () + terrain . raquette . getLongeur () / 2 ) ;
			plateau . print ( terrain . raquette ) ;
			plateau . print ( terrain . balle ) ;
		break ;
		case KEY_BACKSPACE :
			info . clear () ;
			return KeyAfficherMenu ;
		break ;

		case ' ' :
			info . erase ( 1 , 13 , 23 ) ;
			return KeyApresLancer ;
		}
	}
	return KeyExit ;
}

Key Jeu::apresLancer ( Window & plateau , Window &info ) {
	joueur . partie . setEnCours ( true ) ;
	menu . setFirstOption  ( 0 ) ;
	menu . selector . setMenuItemIndex ( menu . getFirstOption () ) ;
	int key ;
	while ( ( key = getch () ) != 'q' ) {
		switch ( key ) {
		case KEY_LEFT :
			plateau . erase ( terrain . raquette ) ;
			terrain . raquette . moveGauche () ;
			plateau . print ( terrain . raquette ) ;
		break ;
		case KEY_RIGHT :
			plateau . erase ( terrain . raquette ) ;
			terrain . raquette . moveDroit () ;
			plateau . print ( terrain . raquette ) ;
		break ;
		case KEY_BACKSPACE :
			info . clear () ;
			return KeyAfficherMenu ;
		break ;
		}
		plateau . erase ( terrain . balle ) ;
		terrain . balle . moveBalle () ;
		int cmpt = 0 ;
		while ( ! estVide ( terrain . balle . getX () , terrain . balle . getY () ) ) {
			if ( terrain . balleHitBrique () ) {
				joueur . partie . setScore ( joueur . partie . getScore () + 1 ) ;
			}
			if ( cmpt < 10 ) {
				terrain . changerDirectionBalle () ;
				terrain . balle . moveBalle () ;
				cmpt++ ;
			}
			else {
				terrain . balle . setX ( terrain . raquette . getX () + terrain . raquette . getLongeur () / 2 ) ;
				terrain . balle . setY ( terrain . raquette . getY () - 1 ) ;
				break ;
			}
		}
		updateBriques ( plateau ) ;
		updateScore ( info ) ;
		plateau . print ( terrain . balle ) ;
		if ( terrain . ballePerdu () ) {
			joueur . partie . setNbBalles ( joueur . partie . getNbBalles () - 1 ) ;
			updateNbBalles ( info ) ;
			plateau . clear () ;
			return KeyAvantLancer ;
		}
		usleep ( 10000 / terrain . balle . getVitesse () ) ;
	}
	return KeyExit ;
}

Key Jeu::gameOver ( Window &plateau , Window &info ) {
	info . print ( 1 , 14 , "Game Over!" ) ;
	while ( getch () != ' ' ) {}
	updateMeilleures () ;
	joueur . reset () ;
	terrain . reset ( configuration ) ;
	plateau . clear () ;
	info . clear () ;
	return KeyAfficherMenu ;
}

Key Jeu::afficherMeilleures ( Window &plateau ) {
	for ( int i = 0 ; i < 5 ; i++ ) {
		plateau . print ( 1 , 2 * i , meilleuresJoueurs [ i ] ) ;
		plateau . print ( 15 , 2 * i , toString ( meilleuresScores [ i ] ) ) ;
	}
	return KeyAfficherMenu ;
}
		

Key Jeu::enregistrer () {
	ofstream save ;
	save . open ( "load.txt" ) ;
	save << joueur . getNom () << endl ;
	save << joueur . partie . getScore () << endl ;
	save << joueur . partie . getNbBalles () << endl ;
	save << terrain . raquette . getX () << endl ;
	save << terrain . raquette . getY () << endl ;
	save << terrain . balle . getX () << endl ;
	save << terrain . balle . getY () << endl ;
	save << terrain . balle . getDirection () << endl ;
	for ( size_t i = 0 ; i < terrain . getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < terrain . getBriqueColonnes () ; j++ ) {
			save << terrain . getBrique ( i , j ) . getResistenceActuelle () << endl ;
		}
	}
	return KeyAvantLancer ;
}

Key Jeu::reprendre ( Window & plateau , Window & info ) {
	info . clear () ;
	ifstream load ;
	load . open ( "load.txt" ) ;
	size_t tmpInt ;
	double tmpDouble ;
	string name ;
	getline ( load , name ) ;
	joueur . setNom ( name ) ;
	load >> tmpInt ;
	joueur . partie . setScore ( tmpInt ) ;
	load >> tmpInt ;
	joueur . partie . setNbBalles ( tmpInt ) ;
	load >> tmpInt ;
	terrain . raquette . setX ( tmpInt ) ;
	load >> tmpInt ;
	terrain . raquette . setY ( tmpInt ) ;
	load >> tmpDouble ;
	terrain . balle . setX ( tmpDouble ) ;
	load >> tmpDouble ;
	terrain . balle . setY ( tmpDouble ) ;
	load >> tmpDouble ;
	terrain . balle . setDirection ( tmpDouble ) ;
	for ( size_t i = 0 ; i < terrain . getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < terrain . getBriqueColonnes () ; j++ ) {
			load >> tmpInt ;
			terrain . getBrique ( i , j ) . setResistenceActuelle ( tmpInt ) ;
		}
	}
	return KeyAvantLancer ;
}

Key Jeu::afficherMenu ( Window & info ) {
	info . clear () ;
	info . print ( menu ) ;
	int key ;
	while ( ( key = getch () ) != 'q' ) {
		switch ( key ) {
		case KEY_UP :
			info . erase ( menu . selector ) ;
			menu . selector . moveUp () ;
			info . print ( menu . selector ) ;
		break ;
		case KEY_DOWN :
			info . erase ( menu . selector ) ;
			menu . selector . moveDown () ;
			info . print ( menu . selector ) ;
		break ;
		case ' ' :
			info . clear () ;
			switch ( menu . selector . getMenuItemIndex () ) {
				case 0 :
					return KeyAvantLancer ;
				case 1 :
					return KeySaisirNomJoueur ;
				case 2 :
					return KeyReprendre ;
				case 3 :
					return KeyEnregistrer ;
				case 4 :
					return KeyAfficherMeilleuresScores ;
				case 5 :
					return KeyAfficherMenu ;
				case 6 :
					return KeyExit ;
			}
		}
	}
	return KeyExit ;
}

void Jeu::start () {
	ofstream os ;
	os . open ( "log.txt" ) ;
	Window plateau ( terrain . getHauteur () , terrain . getLongeur() ,	terrain . getX () , terrain . getY () + 2 ) ;
	plateau . setCouleurBordure ( BBLUE ) ;
	Window info ( terrain . getHauteur () , terrain . getLongeur() / 2 ,	terrain . getX () + terrain . getLongeur () + 1 , terrain . getY () + 2 ) ;
	info . setCouleurBordure ( BBLUE ) ;
	Key control = KeyAfficherMenu ;
	while ( control != KeyExit ) {
		if ( control == KeyAfficherMenu ) {
			control = afficherMenu ( info ) ;
			os << "Afficher le menu" << endl ;
		}
		if ( control == KeySaisirNomJoueur ) {
			control = saisirNomJoueur ( plateau , info ) ;
			os << "Nouvelle partie a commencee" << endl ;
		}
		if ( control == KeyAvantLancer ) {
			control = avantLancer ( plateau , info ) ;
			os << "Balle retourne a la raquette" << endl ;
		}
		if ( control == KeyApresLancer ) {
			control = apresLancer ( plateau , info ) ;
			os << "Balle est lancee" << endl ;
		}
		if ( control == KeyEnregistrer ) {
			control = enregistrer () ;
			os << "Joueur a enregistrer sa partie" << endl ;
		}
		if ( control == KeyReprendre ) {
			control = reprendre ( plateau , info ) ;
			os << "Joueur a repris sa partie" << endl ;
		}
		if ( control == KeyGameOver ) {
			control = gameOver ( plateau , info ) ;
			os << "Joueur perds ses balles" << endl ;
		}
		if ( control == KeyAfficherMeilleuresScores ) {
			control = afficherMeilleures ( plateau ) ;
			os << "Afficher les meilleures Scores" << endl ;
		}
	}
	os << "Quitter le jeu" << endl ;
	os . close () ;
}
