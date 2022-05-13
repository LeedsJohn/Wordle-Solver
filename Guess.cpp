// John Leeds
// 5/8/2022
// Guess.cpp
// Implementation file for class Guess

#include <cctype> // required for toupper()
#include <string>
#include <iostream>
#include "Guess.h"

/*
Constructor
*/
Guess::Guess()
{
    result = "";
    word = "";
}

/*
inputInfo
Gets user input and updates word and result
*/
void Guess::inputInfo()
{
    word = inputWord();
    result = inputResult();
}

/*
inputInfo
Updates word and result from received values
*/
void Guess::inputInfo(std::string w, std::string r)
{
    word = w;
    result = r;
}

/*
getResult
Returns result
*/
std::string Guess::getResult() const
{
    return result;
}

/*
getWord
Returns word
*/
std::string Guess::getWord() const
{
    return word;
}

/*
inputResult
Gets input from the user reflecting the result from the previous
guess.
Enter one character for each character -
    g for green,
    y for yellow,
    x for gray
*/
std::string Guess::inputResult() const
{
    std::cout << "Enter the results of your guess (green --> g, yellow --> y, gray --> x): ";
    std::string results;
    while (!validateResult(results))
    {
        results = "";
        std::cin >> results;
    }
    std::string final = "";
    for (int i = 0; i < 5; i++)
    {
        final.push_back(toupper(results[i]));
    }
    return final;
}

/*
validateResult
Ensures that result is 5 characters and only contains
g, y, or x
*/
bool Guess::validateResult(std::string &word) const
{
    if (word.size() != 5)
    {
        return false;
    }
    for (int i = 0; i < 5; i++)
    {
        char check = toupper(word[i]);
        if (check != 'G' && check != 'Y' && check != 'X')
        {
            return false;
        }
    }
    return true;
}

/*
inputWord
Gets the last word
*/
std::string Guess::inputWord() const
{
    std::cout << "Enter your guess: ";
    std::string guessedWord;
    std::cin >> guessedWord;
    return guessedWord;
}