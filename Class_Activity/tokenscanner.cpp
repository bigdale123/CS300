#include <cctype>
#include <string>
#include "tokenscanner.h"

TokenScanner::TokenScanner() {}

TokenScanner::TokenScanner(std::string str) {
    setInput(str);
}

void TokenScanner::setInput(std::string str) {
    buffer = str;
    cp = 0;
}

bool TokenScanner::hasMoreTokens() {
    if (ignoreWhitespaceFlag) skipWhitespace();
    return cp < buffer.length();
}

/*
 * Implementation notes: nextToken
 * -------------------------------
 * This method starts by looking at the character at the current character
 * indicated by the index cp. If that index is past the end of the string, 
 * nextToken returns the empty string. If that character is alphanumeric,
 * nextToken scans ahead until it finds the end of that word; if not,
 * nextToken returns that character as a one-character string.
 */
std::string TokenScanner::nextToken() {
    if (ignoreWhitespaceFlag) skipWhitespace();
    if (cp >= buffer.length()) {
        return "";
    } else if (isalnum(buffer[cp])) {
        int start = cp;
        while (cp < buffer.length() && isalnum(buffer[cp])) {
            cp++;
        }
        return buffer.substr(start, cp - start);
    } else {
        return std::string(1, buffer[cp++]);
    }
}

/*
 * Implementation notes: ignoreWhitespace and skipWhitespace
 * ---------------------------------------------------------
 * This ignoreWhitespace method simply sets a flag. The private method
 * skipWhitespace is called only if that flag is true.
 */

void TokenScanner::ignoreWhitespace() {
    ignoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace() {
    while (cp < buffer.length() && isspace(buffer[cp])) {
        cp++;
    }
}