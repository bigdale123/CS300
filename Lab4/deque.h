#include <iostream>

#ifndef _deque_h
#define _deque_h
class Deque{
    private:
    struct Node {
        int val;
        Node* nextNode;
        Node* prevNode;

        Node(int ci, Node* n, Node* p){
            val = ci;
            nextNode = n;
            prevNode = p;
        }
    };

    Node* frontOfDeque;
    Node* backOfDeque;
    
    public:
    Deque();

    Node* getFrontOfDeque();

    Node* getBackOfDeque();
    
    void setFrontOfDeque(Node* n);

    void setBackOfDeque(Node* n);

    void push_front(int i);

    void push_back(int i);

    int pop_front();

    int pop_back();

    int peak_front();

    int peak_back();

    void printDeque();

    void removeAll();

    ~Deque();
};

#endif