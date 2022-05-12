all: solver test

solver: Solver.o
	g++ Guess.o CharInfo.o Word.o ValueFinder.o WordList.o Solver.o -o solver
test: Test.o
	g++ Guess.o CharInfo.o Word.o ValueFinder.o WordList.o Test.o -o test

Solver.o: WordList.o main.cpp
	g++ -c main.cpp -o Solver.o
Test.o: WordList.o test.cpp
	g++ -c test.cpp -o Test.o

WordList.o: ValueFinder.o WordList.h WordList.cpp
	g++ -c WordList.cpp -o WordList.o
ValueFinder.o: Word.o ValueFinder.h ValueFinder.cpp
	g++ -c ValueFinder.cpp -o ValueFinder.o
Word.o: CharInfo.o Word.cpp Word.h
	g++ -c Word.cpp -o Word.o
CharInfo.o: Guess.o CharInfo.h CharInfo.cpp
	g++ -c CharInfo.cpp -o CharInfo.o
Guess.o: Guess.cpp Guess.h
	g++ -c Guess.cpp -o Guess.o

clean:
	rm *.o test
