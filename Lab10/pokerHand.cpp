#include <iostream>
#include "pokerHand.h"
#include <string>
#include <vector>



// Function to generate all possible 5-card poker hands
std::vector<std::string> generate_all_hands() {
    std::vector<std::string> deck;
    std::vector<std::string> all_hands;

    // Define possible values and suits
    const std::string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    const std::string suits[] = {"H", "D", "C", "S"};

    // Generate the deck
    for (const std::string& value : values) {
        for (const std::string& suit : suits) {
            deck.push_back(value + suit);
        }
    }

    // Use combinations to generate all 5-card hands
    for (int i = 0; i < deck.size(); ++i) {
        for (int j = i + 1; j < deck.size(); ++j) {
            for (int k = j + 1; k < deck.size(); ++k) {
                for (int l = k + 1; l < deck.size(); ++l) {
                    for (int m = l + 1; m < deck.size(); ++m) {
                        all_hands.push_back(deck[i] + " " + deck[j] + " " + deck[k] + " " + deck[l] + " " + deck[m]);
                    }
                }
            }
        }
    }

    return all_hands;
}

std::string bestPokerHand(std::string p1, std::string p2){
    std::vector<std::string> all_hands = generate_all_hands();
    int p1_score = 0;
    int p2_score = 0;

    for(p1_score; p1_score < all_hands.size(); p1_score++){
        if(p1 == all_hands[p1_score]){
            break;
        }
    }

    for(p2_score; p2_score < all_hands.size(); p2_score++){
        if(p2 == all_hands[p2_score]){
            break;
        }
    }

    if(p1_score > p2_score){
        return p1;
    }
    else {
        return p2;
    }
}

int main(){
    std::cout << bestPokerHand("2H 3D 5S 9C KD", "2C 3H 4S 8C AH")   << std::endl; // 2C 3H 4S 8C AH
    std::cout << bestPokerHand("2H 3D 5S 9C KD", "4C 6H 7S JH AC")   << std::endl; // 4C 6H 7S JH AC
    std::cout << bestPokerHand("2H 3D 5S 9C KD", "4C 4H 7S JH AC")   << std::endl; // 4C 4H 7S JH AC
    std::cout << bestPokerHand("2H 3D 5S 9C KD", "4C 4H 7S 7H AC")   << std::endl; // 4C 4H 7S 7H AC
    std::cout << bestPokerHand("2H 3D 5S 9C KD", "4C 4H 4S 7H AC")   << std::endl; // 4C 4H 4S 7H AC
    std::cout << bestPokerHand("2H 3D 4S 5C 6D", "4C 5H 6S 7H 8C")   << std::endl; // 4C 5H 6S 7H 8C
    std::cout << bestPokerHand("2H 3H 5H 9H KH", "4C 6C 7C JC AC")   << std::endl; // 4C 6C 7C JC AC
    std::cout << bestPokerHand("2H 2D 5S 5C 5D", "4C 4H 7S 7H 7C")   << std::endl; // 4C 4H 7S 7H 7C
    std::cout << bestPokerHand("2H 2D 2S 2C KD", "4C 4H 4S 4H AC")   << std::endl; // 4C 4H 4S 4H AC
    std::cout << bestPokerHand("2H 3H 4H 5H 6H", "4C 5C 6C 7C 8C")   << std::endl; // 4C 5C 6C 7C 8C
    std::cout << bestPokerHand("10H JH QH KH AH", "10C JC QC KC AC") << std::endl; // 10C JC QC KC AC

    return 0;
}