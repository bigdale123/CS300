#ifndef randword
#define randword
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

// Note: I was not in class the day we talked about libraries,
//   So this is probably not proper implementation. But, putting
//   Function declarations in the header file is how we do it in CS330.


static std::vector<std::string> words;

void initDictionary(std::string filepath){
    // https://www.learncpp.com/cpp-tutorial/basic-file-io/
    std::ifstream input_file{filepath};

    if(input_file){
        while(input_file){
            std::string temp = "";
            std::getline(input_file, temp);
            if(temp.size() > 0){
                words.push_back(temp);
            }
        }
    }
}

std::string chooseRandomWord(){
    // https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
    std::mt19937 rng(std::time(NULL));
    std::uniform_int_distribution<int> gen(0, words.size()); // uniform, unbiased

    int rand_index = gen(rng);
    return words[rand_index];
}


#endif