#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    User() {};

    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

// Map to store user names to User objects
map<string, User> mapUserName;

// Map to store friendships
map<string, set<string> > Friends;

void addUser(string userName, User user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;
    } else {
        cout << "UserName Already Taken\n";
    }
}

void makeThemFriend(string userName1, string userName2) {
    if (mapUserName.find(userName1) != mapUserName.end() && mapUserName.find(userName2) != mapUserName.end()) {
        Friends[userName1].insert(userName2);
        Friends[userName2].insert(userName1);
    } else {
        cout << "One or both users do not exist.\n";
    }
}

void displayAllUser() {
    for (map<string, User>::iterator it = mapUserName.begin(); it != mapUserName.end(); ++it) {
        cout << "UserName: " << it->first << ", Name: " << it->second.firstName << " " << it->second.lastName << "\n";
    }
}

void displayAllFriendships() {
    for (map<string, set<string> >::iterator it = Friends.begin(); it != Friends.end(); ++it) {
        cout << it->first << ":\n";
        set<string> friends = it->second;
        for (set<string>::iterator friendIt = friends.begin(); friendIt != friends.end(); ++friendIt) {
            cout << "  " << *friendIt << "\n";
        }
    }
}

int main() {
    // Adding users
    User alice("Alice", "Mishra", 30, "Female");
    User bob("Bob", "Ali", 27, "Male");

    addUser("Alice", alice);
    addUser("Bob", bob);

    // Making them friends
    makeThemFriend("Alice", "Bob");

    // Display users and friendships
    displayAllUser();
    displayAllFriendships();

    return 0;
}

