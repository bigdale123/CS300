#include <iostream>
#include <map>
#include "roman.h"

int romanToDecimal(const std::string& numerals) {
    std::map<char, int> dict = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };


    int sum = dict[numerals[0]];
    for(int i = 1; i < numerals.length()-1; i++){
        if(dict[numerals[i]] < dict[numerals[i+1]]) {
            // std::cout << sum << "-" << dict[numerals[i]] << std::endl;
            sum -= dict[numerals[i]];
        }
        else {
            // std::cout << sum << "+" << dict[numerals[i]] << std::endl;
            sum += dict[numerals[i]];
        }
    }
    // std::cout << sum << "+" << dict[numerals[numerals.length()-1]] << std::endl;
    sum += dict[numerals[numerals.length()-1]];
    return sum;
}