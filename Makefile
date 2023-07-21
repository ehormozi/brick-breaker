All : CasseBrique

CasseBrique : tmp/balle.o tmp/brique.o tmp/configuration.o tmp/jeu.o tmp/joueur.o tmp/main.o tmp/menu.o tmp/niveau.o tmp/partie.o tmp/raquette.o tmp/selector.o tmp/terrain.o tmp/window.o
	        g++ -Wall tmp/*.o -o CasseBrique -lncurses

tmp/balle.o : src/balle.cpp
	        g++ -Wall -c src/balle.cpp -o tmp/balle.o

tmp/brique.o : src/brique.cpp
	        g++ -Wall -c src/brique.cpp -o tmp/brique.o

tmp/configuration.o : src/configuration.cpp
	        g++ -Wall -c src/configuration.cpp -o tmp/configuration.o

tmp/jeu.o : src/jeu.cpp
	        g++ -Wall -c src/jeu.cpp -o tmp/jeu.o

tmp/joueur.o : src/joueur.cpp
	        g++ -Wall -c src/joueur.cpp -o tmp/joueur.o

tmp/main.o : src/main.cpp
	        g++ -Wall -c src/main.cpp -o tmp/main.o

tmp/menu.o : src/menu.cpp
	        g++ -Wall -c src/menu.cpp -o tmp/menu.o

tmp/niveau.o : src/niveau.cpp
	        g++ -Wall -c src/niveau.cpp -o tmp/niveau.o

tmp/partie.o : src/partie.cpp
	        g++ -Wall -c src/partie.cpp -o tmp/partie.o

tmp/raquette.o : src/raquette.cpp
	        g++ -Wall -c src/raquette.cpp -o tmp/raquette.o

tmp/selector.o : src/selector.cpp
	        g++ -Wall -c src/selector.cpp -o tmp/selector.o

tmp/terrain.o : src/terrain.cpp
	        g++ -Wall -c src/terrain.cpp -o tmp/terrain.o

tmp/window.o : src/window.cpp
	        g++ -Wall -c src/window.cpp -o tmp/window.o

clear:
	        rm tmp/*.o
	        rm CasseBrique

