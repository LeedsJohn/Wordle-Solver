// John Leeds
// 5/8/2022
// Guess.h
// Header file for class Guess

#ifndef GUESS_HDR
#define GUESS_HDR
#include <string>

class Guess
{
public:
    /*
    Constructor
    */
    Guess();

    /*
    inputInfo
    Gets user input and updates word and result
    */
    void inputInfo();

    /*
    inputInfo
    Updates word and result from received values
    */
    void inputInfo(const std::string &w, const std::string &ans);

    /*
    getResult
    Returns result
    */
    const std::string &getResult() const;

    /*
    getWord
    Returns word
    */
    const std::string &getWord() const;

private:
    std::string result;
    std::string word;

    /*
    inputResult
    Gets input from the user reflecting the result from the previous
    guess.
    Enter one character for each character -
        g for green,
        y for yellow,
        x for gray
    */
    std::string inputResult() const;

    /*
    validateResult
    Ensures that result is 5 characters and only contains
    g, y, or x
    */
    bool validateResult(const std::string &word) const;

    /*
    inputWord
    Gets the last word
    */
    std::string inputWord() const;

    /*
    calculateResult
    Receives the guess and answer
    Returns the result
    */
    std::string calculateResult(const std::string &g, const std::string &a);
    
    /*
    countOccurrences
    Receives a string and a character
    Returns how many times the character appears in the string
    */
    int countOccurrences(const std::string &w, char c, int end = 5);
};

#endif