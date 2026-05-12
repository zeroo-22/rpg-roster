#include <iostream>
#include <cstdlib>
using namespace std;




int main() {
    int choice;

    do {
	    cout << "\n===== MENU =====" << endl;
        cout << "1. Create Hero" << endl;
        cout << "2. Display Heroes" << endl;
        cout << "3. Battle The Heroes" << endl;
        cout << "4. Delete Character/Hero" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            system("cls");
            cout << "Invalid input. Numbers only.\n";
            continue;
        }

        system("cls"); 


        switch (choice) {
            case 1:
                cout << "hero created";
                break;
            
            case 2 :
                cout << "heroes showed";
            
            case 3 :
                cout << "starting hero battles";
            
            case 4 :
                cout << "deleting hero";
            
            case 5 :
                cout << "exiting";
            
            default:
                cout << "invalid input"

        }
    } while (choice != 5);

    return 0;

}