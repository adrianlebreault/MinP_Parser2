all:
	bison -yd parse.y
	flex -l lexer.l
	g++ -o test y.tab.c lex.yy.c main.cpp -lm

test:
	./test < Test_SBT2.txt > Resultado_Test_SBT2.txt
	./test < Test_SBT3.txt > Resultado_Test_SBT3.txt
	./test < Test_SBT1.txt > Resultado_Test_SBT1.txt

clear:
	rm -rf lex.yy.c
	rm -rf y.tab.c
	rm -rf y.tab.h
	rm -rf test Declaraciones.txt Usos.txt Errores-Declaracion-uso.txt Errores-de-tipos.txt
