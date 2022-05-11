// John Leeds
// 5/8/2022
// CharInfo.h
// Header file for class CharInfo

#include <map>
#include <string>
#include "Guess.h"
#include "CharInfo.h"

/*
constructor
*/
CharInfo::CharInfo(){
    int x = 5+5; // TODO figure out how this should be written
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
            grays.insert({word[i], true});
        }
        else if (result[i] == 'Y')
        {
            yellows.insert({word[i], true});
        }
        else
        {
            greens[i] = word[i];
        }
    }
}