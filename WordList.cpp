// John Leeds
// 5/10/2022
// WordList.cpp
// Implementation file for class WordList

#include <string>
#include <vector>
#include <fstream> // used for reading file
#include "CharInfo.h"
#include "Word.h"
#include "WordList.h"

/*
Constructor
Receives a file name to create the word list from
*/
WordList::WordList(std::string& fileName){
    words = readFile(fileName)
}

/*
updateWords
Receives CharInfo
Removes unusable words from words
*/
int WordList::updateWords(CharInfo charinfo);

/*
getBestWord
Returns the word with the highest word value
*/
std::string WordList::getBestWord() const;

/*
readFile
Receives a file name to create a word list
Adds all the words to words
*/
void WordList::readFile(std::string& fileName)
{
    std::ifstream myFile(fileName);
    std::string str;
    while (getline(myFile, str))
    {
        words.push_back(str);
    }
    myFile.close();
}