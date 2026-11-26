#include <iostream>
using namespace std;
int main() {
    int age; bool hasTicket, isMember, isBanned;
    cout << "Enter age: "; if (!(cin >> age)) return 1;
    cout << "Do you have a ticket? (1 for yes, 0 for no): "; if (!(cin >> hasTicket)) return 1;
    cout << "Are you a member? (1 for yes, 0 for no): "; if (!(cin >> isMember)) return 1;
    cout << "Are you banned? (1 for yes, 0 for no): "; if (!(cin >> isBanned)) return 1;
    bool canEnter = (age >= 18 && hasTicket && !isBanned) || (isMember && !isBanned);
    cout << (canEnter ? "You can enter the event!" : "Sorry, you cannot enter.") << endl;
}
