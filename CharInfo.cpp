// John Leeds
// 5/8/2022
// CharInfo.h
// Header file for class CharInfo

#include <set>
#include <vector>
#include <string>
#include "Guess.h"
#include "CharInfo.h"

/*
constructor
*/
CharInfo::CharInfo()
{
    for (int i = 0; i < 5; i++)
    {
        greens.push_back('*');
    }
}

/*
update
Receives a Guess
Adds in the info to greens, yellows, and greys
*/
void CharInfo::update(Guess &g)
{
    std::string word = g.getWord();
    std::string result = g.getResult();
    for (size_t i = 0; i < 5; i++)
    {
        if (result[i] == 'X')
        {
            grays.insert(word[i]);
        }
        else if (result[i] == 'Y')
        {
            yellows.insert(word[i]);
        }
        else
        {
            greens[i] = word[i];
            yellows.insert(word[i]);
        }
    }
}

// GETTERS
std::vector<char> CharInfo::getGreens() const
{
    return greens;
}

std::set<char> CharInfo::getYellows() const
{
    return yellows;
}

std::set<char> CharInfo::getGrays() const
{
    return grays;
}