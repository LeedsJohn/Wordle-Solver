// John Leeds
// 5/11/2022
// ValueFinder.cpp
// Implementation file for class ValueFinder

#include <string>
#include <map>
#include <vector>
#include "Word.h"
#include "ValueFinder.h"
#include "LinkedList.h"
#include "Node.h"

/*
Constructor
*/
ValueFinder::ValueFinder(LinkedList words){
    generateFrequencies(words.getHead());
}

/*
generateFrequencies
Takes a word list and determines how frequently a character occurs
and how many words would share a green
*/
void ValueFinder::generateFrequencies(Node* traverse)
{
    while (traverse)
    {
        std::string curWord = traverse->val.getWord();
        for (int j = 0; j < 5; j++)
        {
            greens[j][curWord[j]]++;
            yellows[curWord[j]]++;
        }
        traverse = traverse->next;
    }
}

/*
scoreWord
Receives a string
Returns an integer representing its value
*/
int ValueFinder::scoreWord(const std::string &w) const
{
    int score = 0;
    char curWord[5] = {'*'};
    for (int i = 0; i < 5; i++)
    {   
        int penalty = 1;
        int charScore = greens[i].find(w[i])->second * 3;
        score += charScore;
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