#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Word.h"
#include "Guess.h"
#include "WordList.h"
#include "ValueFinder.h"
#include "CharInfo.h"

std::string GUESS_PATH = "data/guesses.txt";
std::string ANSWER_PATH = "data/answers.txt";

int main()
{
    WordList guesses(GUESS_PATH);
    WordList answers(ANSWER_PATH);
    CharInfo ci;
    Guess g;
    int round = 0;
    while (answers.length() != 0 && g.getResult() != "GGGGG")
    {
        ValueFinder vf(answers.getWords());
        std::cout << "-------------------\nRound " << round+1 << ":\n";
        std::cout << "Possible guesses: " << guesses.length() << "\nPossible answers: " << answers.length() << '\n';
        std::cout << "Best guess: ";
        if (answers.length() <= 10)
        {
            std::string guessWord = answers.getBestWord(vf);
            std::cout << guessWord << '\n';
        }
        else
        {
            std::string guessWord = guesses.getBestWord(vf);
            std::cout << guessWord << '\n';
        }
        g.inputInfo();
        ci.update(g);
        round++;
        std::cout << "Number of guesses eliminated: " << guesses.updateWords(ci) << "\nNumber of answers eliminated: " << answers.updateWords(ci) << '\n';
    }
    std::cout << "Found " << g.getWord() << " in " << round << " guesses.\n";
}