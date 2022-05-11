// John Leeds
// 5/10/2022
// Word.cpp
// Implementation file for class Word

#include <string>
#include <set>
#include <iterator>
#include "CharInfo.h"
#include "Word.h"

/*
Constructor
Receives a 5 letter word
*/
Word::Word(std::string &w)
{
    word = w;
}

/*
checkWord
Receives CharInfo
Returns true if the word could be a possible answer
Else, false
*/
bool Word::checkWord(CharInfo charinfo) const
{
    return ( checkGreens(charinfo.getGreens() ||
                checkYellows(charinfo.getYellows() ||
                checkGrays(charinfo.getGrays(), charinfo.getYellows());
}

/*
getWordScore
Receives CharInfo
Returns the score of the word based off of how many
potential green, yellow, and gray letters it has
*/
int Word::getWordScore(CharInfo charinfo) const;

/*
getWord
Returns the word
*/
std::string Word::getWord() const
{
    return word;
}

/*
checkGreen
Helper function for update
Returns true if a word should be eliminated based on having
an incorrect character in a green position
*/
bool Word::checkGreens(char greens[5])
{
    for (int i = 0; i < 5; i++)
    {
        if (greens[i] != '*' && greens[i] != word[i])
        {
            return true;
        }
    }
    return false;
}

/*
checkYellow
Helper function for update
Returns true if
*/
bool Word::checkYellows(std::set<char> yellows)
{
    std::set<char>::iterator itr;
    for (itr = yellows.begin(); itr != yellows.end(); itr++)
    {
        bool flag = false;
        for (int i = 0; i < 5; i++)
        {
            if (word[i] == *itr)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            return false;
        }
    }
    return true;
}

/*
checkGrays
Helper function for update
Returns true if a character is in grays but not in yellows
*/
bool Word::checkGrays(std::set<char> grays, std::set<char> yellows)
{
    for (int i = 0; i < 5; i++)
    {
        if (grays.find(word[i]) != grays.end() &&
            yellows.find(word[i]) == yellows.end())
        {
            return true;
        }
    }
    return false;
}