// John Leeds
// 5/8/2022
// Word.h
// Header file for class Word

#ifndef WORD_HDR
#define WORD_HDR
#include <string>
#include <set>
#include "CharInfo.h"

class Word
{
public:
    /*
    Constructor
    Receives a 5 letter word
    */
    Word(std::string &w);

    /*
    checkWord
    Receives CharInfo
    Returns true if the word could be a possible answer
    Else, false
    */
    bool checkWord(CharInfo charinfo) const;

    /*
    getWordScore
    Receives CharInfo
    Returns the score of the word based off of how many
    potential green, yellow, and gray letters it has
    */
    int getWordScore(CharInfo charinfo) const;

    /*
    getWord
    Returns the word
    */
    std::string getWord() const;

private:
    std::string word;

    /*
    checkGreen
    Helper function for update
    Returns true if a word should be eliminated based on having
    an incorrect character in a green position
    */
    bool checkGreens(char greens[5]) const;

    /*
    checkYellow
    Helper function for update
    Returns true if
    */
    bool checkYellows(std::set<char> yellows) const;

    /*
    checkGrays
    Helper function for update
    Returns true if a character is in grays but not in yellows
    */
    bool checkGrays(std::set<char> grays, std::set<char> yellows) const;
};

#endif