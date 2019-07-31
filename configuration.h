#ifndef CONFIGURATION
#define CONFIGURATION

#include <fstream>
#include <string>
#include "couleurs.h"

class Configuration {
	public :
	double meilleuresScoresGapVerticale ;
	double meilleuresScoresGapHorizontale ;
	double ballStuckRepititionTimes ;
	double partieNbBallesInitiale ;
	Color infoCouleurBordure ;
	Color menuCouleur ;
	double menuOptionsGap ;
	Color selecteurCouleur ;
	Color messageCouleur ;
	double messagesGap ;
	double terrainX ;
	double terrainY ;
	double terrainLongeur ;
	double terrainHauteur ;
	Color terrainCouleurBordure ;
	double terrainBriqueLignes ;
	double terrainBriqueColonnes ;
	double briqueRectangulaireLongeur ;
	double briqueRectangulaireHauteur ;
	Color briqueRectangulaireCouleur ;
	double briqueRectangulaireResistence ;
	double briqueTriangulaireLongeur ;
	double briqueTriangulaireHauteur ;
	Color briqueTriangulaireCouleur ;
	double briqueTriangulaireResistence ;
	double balleXInitialeRelative ;
	double balleYInitialeRelative ;
	Color balleCouleur ;
	double balleDirectionInitialeCoefficient ;
	double balleVitesse ;
	double raquetteXInitialeRelative ;
	double raquetteYInitialeRelative ;
	double raquetteLongeur ;
	double raquetteHauteur ;
	Color raquetteCouleur ;
	Configuration () ;
	double getDouble ( const std::string & ) const ;
} ;

#endif
