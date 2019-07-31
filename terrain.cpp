#include <cmath>
#include "terrain.h"

Terrain::Terrain ( const Configuration &configuration ) : raquette ( configuration ) , balle ( configuration ) {
	setX ( configuration . terrainX ) ;
	setY ( configuration . terrainY ) ;
	setLongeur ( configuration . terrainLongeur ) ;
	setHauteur ( configuration . terrainHauteur ) ;
	setBriqueLignes ( configuration . terrainBriqueLignes ) ;
	setBriqueColonnes ( configuration . terrainBriqueColonnes ) ;
	raquette . setX ( getLongeur () * configuration . raquetteXInitialeRelative ) ;
	raquette . setY ( getHauteur () * configuration . raquetteYInitialeRelative ) ;
	raquette . setMaxX ( getLongeur () - raquette . getLongeur () ) ;
	balle . setX ( raquette . getX () + raquette . getLongeur () * configuration . balleXInitialeRelative ) ;
	balle . setY ( raquette . getY () + configuration . balleYInitialeRelative ) ;
	for ( size_t i = 0 ; i < getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < getBriqueColonnes () ; j++ ) {
			getBrique ( i , j ) . setX ( 6 * ( j + 1 ) ) ;
			getBrique ( i , j ) . setY ( 2 * ( i + 1 ) ) ;
			getBrique ( i , j ) . setLongeur ( configuration . briqueRectangulaireLongeur ) ;
			getBrique ( i , j ) . setHauteur ( configuration . briqueRectangulaireHauteur ) ;
			getBrique ( i , j ) . setResistence ( configuration . briqueRectangulaireResistence ) ;
			getBrique ( i , j ) . setResistenceActuelle ( getBrique ( i , j ) . getResistence () ) ;
		}
	}
}

void Terrain::setX ( const size_t &xTerrain ) {
	x = xTerrain ;
}

void Terrain::setY ( const size_t &yTerrain ) {
	y = yTerrain ;
}

void Terrain::setLongeur ( const size_t &longeurTerrain ) {
	longeur = longeurTerrain ;
}

void Terrain::setHauteur ( const size_t &hauteurTerrain ) {
	hauteur = hauteurTerrain ;
}

void Terrain::setBriqueLignes ( const size_t &briqueLignesTerrain ) {
	briqueLignes = briqueLignesTerrain ;
}

void Terrain::setBriqueColonnes ( const size_t &briqueColonnesTerrain ) {
	briqueColonnes = briqueColonnesTerrain ;
}

size_t Terrain::getX () const {
	return x ;
}

size_t Terrain::getY () const {
	return y ;
}

size_t Terrain::getLongeur () const {
	return longeur ;
}

size_t Terrain::getHauteur () const {
	return hauteur ;
}

size_t Terrain::getBriqueLignes () const {
	return briqueLignes ;
}

size_t Terrain::getBriqueColonnes () const {
	return briqueColonnes ;
}

Brique &Terrain::getBrique ( const size_t &i , const size_t &j ) {
	return briques [ i ] [ j ] ;
}

bool Terrain::balleHitBrique () {
	for ( size_t i = 0 ; i < briqueLignes ; i++ ) {
		for ( size_t j = 0 ; j < briqueColonnes ; j++ ) {
			if ( ( ( size_t ) ( balle . getX () ) >= getBrique ( i , j ) . getX () && ( size_t ) ( balle . getX () ) < getBrique ( i , j ) . getX () + getBrique ( i , j ) . getLongeur () ) &&
			( ( size_t ) ( balle . getY () ) == getBrique ( i , j ) . getY () ) ) {
				if ( getBrique ( i , j ) . getResistenceActuelle () != 0 ) {
					getBrique ( i , j ) . setResistenceActuelle ( getBrique ( i , j ) . getResistenceActuelle () - 1 ) ;
				}
				return true ;
			}
		}
	}
	return false ;
}

bool Terrain::balleHitRaquette () const {
	if ( ( ( size_t ) ( balle . getX () ) >= raquette . getX () && ( size_t ) ( balle . getX () ) < raquette . getX () + raquette . getLongeur () ) &&
	( ( size_t ) ( balle . getY () ) == raquette . getY () ) ) {
		return true ;
	}
	return false ;
}

int Terrain::balleHitMur () const {
	if ( balle . getY () < 1 ) {
		return 1 ;
	}
	if ( ( balle . getX () >= getLongeur () - 1 ) || ( balle . getX () < 1 ) ) {
		return 2 ;
	}
	return 0 ;
}

void Terrain::changerDirectionBalle () {
	if ( balleHitBrique () ) {
		balle . setDirection ( - balle . getDirection () ) ;
	}
	if ( balleHitRaquette () ) {
		balle . setDirection ( - balle . getDirection () ) ;
	}
	switch ( balleHitMur () ) {
		case 1 :
			balle . setDirection ( - balle . getDirection () ) ;
		break ;
		case 2 :
			balle . setDirection ( M_PI - balle . getDirection () ) ;
		break ;
	}
}

bool Terrain::ballePerdu () const {
	if ( ( size_t ) ( balle . getY () ) == raquette . getY () ) {
		return true ;
	}
	return false ;
}

void Terrain::reset ( const Configuration &configuration ) {
	raquette . setX ( getLongeur () * configuration . raquetteXInitialeRelative ) ;
	raquette . setY ( getHauteur () * configuration . raquetteYInitialeRelative ) ;
	balle . setX ( raquette . getX () + raquette . getLongeur () * configuration . balleXInitialeRelative ) ;
	balle . setY ( raquette . getY () + configuration . balleYInitialeRelative ) ;
	for ( size_t i = 0 ; i < getBriqueLignes () ; i++ ) {
		for ( size_t j = 0 ; j < getBriqueColonnes () ; j++ ) {
			getBrique ( i , j ) . setResistenceActuelle ( configuration . briqueRectangulaireResistence ) ;
		}
	}
}
