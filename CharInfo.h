// John Leeds
// 5/8/2022
// CharInfo.h
// Header file for class CharInfo

#ifndef CHARINFO_HDR
#define CHARINFO_HDR
#include <set>
#include "Guess.h"

class CharInfo{
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
        void update(Guess& g);
    
    private:
        char greens[5];
        std::set<char> yellows;
        std::set<char> grays;
};

#endif