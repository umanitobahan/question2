test: engine.o suggest.o test.o
	clang -o test engine.o suggest.o test.o

engine.o: engine.c
	clang -c engine.c -o engine.o
suggest.o: suggest.c
	clang -c suggest.c -o suggest.o
test.o: test.c
	clang -c test.c -o test.o
clean:
	rm -rf test
	rm -rf engine.o
	rm -rf suggest.o
	rm -rf test.o
