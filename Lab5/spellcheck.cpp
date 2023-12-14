#include <iostream>
#include "spellcheck.h"
#include <string>
#include <regex>

std::string spellCheck(std::string recLetter, std::string studentName) { 
  std::regex r("[bB]art[a-zA-Z]+ "); return std::regex_replace(recLetter, r, studentName+' ');
}

