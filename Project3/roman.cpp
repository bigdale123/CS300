#include <iostream>
#include <map>
#include "roman.h"

/**
 * Convert a Roman numeral string to an integer representation.
 *
 * This function takes a Roman numeral string as input and returns its equivalent
 * integer value. It follows the Roman numeral rules for conversion, where
 * smaller numerals appearing before larger ones are subtracted, and larger
 * numerals appearing before smaller ones are added. The function supports
 * Roman numerals from 'I' to 'M' (1 to 1000).
 *
 * @param numerals The Roman numeral string to be converted to an integer.
 * @return The integer representation of the Roman numeral.
 *
 * @note The function assumes that the input Roman numeral is valid and in uppercase.
 * @note The function does not perform extensive error checking for invalid Roman numerals.
 *       It is the caller's responsibility to ensure the input is a valid Roman numeral.
 *
 * @example
 *   int result = romanToDecimal("XIV"); // Result: 14
 *   int result = romanToDecimal("MCMLIV"); // Result: 1954
 */

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