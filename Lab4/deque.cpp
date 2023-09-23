#include <iostream>
#include "deque.h"


Deque::Deque(){
    frontOfDeque = nullptr;
    backOfDeque = nullptr;
}

Deque::Node* Deque::getFrontOfDeque(){
    return frontOfDeque;
}

Deque::Node* Deque::getBackOfDeque(){
    return backOfDeque;
}

void Deque::setFrontOfDeque(Node* n){
    frontOfDeque = n;
}

void Deque::setBackOfDeque(Node* n){
    backOfDeque = n;
}

void Deque::push_front(int i){
    Node* newNode = new Node(i, frontOfDeque, nullptr);
    if(frontOfDeque != nullptr){
        frontOfDeque->prevNode = newNode;
    }
    frontOfDeque = newNode;
    if(backOfDeque == nullptr){
        backOfDeque = newNode;
    }
}

void Deque::push_back(int i){
    Node* newNode = new Node(i, nullptr, backOfDeque);
    if(backOfDeque != nullptr){
        backOfDeque->nextNode = newNode;
    }
    backOfDeque = newNode;
    if(frontOfDeque == nullptr){
        frontOfDeque = newNode;
    }
}

int Deque::pop_front(){
    if (frontOfDeque != nullptr){
        int val = frontOfDeque->val;
        Node* old_front = frontOfDeque;
        frontOfDeque = frontOfDeque->prevNode;
        if(frontOfDeque != nullptr){
            frontOfDeque->nextNode = nullptr;
        }
        else {
            backOfDeque = nullptr;
        }
        delete old_front;
        return val;
    }
    std::cout << "Error: Tried popping an empty Deque." << std::endl;
    return 0;
}

int Deque::pop_back(){
    if (frontOfDeque != nullptr){
        int val = backOfDeque->val;
        Node* old_back = backOfDeque;
        backOfDeque = backOfDeque->prevNode;
        if(backOfDeque != nullptr){
            backOfDeque->nextNode = nullptr;
        }
        else {
            frontOfDeque = nullptr;
        }
        delete old_back;
        return val;
    }
    std::cout << "Error: Tried popping an empty Deque." << std::endl;
    return 0;
}

int Deque::peak_front(){
    if (frontOfDeque != nullptr){
        return frontOfDeque->val;
    }
    std::cout << "Error: Tried peaking an empty stack." << std::endl;
    return 0;
}

int Deque::peak_back(){
    if (backOfDeque != nullptr){
        return backOfDeque->val;
    }
    std::cout << "Error: Tried peaking an empty stack." << std::endl;
    return 0;
}

void Deque::printDeque(){
    if(frontOfDeque != nullptr){
        Node* startOfQue = frontOfDeque;
        std::cout << "[ ";
        while(startOfQue != nullptr){
            std::cout << startOfQue->val << " ";
            startOfQue = startOfQue->nextNode;
        }
        std::cout << "]" << std::endl;
    }
}

void Deque::removeAll(){
    while(frontOfDeque != nullptr){
        pop_front();
    }
}

Deque::~Deque(){
    removeAll();
}