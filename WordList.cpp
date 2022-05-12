// John Leeds
// 5/10/2022
// WordList.cpp
// Implementation file for class WordList

#include <string>
#include <vector>
#include <fstream> // used for reading file
#include "CharInfo.h"
#include "ValueFinder.h"
#include "Word.h"
#include "WordList.h"

/*
Constructor
Receives a file name to create the word list from
*/
WordList::WordList(std::string &fileName)
{
    readFile(fileName);
}

/*
updateWords
Receives CharInfo
Removes unusable words from words
*/
int WordList::updateWords(CharInfo charinfo)
{
    int count = 0;
    auto it = words.begin();
    while (it != words.end())
    {
        if (it->checkWord(charinfo))
        { // TODO: this might not work :D
            count++;
            it = words.erase(it);
        }
        else
        {
            it++;
        }
    }
    return count;
}

/*
getBestWord
Returns the word with the highest word value
*/
std::string WordList::getBestWord(ValueFinder evaluator) const
{
    int maxScore = 0;
    Word bestWord = words[0];
    // TODO: change to using an iterator?
    for (size_t i = 0; i < words.size(); i++)
    {
        Word curWord = words[i];
        int curScore = evaluator.scoreWord(curWord.getWord());
        if (curScore > maxScore)
        {
            maxScore = curScore;
            bestWord = words[i];
        }
    }
    return bestWord.getWord();
}

/*
getWords
Returns the wordList
*/
std::vector<Word> WordList::getWords() const
{
    return words;
}

/*
length
Returns the length of the wordList
*/
int WordList::length() const
{
    return words.size();
}

/*
readFile
Receives a file name to create a word list
Adds all the words to words
*/
void WordList::readFile(std::string &fileName)
{
    std::ifstream myFile(fileName);
    std::string str;
    while (getline(myFile, str))
    {
        words.push_back(str);
    }
    myFile.close();
}