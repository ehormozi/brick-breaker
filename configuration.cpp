#include "configuration.h"

using namespace std ;

Color doubleToCouleur ( const double &r ) {
	switch ( ( size_t ) r ) {
		case 0 :
			return WBLACK ;
		case 1 :
			return WCYAN ;
		case 2 :
			return WBLUE ;
		case 3 :
			return WYELLOW ;
		case 4 :
			return WGREEN ;
		case 5 :
			return WMAGENTA ;
		case 6 :
			return WRED ;
		case 7 :
			return BWHITE ;
		case 8 :
			return BCYAN ;
		case 9 :
			return BBLUE ;
		case 10 :
			return BYELLOW ;
		case 11 :
			return BGREEN ;
		case 12 :
			return BMAGENTA ;
		case 13 :
			return BRED ;
		default :
			return WBLACK ;
	}
}

Configuration::Configuration () {
	meilleuresScoresGapVerticale = getDouble ( "MeilleuresScoresGapVerticale" ) ;
	meilleuresScoresGapHorizontale = getDouble ( "MeilleuresScoresGapHorizontale" ) ;
	ballStuckRepititionTimes = getDouble ( "BallStuckRepititionTimes" ) ;
	partieNbBallesInitiale = getDouble ( "PartieNbBallesInitiale" ) ;
	infoCouleurBordure = doubleToCouleur ( getDouble ( "InfoCouleurBordure" ) ) ;
	menuCouleur = doubleToCouleur ( getDouble ( "MenuCouleur" ) ) ;
	menuOptionsGap = getDouble ( "MenuOptionsGap" ) ;
	selecteurCouleur = doubleToCouleur ( getDouble ( "SelecteurCouleur" ) ) ;
	messageCouleur = doubleToCouleur ( getDouble ( "MessageCouleur" ) ) ;
	messagesGap = getDouble ( "MessagesGap" ) ;
	terrainX = getDouble ( "TerrainX" ) ;
	terrainY = getDouble ( "TerrainY" ) ;
	terrainLongeur = getDouble ( "TerrainLongeur" ) ;
	terrainHauteur = getDouble ( "TerrainHauteur" ) ;
	terrainCouleurBordure = doubleToCouleur ( getDouble ( "TerrainCouleurBordure" ) ) ;
	terrainBriqueLignes = getDouble ( "TerrainBriqueLignes" ) ;
	terrainBriqueColonnes = getDouble ( "TerrainBriqueColonnes" ) ;
	briqueRectangulaireLongeur = getDouble ( "BriqueRectangulaireLongeur" ) ;
	briqueRectangulaireHauteur = getDouble ( "BriqueRectangulaireHauteur" ) ;
	briqueRectangulaireCouleur = doubleToCouleur ( getDouble ( "BriqueRectangulaireCouleur" ) ) ;
	briqueRectangulaireResistence = getDouble ( "BriqueRectangulaireResistence" ) ;
	briqueTriangulaireLongeur = getDouble ( "BriqueTriangulaireLongeur" ) ;
	briqueTriangulaireHauteur = getDouble ( "BriqueTriangulaireHauteur" ) ;
	briqueTriangulaireCouleur = doubleToCouleur ( getDouble ( "BriqueTriangulaireCouleur" ) ) ;
	briqueTriangulaireResistence = getDouble ( "BriqueTriangulaireResistence" ) ;
	balleXInitialeRelative = getDouble ( "BalleXInitialeRelative" ) ;
	balleYInitialeRelative = getDouble ( "BalleYInitialeRelative" ) ;
	balleCouleur = doubleToCouleur ( getDouble ( "BalleCouleur" ) ) ;
	balleDirectionInitialeCoefficient = getDouble ( "BalleDirectionInitialeCoefficient" ) ;
	balleVitesse = getDouble ( "BalleVitesse" ) ;
	raquetteXInitialeRelative = getDouble ( "RaquetteXInitialeRelative" ) ;
	raquetteYInitialeRelative = getDouble ( "RaquetteYInitialeRelative" ) ;
	raquetteLongeur = getDouble ( "RaquetteLongeur" ) ;
	raquetteHauteur = getDouble ( "RaquetteHauteur" ) ;
	raquetteCouleur = doubleToCouleur ( getDouble ( "RaquetteCouleur" ) ) ;
}

double Configuration::getDouble ( const string &parametre ) const {
	ifstream read ;
	read . open ( "configuration.config" ) ;
	string line ;
	double valeur ;
	while ( ! read . eof () ) {
		getline ( read , line , ':' ) ;
		read >> valeur ;
		if ( line == parametre ) {
			return valeur ;
		}
		getline ( read , line ) ;
	}
	return 0 ;
}
