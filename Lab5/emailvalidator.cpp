#include <iostream>
#include <string>
#include "emailvalidator.h"
#include <regex>

bool emailvalidator(std::string email) {
  std::regex r("[0-9a-zA-Z]{1,20}\\.[!$&a-zA-Z]{1,}@[a-z]{1,20}\\.[a-z]{1,3}"); return std::regex_match(email, r);
}
