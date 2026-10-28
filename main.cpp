#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "========================" << endl;
    cout << "       HOPEPAY" << endl;
    cout << "========================" << endl;

    cout << "1. Register a Bill" << endl;
    cout << "2. View All Bills" << endl;
    cout << "3. Donate to a Bill" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "You selected Register a Bill." << endl;
    }
    else if (choice == 2) {
        cout << "You selected View All Bills." << endl;
    }
    else if (choice == 3) {
        cout << "You selected Donate to a Bill." << endl;
    }
    else if (choice == 4) {
        cout << "Thank you for using HopePay!" << endl;
    }
    else {
        cout << "Invalid choice. Please select 1 to 4." << endl;
    }

    return 0;
}