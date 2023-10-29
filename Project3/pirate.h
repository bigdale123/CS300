#ifndef _pirate_h
#define _pirate_h
#include <string>
#include <iostream>
#include <map>
#include <vector>

class PirateTranslator {
    private:
        mutable std::map<std::string, std::string> dict = {
            {"hello", "ahoy"},
            {"excuse me", "arrr"},
            {"sir", "matey"},
            {"boy", "matey"},
            {"man", "matey"},
            {"madame", "proud beauty"},
            {"officer", "foul blaggart"},
            {"the", "th'"},
            {"my", "me"},
            {"your", "yer"},
            {"is", "be"},
            {"are", "be"},
            {"restroom", "head"},
            {"restaurant", "galley"},
            {"hotel", "fleabag inn"},
            {"coins", "doubloons"},
            {"dollar", "doubloon"},
            {"dollars", "doubloons"},
            {"pirate", "buccaneer"},
            {"friend", "mate"},
            {"you", "ye"}
        };
    public:
        PirateTranslator();
        ~PirateTranslator();

        std::string translateLine(const std::string& line) const;
        std::vector<std::string> getKeys() const;
        void runUnitTests();

};

#endif