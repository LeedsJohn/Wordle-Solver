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
void Guess::inputInfo(const std::string &w, const std::string &ans)
{
    word = w;
    result = calculateResult(w, ans);
}

/*
getResult
Returns result
*/
const std::string &Guess::getResult() const
{
    return result;
}

/*
getWord
Returns word
*/
const std::string &Guess::getWord() const
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
bool Guess::validateResult(const std::string &word) const
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

/*
calculateResult
Receives the guess and answer
Returns the result
*/
std::string Guess::calculateResult(const std::string &g, const std::string &a)
{
    std::string result = "";
    for ( int i = 0; i<5; i++ ){
        int occurrences = countOccurrences(a, g[i]);

        if ( g[i] == a[i] ){
            result.push_back('G');
        }
        else if ( occurrences == 0 || countOccurrences(g, g[i], i) >= occurrences ){
            result.push_back('X');
        }
        else{
            result.push_back('Y');
        }
    }
    return result;
}

/*
countOccurrences
Receives a string and a character
Returns how many times the character appears in the string
*/
int Guess::countOccurrences(const std::string &w, char c, int end /* = 5 */)
{
    int count = 0;
    for (int i = 0; i<end; i++ )
    {
        if (w[i] == c)
        {
            count++;
        }
    }
    return count;
}