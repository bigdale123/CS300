#include <iostream>
#include "charstack.h"

/*
* Constructor: CharStack
* Usage: CharStack catk;
* ----------------------
* Initializes a new empty stack that can contain characters.
*/

CharStack::CharStack(){
}

/*
* Destructor: ~CharStack
* Usage: (usually implicit)
* -------------------------
* Frees any heap storage associated with this character stack. 
*/

CharStack::~CharStack(){
    free(arr);
}

void CharStack::printStack(){
    std::cout << "[";
    if(arr != nullptr){
        for(int i = 0; i < topOfStack; i++){
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[topOfStack] << "]" << std::endl;
    }
    else{
        std::cout << "]" << std::endl;
    }
    
}

/*
* Method: size
* Usage: int nElems = catk.size();
* --------------------------------
* Returns the number of characters in this stack.
*/

int CharStack::size(){
    return topOfStack+1;
}

/* 
* Method: isEmpty
* Usage: if (catk.isEmpty()) . . .
* --------------------------------
* Returns true if this stack contains no characters.
*/

bool CharStack::isEmpty(){
    return arr == nullptr ? true : false;
}

/*
    * Method: clear
    * Usage: cat.clear();
    * ------------------
    * Removes all characters from this stack. 
    */

void CharStack::clear(){
    arr = nullptr;
}

/*
    * Method: push
    * Usage: catk.push(ch);
    * ---------------------
    * Pushes the character ch onto this stack. 
    */

void CharStack::push(char ch){
    if(arr == nullptr){
        arr = (char*) malloc(1);
        arr[0] = ch;
    }
    else{
        topOfStack += 1;
        arr = (char*) realloc(arr, topOfStack);
        arr[topOfStack] = ch;
    }
}

/* 
    * Method: pop
    * Usage: char ch = catk.pop();
    * ----------------------------
    * Removes the top character from this stack and returns it. 
    */

char CharStack::pop(){
    if(arr != nullptr){
        char ret = arr[topOfStack];
        topOfStack -= 1;
        return ret;
    }
    else {
        return -1;
    }
}

/*
    * Method: peek
    * Usage: char ch = catk.peek();
    * -----------------------------
    * Returns the value of top character from this stack without
    * removing it. Raises an error if called on an empty stack. 
    */

char CharStack::peek(){
    return topOfStack ? arr[topOfStack] : -1;
}