#include <iostream>
#include <vector>
#include "deque.h"
#include "user.h"

int main(){
    Deque* d = new Deque();
    std::cout << "pop_front: " << d->pop_front() << std::endl;
    std::cout << "pop_back: " << d->pop_back() << std::endl;

    std::cout << "peak_front: " << d->peak_front() << std::endl;
    std::cout << "peak_back: " << d->peak_back() << std::endl;

    d->push_front(1);
    d->push_front(2);
    d->push_front(3);
    d->push_front(4);

    std::cout << "pop_back: " << d->pop_back() << std::endl;
    std::cout << "pop_back: " << d->pop_back() << std::endl;
    std::cout << "pop_back: " << d->pop_back() << std::endl;
    std::cout << "pop_back: " << d->pop_back() << std::endl;
    std::cout << "pop_back: " << d->pop_back() << std::endl;

    d->removeAll();


    User one = User("Dylan Calvin", "dylcal138@gmail.com");
    User two = User("John Doe", "bs32@gmail.com");
    User three = User("Buster Brown", "bb54@hotmail.com");
    User four = User("Logi Tech", "lg@lg.org");

    one.addFriend(&two);
    one.addFriend(&three);

    std::cout << "Number of Friends: " << one.numFriends() << std::endl;
    one.removeFriend("John Doe");
    std::cout << "Number of Friends: " << one.numFriends() << std::endl;


    return 0;
}
