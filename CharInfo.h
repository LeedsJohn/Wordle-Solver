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
    std::vector<char> getGreens() const;

    std::set<char> getYellows() const;

    std::set<char> getGrays() const;

private:
    std::vector<char> greens;
    std::set<char> yellows;
    std::set<char> grays;
};

#endif