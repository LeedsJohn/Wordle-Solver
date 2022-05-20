#include <chrono> // measuring how long stuff takes

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Word.h"
#include "Guess.h"
#include "WordList.h"
#include "ValueFinder.h"
#include "CharInfo.h"
#include "LinkedList.h"
#include "Node.h"

std::string GUESS_PATH = "data/guesses.txt";
std::string ANSWER_PATH = "data/answers.txt";

int playRound(std::string ans)
{
    WordList guesses(GUESS_PATH);
    WordList answers(ANSWER_PATH);
    CharInfo ci;
    Guess g;
    int round = 0;
    while (answers.length() != 0 && g.getResult() != "GGGGG" && round < 20)
    {
        ValueFinder vf(answers.getWords());
        std::string bestGuess = "";
        if (answers.length() <= 10)
        {
            bestGuess = answers.getBestWord(vf);
        }
        else
        {
            //auto startGBW = std::chrono::high_resolution_clock::now();
            bestGuess = guesses.getBestWord(vf);
            //auto stopGBW = std::chrono::high_resolution_clock::now();
            //auto durationGBW = std::chrono::duration_cast<std::chrono::microseconds>(stopGBW-startGBW);
            //std::cout << "getbestword: " << durationGBW.count() << '\n';
        }
        g.inputInfo(bestGuess, ans);
        ci.update(g);
        //auto startUW = std::chrono::high_resolution_clock::now();
        guesses.updateWords(ci);
        answers.updateWords(ci);
        //auto stopUW = std::chrono::high_resolution_clock::now();
        //auto durationUW = std::chrono::duration_cast<std::chrono::microseconds>(stopUW-startUW);
        //std::cout << "update words: " << durationUW.count() << '\n';
        round++;
    }
    return round;
}

int main()
{
    WordList words(ANSWER_PATH);
    Node* traverse = words.getWords().getHead();
    int numWords = 0;
    int totalRounds = 0;
    int overSix = 0;
    int maxGuesses = 0;
    while ( traverse ){
        Word word = traverse->val;
        numWords++;
        int guesses = playRound(word.getWord());
        totalRounds += guesses;
        if ( guesses > maxGuesses ){
            maxGuesses = guesses;
        }
        if ( guesses > 6 ){
            std::cout << "lost - " << guesses << " guesses. Word: " << word.getWord() << '\n';
        }
        if ( numWords%500 == 0 ){
            std::cout << numWords << '\t' << totalRounds << '\n';
        }
        traverse = traverse->next;
        //std::cout << "Word: " << word.getWord() << "\tnumWords: " << numWords << "\ttotalRounds: " << totalRounds << '\n';
        // break;
    }
    std::cout << "numWords: " << numWords << "\ttotalRounds: " << totalRounds << "\tmaxGuesses: " << maxGuesses << '\n';
}