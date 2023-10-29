#ifndef _roman_h
#define _roman_h

#include <iostream>

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
int romanToDecimal(const std::string& numerals);

#endif