#ifndef __WINDOW_H
#define __WINDOW_H

extern "C" {
#include <curses.h>
}
#include <string>
#include <cstddef>
#include "brique.h"
#include "balle.h"
#include "raquette.h"
#include "menu.h"
#include "selector.h"
#include "configuration.h"

// fonction pour demarrer le mode console graphique
void startProgramX();
// fonction pour arreter le mode console graphique
void stopProgramX();


class Window {
 private:
  size_t height,width,startx,starty;
  WINDOW* win, *frame;
  Color colorwin, colorframe;
  char bord;
  void update() const;

 public:

  // constructeur d'un fenetre de hauteur=h, largeur=w dont le coin superieur gauche
  // a pour coordonnée (x,y), le caractère c est utilisé pour définir la bordure
  Window(size_t h,size_t w, size_t x, size_t y, char c='+');

  ~Window();

  // fonction permettant d'afficher une variable s de type (string ou char)
  // à la position (x,y) dans la fenetre.
  // si un couleur est spécifié l'affichage utilise cette couleur, sinon la couleur de la fenêtre est utilisée
  void print(size_t x, size_t y, std::string s, Color c) const;
  void print(size_t x, size_t y, char s, Color c) const;
  void print(size_t x, size_t y, std::string s) const;
  void print(size_t x, size_t y, char s) const; 

  
  // accesseurs
  size_t getX() const;        // récupère l'abscisse du coin supérieur gauche de la fenêtre 
  size_t getY() const;        // récupère l'ordonnée du coin supérieur gauche de la fenêtre 
  size_t getHauteur() const ; // récupère la hauteur de la fenêtre
  size_t getLargeur() const ; // récupère la largeur de la fenêtre

  Color getCouleurBordure() const; // récupère la couleur de la bordure
  Color getCouleurFenetre() const; // récupère la couleur de la fenêtre
  void setCouleurBordure(Color);   // modifie la couleur de la bordure
  void setCouleurFenetre(Color);   // modifie la couleur de la fenêtre (ATTENTION, tout le contenu de la fenêtre prend la couleur)

  void clear() const; // enleve tout le contenu de la fenêtre
  
  void print ( Raquette ) ;
  void print ( Balle ) ;
  void print ( Brique ) ;
  void print ( Menu ) ;
  void print ( Selector ) ;
  
  void erase ( Raquette ) ;
  void erase ( Balle ) ;
  void erase ( Brique ) ;
  void erase ( Selector ) ;
  void erase ( size_t , size_t , size_t ) ;

};











#endif
