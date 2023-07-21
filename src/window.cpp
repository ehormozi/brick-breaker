#include "../header/window.h"

void init_colors(void)
{
  start_color();
  init_pair(WBLACK,   COLOR_WHITE, COLOR_BLACK);
  init_pair(WCYAN,    COLOR_WHITE, COLOR_CYAN);
  init_pair(WBLUE,    COLOR_WHITE, COLOR_BLUE);
  init_pair(WYELLOW,  COLOR_WHITE, COLOR_YELLOW);  
  init_pair(WGREEN,   COLOR_WHITE, COLOR_GREEN); 
  init_pair(WMAGENTA, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(WRED,     COLOR_WHITE, COLOR_RED);  
  init_pair(BWHITE,   COLOR_BLACK, COLOR_WHITE);
  init_pair(BCYAN,    COLOR_BLACK, COLOR_CYAN);
  init_pair(BBLUE,    COLOR_BLACK, COLOR_BLUE);
  init_pair(BYELLOW,  COLOR_BLACK, COLOR_YELLOW);  
  init_pair(BGREEN,   COLOR_BLACK, COLOR_GREEN); 
  init_pair(BMAGENTA, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(BRED,     COLOR_BLACK, COLOR_RED);  
}


void startProgramX() {
  initscr();             // initialize curses
  cbreak();              // pass key presses to program, but not signals
  noecho();              // don't echo key presses to screen
  keypad(stdscr, TRUE);  // allow arrow keys
  timeout(0);            // no blocking on getch()
  curs_set(0);           // set the cursor to invisible
  init_colors();
}

void stopProgramX() {
  refresh();
  getch();    
  endwin();
}



void Window::update() const{
  wrefresh(win);
  wrefresh(frame);
  refresh();
}


Window::Window(size_t h,size_t w, size_t x, size_t y, char c)
  : height(h), width(w), startx(x), starty(y), bord(c)
{
  colorwin=WCYAN;
  colorframe=WBLACK;
  frame=newwin(h+2,w+2,y,x);
  win=subwin(frame,h,w,y+1,x+1);
  wbkgd(frame,COLOR_PAIR(colorwin));
  wbkgd(win,COLOR_PAIR(colorframe));
  wborder(frame, c,c,c,c,c,c,c,c);
  wattron(win,COLOR_PAIR(colorwin));
  wattron(frame,COLOR_PAIR(colorframe));
  update();
}

Window::~Window(){
  wborder(frame, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wattroff(win,COLOR_PAIR(colorwin));
  wattroff(win,COLOR_PAIR(colorframe));
  werase(win);
  update();
  delwin(win); 
}

void Window::print(size_t x, size_t y, std::string s, Color c) const {
  wattron(win,COLOR_PAIR(c));
  mvwprintw(win,y,x,s.c_str());
  wattroff(win,COLOR_PAIR(c));
  update();  
}
void Window::print(size_t x, size_t y, char s, Color c) const{
  wattron(win,COLOR_PAIR(c));
  mvwaddch(win,y,x,s);
  wattroff(win,COLOR_PAIR(c));
  update();
}
void Window::print(size_t x, size_t y, std::string s) const{
  mvwprintw(win,y,x,s.c_str());
  update();  
}
void Window::print(size_t x, size_t y, char s) const{
  mvwaddch(win,y,x,s);
  update();  
}


size_t Window::getX() const { return startx;} 
size_t Window::getY() const { return starty;} 
size_t Window::getHauteur() const { return height;} 
size_t Window::getLargeur() const { return width;}  
Color Window::getCouleurBordure() const{ return colorframe;}
Color Window::getCouleurFenetre() const{ return colorwin;}
void Window::setCouleurBordure(Color c){
  colorframe=c;
  wattron(frame,COLOR_PAIR(colorframe));
  wborder(frame, bord,bord,bord,bord,bord,bord,bord,bord);
  update();
}
void Window::setCouleurFenetre(Color c){
  colorwin=c;
  wattron(win,COLOR_PAIR(colorwin));
  wbkgd(win,COLOR_PAIR(colorwin));
  update();  
}

void Window::clear() const{  werase(win); update(); }

void Window::print ( Brique brique ) {
	std::string briqueString = "     " ;
	print ( brique . getX () , brique . getY () , briqueString , WRED ) ;
}

void Window::print ( Raquette raquette ) {
	size_t longeurRaquette = raquette . getLongeur () ;
	char* tmp = new char [ longeurRaquette ] ;
	for ( size_t i = 0 ; i < longeurRaquette ; i++ ) {
		tmp [ i ] = ' ' ;
	}
	std::string raquetteString = tmp ;
	print ( raquette . getX () , raquette . getY () , raquetteString , WBLUE ) ;
}

void Window::print ( Balle balle ) {
	print ( balle . getX () , balle . getY () , 'O' ) ;
}

void Window::print ( Menu menu ) {
	for ( size_t i = menu . getFirstOption () ; i < 7 ; i++ ) {
		print ( menu . getX () + 2 , menu . getY () + ( 3 * i + 1 ) - 1 , menu . getOption ( i ) ) ;
	}
	print ( menu . selector ) ;
}

void Window::print ( Selector selector ) {
	print ( selector . getX () , selector . getY () , ">>" , WGREEN ) ;
}

void Window::erase ( Raquette raquette ) {
	size_t longeurRaquette = raquette . getLongeur () ;
	char* tmp = new char [ longeurRaquette ] ;
	for ( size_t i = 0 ; i < longeurRaquette ; i++ ) {
		tmp [ i ] = ' ' ;
	}
	std::string raquetteString = tmp ;
	print ( raquette . getX () , raquette . getY () , raquetteString ) ;
}

void Window::erase ( Brique brique ) {
	size_t longeurBrique = brique . getLongeur () ;
	char* tmp = new char [ longeurBrique ] ;
	for ( size_t i = 0 ; i < longeurBrique ; i++ ) {
		tmp [ i ] = ' ' ;
	}
	std::string briqueString = tmp ;
	print ( brique . getX () , brique . getY () , briqueString ) ;
}

void Window::erase ( Balle balle ) {
	print ( balle . getX () , balle . getY () , ' ' ) ;
}

void Window::erase ( Selector selector ) {
	print ( selector . getX () , selector . getY () , "  " ) ;
}

void Window::erase ( size_t x , size_t y , size_t longeur ) {
	for ( size_t i = x ; i < x + longeur ; i++ ) {
		print ( i , y , ' ' , WBLACK ) ;
	}
}
