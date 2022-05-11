// John Leeds
// 5/8/2022
// WordList.h
// Header file for class WordList

#ifndef WORDLIST_HDR
#define WORDLIST_HDR
#include <string>
#include <vector>
#include "CharInfo.h"
#include "Word.h"

class WordList{
    public:
        /*
        Constructor
        Receives a file name to create the word list from
        */
        WordList(std::string& fileName);
        
        /*
        updateWords
        Receives CharInfo
        Removes unusable words from words
        */
        int updateWords(CharInfo charinfo);

        /*
        getBestWord
        Returns the word with the highest word value
        */
        std::string getBestWord() const;

    private:
        std::vector<Word> words;

        /*
        readFile
        Receives a file name to create a word list
        Adds all the words to words
        */
        void readFile(std::string& fileName);
};

#endif