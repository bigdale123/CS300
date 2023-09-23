#include <iostream>

// A heap allocated Stack data structure
class Stack {
    private:
    // Each value in the stack is held in this node object
    struct Node {
        int val;
        Node* nextNode;

        Node(int ci, Node* n){
            val = ci;
            nextNode = n;
        }
    };
    // The Stack only needs a pointer to the topmost Node of the stack
    Node* topOfStack;

    public:
    Stack(){
        //always Initialize to nullptr
        topOfStack = nullptr;
    }

    Node* getTopOfStack(){
        return topOfStack;
    }

    void setTopOfStack(Node* n){
        topOfStack = n;
    }

    // Pushes a value to the top of the stack
    void push(int i){
        Node* newNode = new Node(i, topOfStack);
        setTopOfStack(newNode);
    }

    int pop(){
        if (topOfStack != nullptr){
            int val = topOfStack->val;
            Node* ptrNewTop = topOfStack->nextNode

            delete topOfStack;
            setTopOfStack(ptrNewTop);
            return val;
        }
        std::cout << "Error: Tried popping an empty stack." << std::endl;
        return 0;
    }

    int peak(){
        if (topOfStack != nullptr){
            return topOfStack->val;
        }
        std::cout << "Error: Tried peaking an empty stack." << std::endl;
        return 0;
    }

    void removeAll(){
        while(getTopOfStack() != nullptr){
            int temp = pop();
        }
    }

    ~Stack(){
        removeAll();
    }
};