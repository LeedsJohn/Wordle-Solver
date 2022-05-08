// John Leeds
// 5/8/2022
// Word.h
// Header file for class Word

#ifndef WORD_HDR
#define WORD_HDR
#include <string>
#include "CharInfo.h"

class Word{
    public:
        /*
        Constructor
        Receives a 5 letter word
        */
        Word(std::string& w);

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
        string& getWord() const;

    private:
        std::string& word;
};

#endif