// John Leeds
// 5/10/2022
// Word.cpp
// Implementation file for class Word

#include <string>
#include <set>
#include <vector>
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
Returns true if a word should be eliminated based
off of current information
*/
bool Word::checkWord(CharInfo charinfo) const
{
    // return (checkGreens(charinfo.getGreens()) ||
    //     checkYellows(charinfo.getYellows()) ||
    //     checkGrays(charinfo.getGrays(), charinfo.getYellows()) || 
    //     checkWrongPosition(charinfo.getWrongPosition()));
    
}

/*
getWord
Returns the word
*/
const std::string &Word::getWord() const
{
    return word;
}

/*
checkGreen
Helper function for update
Returns true if a word should be eliminated based on having
an incorrect character in a green position
*/
bool Word::checkGreens(const std::vector<char> &greens) const
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
Returns true if a word should be eliminated based on not
including a character that is known in the word.
*/
bool Word::checkYellows(const std::set<char> &yellows) const
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
                break;
            }
        }
        if (!flag)
        {
            return true;
        }
    }
    return false;
}

/*
checkGrays
Helper function for update
Returns true if a character is in grays but not in yellows
*/
bool Word::checkGrays(const std::set<char> &grays, const std::set<char> &yellows) const
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

/*
checkWrongPosition
Helper function for update
Returns true if there is a character that is yellow but in the wrong position
*/
bool Word::checkWrongPosition(const std::vector<std::set<char>> &wrongPos) const{
    for ( int i = 0; i<5; i++ ){
        if ( wrongPos[i].find(word[i]) != wrongPos[i].end() ){
            return true;
        }
    }
    return false;
}