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
ValueFinder::ValueFinder(std::vector<Word> words){
    generateFrequencies(words);
}

/*
generateFrequencies
Takes a word list and determines how frequently a character occurs
and how many words would share a green
*/
void ValueFinder::generateFrequencies(std::vector<Word> words)
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
int ValueFinder::scoreWord(std::string w) const
{
    int score = 0;
    char curWord[5] = {'*'};
    for (int i = 0; i < 5; i++)
    {   
        int penalty = 1;
        int charScore = greens[i].find(w[i])->second * 3;
        if ( checkPrev(curWord, w[i])){
            penalty = 2;
        }
        else if ( charScore == 0 ){
            charScore = yellows.find(w[i])->second * 2;
        }
        score += (charScore+1)/penalty;
        curWord[i] = w[i];
    }
    return score;
}

/*
checkPrev
Checks previous characters in a word for a character
*/
bool ValueFinder::checkPrev(char word[], char c) const{
    for ( int i = 0; i<5; i++ ){
        if ( word[i] == c ){
            return true;
        }
        if ( word[i] == '*' ){ // exit early
            return false;
        }
    }
    return false;
}