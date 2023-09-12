#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <limits>
#include "randword.h"



// Problem 1

std::string keyboard_corrector(std::string input){
    // Yes, I know that this is overkill. However, this will
    // make the solution easier and makes it easier to change
    // What characters are corrected to what (And also to add new cases).
    // This also means the solution can run in O(n) time for each string.
    std::map<char, char> correction_map = {
        // Number Row (Lowercase) (not including back quote)
        {'2','1'},
        {'3','2'},
        {'4','3'},
        {'5','4'},
        {'6','5'},
        {'7','6'},
        {'8','7'},
        {'9','8'},
        {'0','9'},
        {'-','0'},
        {'=','-'},
        // Number Row (Uppercase) (Not including back quote)
        {'@','!'},
        {'#','@'},
        {'$','#'},
        {'%','$'},
        {'^','%'},
        {'&','^'},
        {'*','&'},
        {'(','*'},
        {')','('},
        {'_',')'},
        {'+','_'},
        // First Row (No lowercase)
        {'W','Q'},
        {'E','W'},
        {'R','E'},
        {'T','R'},
        {'Y','T'},
        {'U','Y'},
        {'I','U'},
        {'O','I'},
        {'P','O'},
        {'{','P'},
        {'}','{'},
        {'\\','}'},
        // Second Row
        {'S','A'},
        {'D','S'},
        {'F','D'},
        {'G','F'},
        {'H','G'},
        {'J','H'},
        {'K','J'},
        {'L','K'},
        {':','L'},
        {'"',':'},
        // Second Row lowercase punctuation
        {'\'',';'},
        // Third Row
        {'X','Z'},
        {'C','X'},
        {'V','C'},
        {'B','V'},
        {'N','B'},
        {'M','N'},
        {'<','M'},
        {',','M'},
        {'>','<'},
        {'.',','},
        {'?','>'},
        {'/','.'}
    };

    for(int i = 0; i < input.size(); i++){
        if(correction_map.count(input[i]) > 0){
            input[i] = correction_map[input[i]];
        }
    }

    return input;
}



// Problem 3
int radd(int number){
    // Used https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
    std::string number_string = std::to_string(number);
    int reverse = std::stoi(std::string(number_string.rbegin(), number_string.rend()));
    return number+reverse;
}

int reverse_and_add(int input_number){
    int tries = 0;
    bool done = false;
    int current_work = input_number;
    while(tries < 1000 && !done){
        try{
            current_work = radd(current_work);
            std::string number_string = std::to_string(current_work);
            int reverse = std::stoi(std::string(number_string.rbegin(), number_string.rend()));
            if(reverse == std::stoi(number_string)){
                done = true;
            }
            tries++;
        }
        catch(std::out_of_range){
            std::cout << "Work cannot be done because result exceeds integer size.\n";
            break;
        }
        
    }
    return current_work;
}


// Problem 4
struct bookdataT {
    std::string title;
    std::vector<std::string> authors;
    int catalog_number;
    std::vector<std::string> subject_headings;
    std::string publisher;
    int year_of_publication;
    bool circulating;
};

void addBook(std::vector<bookdataT> *database){
    // Was having trouble using >> and getline together, so I had to read in numbers using getline.
    // https://stackoverflow.com/questions/7786994/c-getline-isnt-waiting-for-input-from-console-when-called-multiple-times
    bookdataT temp_book;
    std::string line;
    std::cout << "  Book Title: ";
    std::cin.ignore();
    std::getline(std::cin, temp_book.title);
    std::cout << "  Authors (leave entry blank for no author):\n";
    for(int i = 0; i < 5; i++){
        std::cout << "      Author #" << i+1 <<": ";
        std::string temp = "";
        std::getline(std::cin, temp);
        if(temp.size()>0){
            temp_book.authors.push_back(temp);
        }
    }
    std::cout << "  Library of Congress Catalog #: ";
    std::getline(std::cin, line);
    temp_book.catalog_number = std::stoi(line);
    for(int i = 0; i < 5; i++){
        std::cout << "      Subject Heading #" << i+1 <<": ";
        std::string temp = "";
        std::getline(std::cin, temp);
        if(temp.size()>0){
            temp_book.subject_headings.push_back(temp);
        }
    }
    std::cout << "  Publisher: ";
    std::getline(std::cin, temp_book.publisher);
    std::cout << "  Year of Publication: ";
    std::getline(std::cin, line);
    temp_book.year_of_publication = std::stoi(line);
    std::cout << "  Currently Circulating? (y/n): ";
    std::string choice = "";
    std::getline(std::cin, choice);
    if(choice == "y"){
        temp_book.circulating = true;
    }
    else{
        temp_book.circulating = false;
    }
    database->push_back(temp_book);
}

