test: engine.o suggest.o test.o
	clang -o test engine.o suggest.o test.o

engine.o: engine.c
	clang -c engine.c -o engine.o
suggest.o: suggest.c
	clang -c suggest.c -o suggest.o
test.o: test.c
	clang -c test.c -o test.o
