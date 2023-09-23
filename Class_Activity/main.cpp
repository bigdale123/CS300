#include <iostream>
#include <string>
#include "tokenscanner.h"

int main() {
    bool done = false;
    while (!done) {
        std::string input = "";
        std::cout << "> ";
        std::getline(std::cin, input);
        if(input != "q"){
            TokenScanner scan = TokenScanner(input);
            scan.ignoreWhitespace();
            float accumulator = std::stof(scan.nextToken());
            while(scan.hasMoreTokens()){
                char symbol = scan.nextToken()[0];
                float operand = std::stof(scan.nextToken());
                switch (symbol) {
                    case '+':
                        accumulator += operand;
                        break;
                    case '-':
                        accumulator -= operand;
                        break;
                    case '*':
                        accumulator *= operand;
                        break;
                    case '/':
                        accumulator /= operand;
                        break;
                }
            }
            std::cout << accumulator << "\n";
        }
        else{
            done = !done;
        }
        
    }
    return 0;
}