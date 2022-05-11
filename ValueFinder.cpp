// John Leeds
// 5/11/2022
// ValueFinder.cpp
// Implementation file for class ValueFinder

#include <string>
#include <map>
#include <vector>
#include "Word.h"
#include "ValueFinder.h"

/*
Constructor
*/
ValueFinder(){

}

/*
generateFrequencies
Takes a word list and determines how frequently a character occurs
and how many words would share a green
*/
void generateFrequencies(std::vector<Word> words)
{
    for (size_t i = 0; i < words.size(); i++)
    {
        std::string curWord = words[i].getWord();
        for (int j = 0; j < 5; j++)
        {
            greens[j][curWord[j]]++;
            yellows[curWord[j]]++;
        }
    }
}

/*
scoreWord
Receives a string
Returns an integer representing its value
*/
int scoreWord(std::string &w) const
{
    int score = 0;
    for (int i = 0; i < 5; i++)
    {
        if (greens[i].find(w[i]) != greens[i].end())
        {
            score += greens[i][w[i]] * 2;
        }
        if (yellows[i].find(w[i]) != yellows.end())
        {
            score += yellows[w[i]];
        }
    }
    return score;
}