#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include "pirate.h"

PirateTranslator::PirateTranslator(){}
PirateTranslator::~PirateTranslator(){}


/**
 * Get Keys from the Translation Dictionary
 *
 * This method is responsible for extracting the keys (English words) from the
 * translation dictionary and returning them as a vector of strings. It is marked
 * as a const member function, indicating that it does not modify the object's state.
 *
 * The implementation uses a loop to iterate through the dictionary and pushes each
 * key into the 'retval' vector. The 'retval' vector is then returned to the caller.
 *
 * @return A vector of strings containing the keys (English words) from the translation dictionary.
 */
std::vector<std::string> PirateTranslator::getKeys() const {
    // https://www.lonecpluspluscoder.com/2015/08/13/an-elegant-way-to-extract-keys-from-a-c-map/
    std::vector<std::string> retval;
    for (auto const& element : dict) {
        retval.push_back(element.first);
    }
    return retval;
}


/**
 * Translate a Line to Pirate-Speak
 *
 * This method takes an English sentence as input and translates it into pirate-speak
 * based on the stored dictionary of translations. It is marked as a const member
 * function, indicating that it does not modify the object's state.
 *
 * The implementation starts by calling 'getKeys' to retrieve the keys (English words)
 * from the translation dictionary. It then iterates through the keys and uses regular
 * expressions to perform the translations. Additionally, it capitalizes the first
 * letter of both the original and translated words.
 *
 * @param line The English sentence to be translated.
 * @return The corresponding pirate-speak translation of the input sentence.
 */
std::string PirateTranslator::translateLine(const std::string& line) const {
    std::vector<std::string> keys = getKeys();
    std::string translatedLine = line;
    for(int i = 0; i < dict.size(); i++){
        translatedLine = std::regex_replace(translatedLine, std::regex("\\b"+keys[i]+"\\b"), dict[keys[i]]);
        std::string upperKey = keys[i];
        std::string upperVal = dict[keys[i]];
        upperKey[0] = toupper(upperKey[0]);
        upperVal[0] = toupper(upperVal[0]);
        translatedLine = std::regex_replace(translatedLine, std::regex("\\b"+upperKey+"\\b"), upperVal);
    }
    return translatedLine;
}


/**
 * Run Unit Tests for Pirate Translation
 *
 * This method runs a set of unit tests to validate the translation functionality
 * of the PirateTranslator class. It includes tests for various English phrases and
 * their expected pirate-speak translations.
 *
 * The implementation initializes a PirateTranslator instance, conducts multiple
 * translation tests, and checks whether the translated results match the expected
 * pirate-speak translations. It then reports the test results.
 */
void PirateTranslator::runUnitTests() {
    PirateTranslator pt = PirateTranslator();
    int tests_passed = 0;
    int total_tests = 3;
    std::string result = translateLine("Hello, madame, would you direct me to the nearest hotel?");
    if("Ahoy, proud beauty, would ye direct me to th' nearest fleabag inn?" == result) {
        tests_passed++;
        std::cout << "Test 1: Passed" << std::endl;
    }
    else {
        std::cout << "Test 1: Failed" << std::endl << "    Expected \"Ahoy, proud beauty, would ye direct me to th' nearest fleabag inn?\", but got \"" << result << "\"" << std::endl;
    }
    result = translateLine("Sir, what is the name of your best restaurant?");
    if("Matey, what be th' name of yer best galley?" == result) {
        tests_passed++;
        std::cout << "Test 1: Passed" << std::endl;
    }
    else {
        std::cout << "Test 1: Failed" << std::endl << "    Expected \"Matey, what be th' name of yer best galley?\", but got \"" << result << "\"" << std::endl;
    }
    result = translateLine("Excuse me, officer, my friend is lost. He is a fellow pirate looking for coins to pay the restaurant.");
    if("Arrr, foul blaggart, me mate be lost. He be a fellow buccaneer looking for doubloons to pay th' galley." == result) {
        tests_passed++;
        std::cout << "Test 1: Passed" << std::endl;
    }
    else {
        std::cout << "Test 1: Failed" << std::endl << "    Expected \"Arrr, foul blaggart, me mate be lost. He be a fellow buccaneer looking for doubloons to pay th' galley.\", but got \"" << result << "\"" << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "Tests Passed: " << tests_passed << "/" << total_tests << std::endl;
}