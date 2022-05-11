test: Test.o
	g++ CharInfo.o Guess.o WordList.o CharInfo.o ValueFinder.o Test.o -o test

Test.o: Guess.o WordList.o CharInfo.o ValueFinder.o test.cpp
	g++ -c test.cpp -o Test.o

WordList.o: Word.o ValueFinder.o WordList.h WordList.cpp
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
