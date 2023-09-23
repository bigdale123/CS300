#include <iostream>
#include "trip.h"
#include <vector>

int main(){
    std::vector<float> expenses = {15,15.01,3,3.01};
    std::cout << moneyEqualizer(expenses) << "\n";
    return 0;
}