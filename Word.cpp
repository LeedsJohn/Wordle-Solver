// John Leeds
// 5/10/2022
// Word.cpp
// Implementation file for class Word

#include <string>
#include "CharInfo.h"
#include "Word.h"

/*
Constructor
Receives a 5 letter word
*/
Word::Word(std::string& w){
    word = w;
}

/*
checkWord
Receives CharInfo
Returns true if the word could be a possible answer
Else, false
*/
bool Word::checkWord(CharInfo charinfo) const;

/*
getWordScore
Receives CharInfo
Returns the score of the word based off of how many
potential green, yellow, and gray letters it has
*/
int Word::getWordScore(CharInfo charinfo) const;

/*
getWord
Returns the word
*/
std::string Word::getWord() const{
    return word;
}