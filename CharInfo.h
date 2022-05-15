// John Leeds
// 5/8/2022
// CharInfo.h
// Header file for class CharInfo

#ifndef CHARINFO_HDR
#define CHARINFO_HDR
#include <set>
#include <vector>
#include "Guess.h"

class CharInfo
{
public:
    /*
    constructor
    */
    CharInfo();

    /*
    update
    Receives a Guess
    Adds in the info to greens, yellows, and greys
    */
    void update(Guess &g);

    // GETTERS
    const std::vector<char> &getGreens() const;

    const std::set<char> &getYellows() const;

    const std::set<char> &getGrays() const;

    const std::vector<std::set<char>> &getWrongPosition() const;

private:
    std::vector<char> greens;
    std::vector<std::set<char>> wrongPosition;
    std::set<char> yellows;
    std::set<char> grays;
};

#endif