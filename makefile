all: solver analysis

analysis: Analysis.o
	g++ Node.o LinkedList.o Guess.o CharInfo.o Word.o ValueFinder.o WordList.o Analysis.o -o analysis
solver: Solver.o
	g++ Node.o LinkedList.o Guess.o CharInfo.o Word.o ValueFinder.o WordList.o Solver.o -o solver

Analysis.o: WordList.o analysis.cpp
	g++ -c analysis.cpp -o Analysis.o
Solver.o: WordList.o main.cpp
	g++ -c main.cpp -o Solver.o

WordList.o: ValueFinder.o WordList.h WordList.cpp
	g++ -c WordList.cpp -o WordList.o
ValueFinder.o: Word.o LinkedList.o ValueFinder.h ValueFinder.cpp
	g++ -c ValueFinder.cpp -o ValueFinder.o
Word.o: CharInfo.o Word.cpp Word.h
	g++ -c Word.cpp -o Word.o
CharInfo.o: Guess.o CharInfo.h CharInfo.cpp
	g++ -c CharInfo.cpp -o CharInfo.o
Guess.o: Guess.cpp Guess.h
	g++ -c Guess.cpp -o Guess.o

LinkedList.o: Node.o LinkedList.h LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o
Node.o: Node.h Node.cpp
	g++ -c Node.cpp -o Node.o

clean:
	rm *.o test solver analysis
