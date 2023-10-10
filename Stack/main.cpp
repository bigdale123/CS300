#include <iostream>
#include "charstack.h"

int main() {
    CharStack cs = CharStack();
    cs.push('a');
    cs.printStack();
    cs.push('b');
    cs.push('c');
    cs.printStack();
    cs.push('d');
    cs.push('e');
    cs.printStack();
    cs.pop();
    cs.pop();
    cs.printStack();
    std::cout << cs.peek() << std::endl;
    std::cout << cs.size() << std::endl;
    std::cout << cs.isEmpty() << std::endl;
    cs.clear();
    cs.printStack();
    return 0;
}