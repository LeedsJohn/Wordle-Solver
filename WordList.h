// John Leeds
// 5/8/2022
// WordList.h
// Header file for class WordList

#ifndef WORDLIST_HDR
#define WORDLIST_HDR
#include <string>
#include <vector>
#include "CharInfo.h"
#include "ValueFinder.h"
#include "Word.h"

class WordList
{
public:
    /*
    Constructor
    Receives a file name to create the word list from
    */
    WordList(const std::string &fileName);

    /*
    updateWords
    Receives CharInfo
    Removes unusable words from words
    */
    int updateWords(const CharInfo &charinfo);

    /*
    getBestWord
    Returns the word with the highest word value
    */
    const std::string &getBestWord(const ValueFinder &evaluator) const;

    /*
    getWords
    Returns the wordList
    */
    const std::vector<Word> &getWords() const;

    /*
    length
    Returns the length of the wordList
    */
    int length() const;

private:
    std::vector<Word> words;

    /*
    readFile
    Receives a file name to create a word list
    Adds all the words to words
    */
    void readFile(const std::string &fileName);
};

#endif