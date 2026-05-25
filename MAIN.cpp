#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>
#include "system_architecture.h"
#include "DATABASE_engineer.h"
using namespace std;

int main() {
    int choice;
    vector<string> heroes;
    RosterDB db;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Create Hero" << endl;
        cout << "2. Display Heroes" << endl;
        cout << "3. Battle The Heroes" << endl;
        cout << "4. Delete Character/Hero" << endl;
        cout << "5. Save & Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "Invalid input. Numbers only." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush newline
        system("cls");

        switch (choice) {
        case 1: {
            string hero = createHeroName(heroes);
            heroes.push_back(hero);

            int roleChoice;
            cout << "Choose role:\n";
            cout << "1. Assault\n";
            cout << "2. Sharpshooter\n";
            cout << "3. Engineer\n";
            cout << "4. Recon\n";
            cout << "5. Support\n";
            cout << "Enter choice (1-5): ";
            cin >> roleChoice;

            string role;
            switch (roleChoice) {
            case 1: role = "Assault"; break;
            case 2: role = "Sharpshooter"; break;
            case 3: role = "Engineer"; break;
            case 4: role = "Recon"; break;
            case 5: role = "Support"; break;
            default:
                cout << "Invalid choice. Role not assigned." << endl;
                break;
            }

            if (!role.empty()) {
                db.addCharacter(hero, role);
            }
            break;
        }

        case 2:
            db.listCharacters();
            break;
        case 3:
            if (heroes.size() < 2) {
                cout << "Need at least 2 heroes to battle." << endl;
            }
            else {
                battleHeroes(heroes);
            }
            break;
        case 4: {
            int id;
            cout << "Enter character ID to delete: ";
            cin >> id;
            if (db.removeCharacter(id)) {
                cout << "Character deleted." << endl;
            }
            else {
                cout << "Character not found." << endl;
            }
            break;
        }
        case 5:
            db.saveToCSV("heroes.csv");
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}