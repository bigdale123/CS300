#include <iostream>
#include "emailvalidator.h"
#include "spellcheck.h"
#include <string>

int main() {
  std::string email = "dylan.calvin@uab.edu";
  std::string recLetter = "Barthalamule is a fantastic Student. barthle once raised a clutch of baby hawks to adulthood. There was never a challenge that bartksafdjksdfNASmwik couldn't solve.";
  std::cout << "Is Valid Email?   " << emailvalidator(email) << std::endl;
  std::cout << "Result of spellCheck: " << spellCheck(recLetter, "Barthalamuel") << std::endl;
  return 0;
}
