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
WordList::WordList(const std::string &fileName)
{
    readFile(fileName);
}

/*
updateWords
Receives CharInfo
Removes unusable words from words
*/
int WordList::updateWords(const CharInfo &charinfo)
{
    Node* traverse = words.getHead();
    Node* prev = nullptr;
    int oldLength = words.getLength();
    while ( traverse ){
        if ( traverse->val.checkWord(charinfo)){
            traverse = traverse->next;
            words.erase(prev);
        }
        else{
            prev = traverse;
            traverse = traverse->next;
        }
    }
    return oldLength - words.getLength();

    // std::vector<Word> oldWords = words;
    // words.clear();
    // int count = 0;
    // auto it = oldWords.begin();
    // while (it != oldWords.end())
    // {
    //     if (!it->checkWord(charinfo))
    //     { // TODO: this might not work :D
    //         count++;
    //         words.push_back(*it);
    //     }
    //     it++;
    // }
    // return count;
}

/*
getBestWord
Returns the word with the highest word value
*/
const std::string WordList::getBestWord(const ValueFinder &evaluator) const
{
    int maxScore = 0;
    std::string bestWord = words.getHead()->val.getWord();
    Node* traverse = words.getHead();
    while (traverse)
    {
        int curScore = evaluator.scoreWord(traverse->val.getWord());
        if (curScore > maxScore)
        {
            maxScore = curScore;
            bestWord = traverse->val.getWord();
        }
        traverse = traverse->next;
    }
    return bestWord;
}

/*
getWords
Returns the wordList
*/
const LinkedList &WordList::getWords() const
{
    return words;
}

/*
length
Returns the length of the wordList
*/
int WordList::length() const
{
    return words.getLength();
}

/*
readFile
Receives a file name to create a word list
Adds all the words to words
*/
void WordList::readFile(const std::string &fileName)
{
    std::ifstream myFile(fileName);
    std::string str;
    while (getline(myFile, str))
    {
        Word newWord(str);
        words.add(newWord);
    }
    myFile.close();
}