void searchBySubject(std::vector<bookdataT> database, std::string subject){
    for(int i = 0; i < database.size(); i++){
        for(int j = 0; j < database[i].subject_headings.size(); i++){
            if(subject == database[i].subject_headings[j]){
                std::cout << "Title: " << database[i].title << "\n";
                std::cout << "  First Author: " << database[i].authors[0] << "\n";
                std::cout << "  Catalog #: " << database[i].catalog_number << "\n";
            }
        }
    }
    std::cout << "\n\n";
}

void displayAllBooks(std::vector<bookdataT> database){
    for(int i = 0; i < database.size(); i++){
        std::cout << "Title: " << database[i].title << "\n";
        std::cout << "    Authors:\n";
        for(int j = 0; j < database[i].authors.size(); j++){
            if(database[i].authors[j].size() > 0){
                std::cout << "        " << database[i].authors[j] << "\n";
            }
        }
        std::cout << "    Catalog #: " << database[i].catalog_number << "\n";
        std::cout << "    Subject Headings:\n";
        for(int j = 0; j < database[i].subject_headings.size(); j++){
            if(database[i].subject_headings[j].size() > 0){
                std::cout << "        " << database[i].subject_headings[j] << "\n";
            }
        }
        std::cout << "    Publisher: " << database[i].publisher << "\n";
        std::cout << "    Year of Publication: " << database[i].year_of_publication << "\n";
        std::cout << "    Circulating? : " << database[i].circulating << "\n";
    }
}

std::vector<int> find_matches(std::string word, char character){
    std::vector<int> indices;
    for(int i = 0; i < word.size(); i++){
        if(word[i] == character){
            indices.push_back(i);
        }
    }
    return indices;
}

