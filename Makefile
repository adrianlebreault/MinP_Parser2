default:
	bison -yd parser.y
	flex -l PI1Scanner.l
	g++ -o test y.tab.c lex.yy.c main.cpp -lm

clear:
	rm -rf lex.yy.c
	rm -rf y.tab.c
	rm -rf y.tab.h
	rm -rf test Declaraciones.txt Usos.txt Errores-Declaracion-uso.txt Errores-de-tipos.txt
