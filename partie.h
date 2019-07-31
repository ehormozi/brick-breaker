#ifndef __PARTIE_H
#define __PARTIE_H

#include <cstddef>
#include "niveau.h"
#include "configuration.h"

class Partie {
	private :
	size_t score ;
	size_t nbBalles ;
	bool enCours ;
	const size_t scoreInitiale = 0 ;
	const bool enCoursInitiale = false ;
	public :
	Niveau niveau ;
	Partie ( const Configuration & ) ;
	void setScore ( size_t scorePartie ) ;
	void setNbBalles ( size_t ) ;
	void setEnCours ( bool estFiniPartie ) ;
	size_t getScore () ;
	size_t getNbBalles () ;
	bool getEnCours () ;
	size_t getScoreInitiale () const ;
	bool getEnCoursInitiale () const ;
} ;

#endif
