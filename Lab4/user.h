#ifndef _user_h
#define _user_h
#include <vector>
class User {
    private:
        std::string userName;
        std::string email;
        std::vector<User*> friends;

    public:
        User(std::string newUserName, std::string newEmail);

        std::string getUserName();

        std::string getEmail();

        std::vector<User*> getFriends();

        void setUserName(std::string userName);

        void setEmail(std::string email);

        void addFriend(User* buddy);

        void removeFriend(std::string userName);

        int numFriends();

        User* getFriendAt(int index);
};
#endif