int main(){

    // Problem 1
    std::string wrong_input = "O S, GOMR YPFSU/";
    std::cout << "Result of correction function: " << keyboard_corrector(wrong_input) << "\n";

    // Problem 3
    int input = 265;
    std::cout << "Resulting Palindrome: " << reverse_and_add(input) << "\n";


    // Problem 4
    std::vector<bookdataT> libdata;
    int userChoice = 0;

    // Initial Books
    bookdataT temp_book;temp_book.title = "Ender's Game";temp_book.authors.push_back("Orson Scott Card");temp_book.catalog_number = 1;temp_book.subject_headings.push_back("Sci-Fi");temp_book.subject_headings.push_back("Drama");temp_book.subject_headings.push_back("Action");temp_book.publisher = "Tor Books";temp_book.year_of_publication = 1985;temp_book.circulating = true;libdata.push_back(temp_book);
    bookdataT temp_book2;temp_book2.title = "The Hobbit";temp_book2.authors.push_back("JRR Tolkien");temp_book2.catalog_number = 1;temp_book2.subject_headings.push_back("Fantasy");temp_book2.subject_headings.push_back("Drama");temp_book2.subject_headings.push_back("Action");temp_book2.publisher = "George Allen & Unwin (UK)";temp_book2.year_of_publication = 1937;temp_book2.circulating = true;libdata.push_back(temp_book2);
    bookdataT temp_book3;temp_book3.title = "The Fellowship of the Ring";temp_book3.authors.push_back("JRR Tolkien");temp_book3.catalog_number = 1;temp_book3.subject_headings.push_back("Fantasy");temp_book3.subject_headings.push_back("Drama");temp_book3.subject_headings.push_back("Action");temp_book3.publisher = "George Allen & Unwin (UK)";temp_book3.year_of_publication = 1954;temp_book3.circulating = true;libdata.push_back(temp_book3);
    bookdataT temp_book4;temp_book4.title = "The Two Towers";temp_book4.authors.push_back("JRR Tolkien");temp_book4.catalog_number = 1;temp_book4.subject_headings.push_back("Fantasy");temp_book4.subject_headings.push_back("Drama");temp_book4.subject_headings.push_back("Action");temp_book4.publisher = "George Allen & Unwin (UK)";temp_book4.year_of_publication = 1954;temp_book4.circulating = true;libdata.push_back(temp_book4);
    bookdataT temp_book5;temp_book5.title = "The Return of the King";temp_book5.authors.push_back("JRR Tolkien");temp_book5.catalog_number = 1;temp_book5.subject_headings.push_back("Fantasy");temp_book5.subject_headings.push_back("Drama");temp_book5.subject_headings.push_back("Action");temp_book5.publisher = "George Allen & Unwin (UK)";temp_book5.year_of_publication = 1955;temp_book5.circulating = true;libdata.push_back(temp_book5);

    std::cout << "==== Library Catalouge Software ====\n";
    while(userChoice != 4){
        std::cout << "1. Add Book\n";
        std::cout << "2. Search By Subject\n";
        std::cout << "3. Display all Books\n";
        std::cout << "4. Quit\n\n";
        std::cout << " > ";
        std::cin >>userChoice;
        // https://stackoverflow.com/questions/5685471/error-jump-to-case-label-in-switch-statement
        // Had to put case contents inside blocks.
        switch(userChoice){
            case 1:{
                addBook(&libdata);
                break;
            }
            case 2:{
                std::string subject = "";
                std::cout << "  What subject to search?  ";
                std::cin.ignore();
                std::getline(std::cin, subject);
                std::cout << "\n";
                searchBySubject(libdata, subject); 
                break;
            }
            case 3:{
                displayAllBooks(libdata);
                break;
            }
            case 4:{
                break;
            }
            default:{
                std::cout << "Please enter a Valid choice.\n\n";
                break;
            }
        }
    }

    // Problem 5
    initDictionary("words.txt");
    std::string word_to_guess = chooseRandomWord();
    std::cout << "===== Hangman =====\n\n";
    std::cout << "Guess the word before you are hung.\n";
    bool won = false;
    bool dead = false;
    bool run_once = false;
    int guesses = 0;
    std::string guess = "";
    std::string current_word = "";
    for(int i = 0; i < word_to_guess.size(); i++){
        current_word.push_back('-');
    }
    while(!won && !dead){
        std::cout << "The word looks like this now: " << current_word << "\n";
        std::cout << "You have " << 8-guesses << " guesses left.\n";
        std::cout << "(Dev Mode: " << word_to_guess << ")\n";
        // Hack behavior, but it works
        if(!run_once){
            std::cin.ignore();
            run_once = true;
        }
        std::cout << "Guess a Letter: ";

        std::getline(std::cin, guess);
        // https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        std::vector<int> indices = find_matches(word_to_guess, guess[0]);
        if(indices.size() > 0){
            for(int i = 0; i < indices.size(); i++){
                current_word[indices[i]] = guess[0];
            }
        }
        else{
            guesses++;
        }
        if(current_word == word_to_guess){
            won = true;
            std::cout << "You Winner!\n";
            std::cout << "The correct word was: " << word_to_guess << "\n";
        }
        if(guesses >= 8 && !won){
            dead = true;
            std::cout << "You were hung before you guessed the right word.\n";
            std::cout << "The correct word was: " << word_to_guess << "\n";
        }
        
    }
    std::cout << "\nGAME OVER\n\n";
    return 0;
}