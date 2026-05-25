#include "system_architecture.h"
#include <iostream>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Create Hero Name
string createHeroName(vector<string>& heroes) {
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
            cout << "Invalid input. Please use letters only." << endl;
            continue;
        }

        // Check for duplicates
        bool exists = false;
        for (const auto& hero : heroes) {
            if (hero == name) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "Hero name already exists. Please enter another." << endl;
            continue;
        }

        cout << "Hero created." << endl;
        return name;
    }
}

// Battle royale
void battleHeroes(vector<string>& heroes) {
    srand(time(0)); // seed random number generator

    cout << "\n--- Let The Battle Begin! ---\n" << endl;

    // Elimination 
    while (heroes.size() > 1) {
        int player1 = rand() % heroes.size();
        int player2;

        // Ensure different players and different names
        do {
            player2 = rand() % heroes.size();
        } while (player2 == player1 || heroes[player2] == heroes[player1]);

        // Who will win
        int winnerIndex = (rand() % 2 == 0) ? player1 : player2;
        int loserIndex = (winnerIndex == player1) ? player2 : player1;

        cout << heroes[winnerIndex] << " eliminated " << heroes[loserIndex] << "!" << endl;

        // Remove loser
        heroes.erase(heroes.begin() + loserIndex);
    }

    // Winner
    cout << "\nThe winner is: " << heroes[0] << "!" << endl;
    cout << "Winner! Winner! Chicken dinner." << endl;
}
