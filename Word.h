// John Leeds
// 5/8/2022
// Word.h
// Header file for class Word

#ifndef WORD_HDR
#define WORD_HDR
#include <string>
#include <set>
#include <vector>
#include "CharInfo.h"

class Word
{
public:
    /*
    Default constructor
    Sets the word as "*****"
    */
   Word();

    /*
    Constructor
    Receives a 5 letter word
    */
    Word(std::string &w);

    /*
    checkWord
    Receives CharInfo
    Returns true if a word should be eliminated based
    off of current information
    */
    bool checkWord(CharInfo charinfo) const;

    /*
    getWord
    Returns the word
    */
    const std::string &getWord() const;

private:
    std::string word;

    /*
    checkGreen
    Helper function for update
    Returns true if a word should be eliminated based on having
    an incorrect character in a green position
    */
    bool checkGreens(const std::vector<char> &greens) const;

    /*
    checkYellow
    Helper function for update
    Returns true if a word should be eliminated based on not
    including a character that is known in the word.
    */
    bool checkYellows(const std::set<char> &yellows) const;

    /*
    checkGrays
    Helper function for update
    Returns true if a character is in grays but not in yellows
    */
    bool checkGrays(const std::set<char> &grays, const std::set<char> &yellows) const;

    /*
    checkWrongPosition
    Helper function for update
    Returns true if there is a character that is yellow but in the wrong position
    */
    bool checkWrongPosition(const std::vector<std::set<char>> &wrongPos) const;
};

#endif