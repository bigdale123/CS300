#include <iostream>
#include "user.h"
#include <vector>

User::User(std::string newUserName, std::string newEmail){
    userName = newUserName;
    email = newEmail;
}

std::string User::getUserName(){
    return userName;
}

std::string User::getEmail(){
    return email;
}

std::vector<User*> User::getFriends(){
    return friends;
}

void User::setUserName(std::string userName){
    userName = userName;
}

void User::setEmail(std::string email){
    email = email;
}

// Apparently friend is a reserved keyword in C++????
// So the parameter is buddy.
void User::addFriend(User* buddy){
    friends.push_back(buddy);
}

// https://stackoverflow.com/questions/20582519/delete-from-specific-indexes-in-a-stdvector
void User::removeFriend(std::string userName){
    for(int i = 0; i < friends.size(); i++){
        std::cout << friends[i]->getUserName() << std::endl;
        if(userName == friends[i]->getUserName()){
            friends.erase(friends.begin()+i);
        }
    }
}

int User::numFriends() {
    return friends.size();
}

User* User::getFriendAt(int index){
    if(index > 0 && index < friends.size()){
        return friends[index];
    }
}