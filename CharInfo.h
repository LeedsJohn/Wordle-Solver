// John Leeds
// 5/8/2022
// CharInfo.h
// Header file for class CharInfo

#ifndef CHARINFO_HDR
#define CHARINFO_HDR
#include <map>
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
        std::map<char, bool> greens[5];
        std::map<char, bool> yellows;
        std::map<char, bool> grays;
};

#endif