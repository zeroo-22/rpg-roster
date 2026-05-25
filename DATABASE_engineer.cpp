#include "DATABASE_engineer.h"
#include <fstream>
#include <algorithm>

// Assign base stats depending on role
Character RosterDB::assignStats(const std::string& name, const std::string& role) {
    Character c;
    c.id = nextId++;
    c.name = name;
    c.role = role;

    if (role == "Fighter") {
        c.damage = 18;
        c.health = 110;
        c.defense = 12;
    }
    else if (role == "Marksman") {
        c.damage = 22;
        c.health = 90;
        c.defense = 6;
    }
    else if (role == "Tank") {
        c.damage = 12;
        c.health = 160;
        c.defense = 20;
    }
    else if (role == "Assassin") {
        c.damage = 30;
        c.health = 75;
        c.defense = 4;
    }
    else if (role == "Mage") {
        c.damage = 25;
        c.health = 85;
        c.defense = 5;
    }
    else {
        // Default stats
        c.damage = 10;
        c.health = 100;
        c.defense = 5;
    }

    return c;
}

// Create
void RosterDB::addCharacter(const std::string& name, const std::string& role) {
    roster.push_back(assignStats(name, role));
}

// Read
void RosterDB::listCharacters() const {
    for (const auto& c : roster) {
        std::cout << "ID: " << c.id
            << " | Name: " << c.name
            << " | Role: " << c.role
            << " | Damage: " << c.damage
            << " | Health: " << c.health
            << " | Defense: " << c.defense << "\n";
    }
}

// Update
bool RosterDB::updateCharacter(int id, const std::string& newName, const std::string& newRole) {
    for (auto& c : roster) {
        if (c.id == id) {
            c.name = newName;
            c.role = newRole;
            // Reassign stats based on new role
            Character updated = assignStats(newName, newRole);
            c.damage = updated.damage;
            c.health = updated.health;
            c.defense = updated.defense;
            return true;
        }
    }
    return false;
}

// Delete
bool RosterDB::removeCharacter(int id) {
    auto it = std::remove_if(roster.begin(), roster.end(),
        [id](const Character& c) { return c.id == id; });
    if (it != roster.end()) {
        roster.erase(it, roster.end());
        return true;
    }
    return false;
}

// Save roster to CSV file
void RosterDB::saveToCSV(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    file << "ID,Name,Role,Damage,Health,Defense\n";
    for (const auto& c : roster) {
        file << c.id << ","
            << c.name << ","
            << c.role << ","
            << c.damage << ","
            << c.health << ","
            << c.defense << "\n";
    }

    file.close();
    std::cout << "Roster saved to " << filename << "\n";
}
