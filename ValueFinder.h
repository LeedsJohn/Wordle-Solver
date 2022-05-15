// John Leeds
// 5/8/2022
// ValueFinder.h
// Header file for class ValueFInder

#ifndef VALUEFINDER_HDR
#define VALUEFINDER_HDR
#include <string>
#include <map>
#include "Word.h"

class ValueFinder
{
public:
    /*
    Constructor
    */
    ValueFinder(const std::vector<Word> &words);

    /*
    generateFrequencies
    Takes a word list and determines how frequently a character occurs
    and how many words would share a green
    */
    void generateFrequencies(const std::vector<Word> &words);

    /*
    scoreWord
    Receives a string
    Returns an integer representing its value
    */
    int scoreWord(const std::string &w) const;

private:
    std::map<char, int> greens[5];
    std::map<char, int> yellows;

    /*
    checkPrev
    Checks previous characters in a word for a character
    */
   bool checkPrev(char word[], char c) const;
};

#endif