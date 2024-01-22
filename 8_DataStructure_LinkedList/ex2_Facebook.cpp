#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Facebooker {
    private:
        string name;
        vector<Facebooker*> friends;    // List of friends
    public:
        // Constructor
        Facebooker(string nameVal = "", vector<Facebooker*> friendsVal = {})
        : name(nameVal), friends(friendsVal) {}

        // Methods to add a friend
        void addFriend(Facebooker &newFriend) {
            // Put the new friend in the friend list of current user
            friends.push_back(&newFriend);
            // Put the current user in the friend list of new friend
            newFriend.friends.push_back(this);
        }

        // Show friends
        void showFriends() {
            cout << "Friends of " << name << ": ";
            for (auto *aFriend : friends) {
                cout << aFriend->name << " ";
            }
            cout << "\n";
        }

        // Show friends of friends
        void showFriendsOfFriends() {
            showFriends();  // Show current user's friends 
            for (auto aFriend : friends) {  // Go through each friend of current user's friend
                aFriend->showFriends();
            }
        }

        // Show mutual friends
        void showMutualFriends(Facebooker &anotherFacebooker) {
            cout << "Mutual Friends of " << name << " and " << anotherFacebooker.name << ": ";
            for (auto aFriend : friends) {  // Go through each friend of current user
                for (auto anotherFriend: anotherFacebooker.friends) {   // Go through each friend of anotherFacebooker
                    if (aFriend == anotherFriend) {
                        cout << aFriend->name << " ";
                    }
                }
            }
        }
};

int main() {
    Facebooker user1("Cuong"), user2("Loc"), user3("Minh"), user4("Man");
    user1.addFriend(user2);
    user1.addFriend(user3);
    user1.addFriend(user4);

    user2.addFriend(user3);
    user2.addFriend(user4);

    user1.showFriends();
    cout << "\n";
    user1.showFriendsOfFriends();
    cout << "\n";
    user1.showMutualFriends(user2);

    return 0;
}