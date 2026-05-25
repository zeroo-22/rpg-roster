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
};

class RosterDB {
private:
    std::vector<Character> roster;
    int nextId = 1;

public:
    // Create
    void addCharacter(const std::string& name, const std::string& role);

    // Read
    void listCharacters() const;

    // Update
    bool updateCharacter(int id, const std::string& newName, const std::string& newRole);

    // Delete
    bool removeCharacter(int id);
};

#endif // DATABASE_ENGINEER_H
