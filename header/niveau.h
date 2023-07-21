#ifndef __NIVEAU_H
#define __NIVEAU_H

#include "configuration.h"

class Niveau {
	private :
	unsigned int nbNiveau ;
	public :
	Niveau () ;
	void setNbNiveau ( unsigned int nbNiveauNiveau ) ;
	unsigned int getNbNiveau () ;
} ;

#endif