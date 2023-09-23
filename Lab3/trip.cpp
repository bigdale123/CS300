#include <iostream>
#include "trip.h"
#include <vector>

float moneyEqualizer(std::vector<float> expenses){
    float avg_pay = 0;
    for(int i = 0; i < expenses.size(); i++){
        avg_pay += expenses[i];
    }
    avg_pay /= expenses.size();
    float total_amount_above = 0;
    float total_amount_below = 0;
    for(int i = 0; i < expenses.size(); i++){
        if(expenses[i] > avg_pay){
            total_amount_above += expenses[i] - avg_pay;
        }
        else if(expenses[i] < avg_pay){
            total_amount_below += avg_pay - expenses[i];
        }
    }
    if(total_amount_below < total_amount_above){
        return total_amount_below;
    }
    else{return total_amount_above;}
}
