#ifndef _pirate_h
#define _pirate_h
#include <string>
#include <iostream>
#include <map>
#include <vector>

/**
 * Pirate Translator Class
 *
 * The PirateTranslator class is responsible for translating English phrases
 * into pirate-speak. It uses a dictionary to perform these translations.
 */
class PirateTranslator {
private:
    /**
     * Dictionary of English to Pirate Translations
     *
     * This dictionary stores the English words and their corresponding pirate
     * translations. It is marked as mutable to allow modification within
     * const member functions for caching translation keys.
     */
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
    /**
     * Constructor
     *
     * Creates an instance of the PirateTranslator class and initializes
     * the translation dictionary.
     */
    PirateTranslator();

    /**
     * Destructor
     *
     * Destroys an instance of the PirateTranslator class.
     */
    ~PirateTranslator();

    /**
     * Translate a Line to Pirate-Speak
     *
     * This function takes an English sentence as input and translates it
     * into pirate-speak based on the stored dictionary of translations.
     *
     * @param line The English sentence to be translated.
     * @return The corresponding pirate-speak translation of the input sentence.
     */
    std::string translateLine(const std::string& line) const;

    /**
     * Get Keys from the Translation Dictionary
     *
     * This function retrieves the keys (English words) from the translation
     * dictionary and returns them as a vector of strings. It is marked as const
     * since it does not modify the object's state.
     *
     * @return A vector of strings containing the keys (English words) from the
     *         translation dictionary.
     */
    std::vector<std::string> getKeys() const;

    /**
     * Run Unit Tests for Pirate Translation
     *
     * This function runs a set of unit tests to validate the translation
     * functionality of the PirateTranslator class. It includes tests for
     * various English phrases and their expected pirate-speak translations.
     */
    void runUnitTests();
};

#endif