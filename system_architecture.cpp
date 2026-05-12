#include <iostream>
#include <cctype>
using namespace std;

// Create Hero Name

string createHeroName() {
    string name;

    while (true) {
        cout << "Enter hero name: ";
        getline(cin, name);

        // Prevent empty input
        if (name.empty()) {
            cout << "Invalid input. Name cannot be empty." << endl;
            continue;
        }

        // Check if input contains digits
        bool hasDigit = false;
        for (char c : name) {
            if (isdigit(c)) {
                hasDigit = true;
                break;
            }
        }

        if (hasDigit) {
            cout << "Invalid input. Name cannot contain numbers." << endl;
            continue; // ask again
        }

        cout << "Hero created." << endl;
        return name;
    }
}

int main() {
    std::string hero1 = createHeroName();
    std::string hero2 = createHeroName();
    std::string hero3 = createHeroName();
    std::string hero4 = createHeroName();
    std::string hero5 = createHeroName();
    std::string hero6 = createHeroName();
    std::string hero7 = createHeroName();
    std::string hero8 = createHeroName();
    std::string hero9 = createHeroName();
    std::string hero10 = createHeroName();

    return 0;
}

//Battle Heroes