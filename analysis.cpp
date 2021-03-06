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

std::string GUESS_PATH = "data/guesses.txt";
std::string ANSWER_PATH = "data/answers.txt";

int playRound(std::string ans, WordList guesses, WordList answers)
{
    // WordList guesses(GUESS_PATH);
    // WordList answers(ANSWER_PATH);
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
    WordList guess_words(GUESS_PATH);
    WordList words(ANSWER_PATH);
    std::vector<Word> wordList = words.getWords();
    int numWords = 0;
    int totalRounds = 0;
    int overSix = 0;
    int maxGuesses = 0;
    for ( auto &word : wordList ){
    // for ( int i = 0; i<20; i++ ){
        // Word word = wordList[i];
        // std::cout << word.getWord() << '\n';
        numWords++;
        int guesses = playRound(word.getWord(), guess_words, words);
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
        //std::cout << "Word: " << word.getWord() << "\tnumWords: " << numWords << "\ttotalRounds: " << totalRounds << '\n';
        // break;
    }
    std::cout << "numWords: " << numWords << "\ttotalRounds: " << totalRounds << "\tmaxGuesses: " << maxGuesses << '\n';
}