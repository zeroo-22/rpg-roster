#include <iostream>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Create Hero Name
string createHeroName() {
    string name;
    while (true) {
        cout << "Enter hero name: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "Invalid input. The name should not be empty." << endl;
            continue;
        }

        bool hasDigit = false;
        for (char c : name) {
            if (isdigit(c)) {
                hasDigit = true;
                break;
            }
        }

        if (hasDigit) {
            cout << "Invalid input. Please use strings instead of integer." << endl;
            continue;
        }

        cout << "Hero created." << endl;
        return name;
    }
}

int main() {
    srand(time(0)); // seed random number generator

    // Create heroes
    vector<string> heroes;
    for (int i = 1; i <= 10; i++) {
        heroes.push_back(createHeroName());
    }

    cout << "\n--- Let The Battle Begin! ---\n" << endl;

    // Elimination rounds
    while (heroes.size() > 1) {
        int attackerIndex = rand() % heroes.size();
        int victimIndex;

        // Ensure attacker and victim are different
        do {
            victimIndex = rand() % heroes.size();
        } while (victimIndex == attackerIndex);

        cout << heroes[attackerIndex] << " eliminated " << heroes[victimIndex] << "!" << endl;

        // Remove victim
        heroes.erase(heroes.begin() + victimIndex);
    }

    // Winner
    cout << "\nThe winner is: " << heroes[0] << "!" << endl;
    cout << "Winner! Winner! Chicken dinner." << endl;

    return 0;
}