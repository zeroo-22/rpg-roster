#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Character {
    int id;
    std::string name;
    std::string role;
};

class RosterDB {
private:
    std::vector<Character> roster;
    int nextId = 1;

public:
    // Create
    void addCharacter(const std::string& name, const std::string& role) {
        roster.push_back({ nextId++, name, role });
    }

    // Read
    void listCharacters() const {
        for (const auto& c : roster) {
            std::cout << "ID: " << c.id
                << " | Name: " << c.name
                << " | Role: " << c.role << "\n";
        }
    }

    // Update
    bool updateCharacter(int id, const std::string& newName, const std::string& newRole) {
        for (auto& c : roster) {
            if (c.id == id) {
                c.name = newName;
                c.role = newRole;
                return true;
            }
        }
        return false;
    }

    // Delete
    bool removeCharacter(int id) {
        auto it = std::remove_if(roster.begin(), roster.end(),
            [id](const Character& c) { return c.id == id; });
        if (it != roster.end()) {
            roster.erase(it, roster.end());
            return true;
        }
        return false;
    }
};

int main() {
    RosterDB db;

    db.addCharacter("Dren", Marksman");
        db.addCharacter("Dave", Assassin");
            db.addCharacter("Ryuu", Tank");
                db.addCharacter("Ken", Fighter");
                    db.addCharacter("Nico", Support");

                        std::cout << "Initial roster:\n";
    db.listCharacters();

    std::cout << "\nUpdating Borin...\n";
    db.updateCharacter(2, "Borin the Brave", "Support");

    db.listCharacters();

    std::cout << "\nRemoving Celine...\n";
    db.removeCharacter(3);

    db.listCharacters();

    return 0;
}
