#ifndef __TERRAIN_H
#define __TERRAIN_H

#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include "configuration.h"

#include <cstddef>

class Terrain {
	private :
	size_t x ;
	size_t y ;
	size_t longeur ;
	size_t hauteur ;
	size_t briqueLignes ;
	size_t briqueColonnes ;
	Brique briques [ 3 ] [ 6 ] ;
	public :
	Raquette raquette ;
	Balle balle ;
	Terrain ( const Configuration & ) ;
	void setX ( const size_t &xTerrain ) ;
	void setY ( const size_t &yTerrain ) ;
	void setLongeur ( const size_t &longeurTerrain ) ;
	void setHauteur ( const size_t &hauteurTerrain ) ;
	void setBriqueLignes ( const size_t &briqueLignesTerrain ) ;
	void setBriqueColonnes ( const size_t &briqueColonnesTerrain ) ;
	size_t getX () const ;
	size_t getY () const ;
	size_t getLongeur () const ;
	size_t getHauteur () const ;
	size_t getBriqueLignes () const ;
	size_t getBriqueColonnes () const ;
	Brique &getBrique ( const size_t & , const size_t & ) ;
	bool balleHitBrique () ;
	bool balleHitRaquette () const ;
	int balleHitMur () const ;
	void changerDirectionBalle () ;
	bool ballePerdu () const ;
	void reset ( const Configuration & ) ;
} ;

#endif
