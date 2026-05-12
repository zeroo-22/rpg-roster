// Create Hero Name
std::string createHeroName() {
    std::string name;
    std::cout << "Enter hero name: ";
    std::getline(std::cin, name);
    std::cout << "Hero created." << endl;
    return name;
}

int main() {
    std::string hero1 = createHeroName();

    return 0;
}

//Battle Heroes