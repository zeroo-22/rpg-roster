#ifndef DATABASE_ENGINEER_H
#define DATABASE_ENGINEER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Character {
    int id;
    std::string name;
    std::string role;
    int damage;
    int health;
    int defense;
};

class RosterDB {
private:
    std::vector<Character> roster;
    int nextId = 1;

    Character assignStats(const std::string& name, const std::string& role);

public:
    // Create
    void addCharacter(const std::string& name, const std::string& role);

    // Read
    void listCharacters() const;

    // Update
    bool updateCharacter(int id, const std::string& newName, const std::string& newRole);

    // Delete
    bool removeCharacter(int id);

    // Save
    void saveToCSV(const std::string& filename) const;
};

#endif // DATABASE_ENGINEER_H
