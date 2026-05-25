#ifndef DATABASE_ENGINEER_H
#define DATABASE_ENGINEER_H

#include <string>
#include <vector>
#include <iostream>

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
    void addCharacter(const std::string& name, const std::string& role);
    void listCharacters() const;
    bool updateCharacter(int id, const std::string& newName, const std::string& newRole);
    bool removeCharacter(int id);
    void saveToCSV(const std::string& filename) const;

    const std::vector<Character>& getRoster() const { return roster; }
};

#endif

