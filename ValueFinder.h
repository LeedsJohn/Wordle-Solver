// John Leeds
// 5/8/2022
// ValueFinder.h
// Header file for class ValueFInder

#ifndef VALUEFINDER_HDR
#define VALUEFINDER_HDR
#include <string>
#include <map>
#include "WordList.h"

class ValueFinder{
    public:
        /*
        Constructor
        */
        ValueFinder();

        /*
        generateFrequencies
        Takes a word list and determines how frequently a character occurs
        and how many words would share a green
        */
        void generateFrequencies(WordList wordlist);

        /*
        scoreWord
        Receives a string
        Returns an integer representing its value
        */
        int scoreWord(std::string& w) const;

    private:
        std::map<char, int> yellows;
        std::map<char, int> greens[5];
};

#endif