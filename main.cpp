#include <iostream>
#include <string>
using namespace std;

void registerBill() {
    string name;
    double amount;

    cout << "\nEnter person's name: ";
    getline(cin, name);

    cout << "Enter bill amount (Rs.): ";
    cin >> amount;

    cout << "\n----- Bill Registered -----" << endl;
    cout << "Person: " << name << endl;
    cout << "Bill Amount: Rs. " << amount << endl;
}

int main() {
    int choice;

    do {
        cout << "\n========================" << endl;
        cout << "        HOPEPAY" << endl;
        cout << "========================" << endl;

        cout << "1. Register a Bill" << endl;
        cout << "2. View All Bills" << endl;
        cout << "3. Donate to a Bill" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        if (choice == 1) {
            registerBill();
        }
        else if (choice == 2) {
            cout << "View All Bills selected." << endl;
        }
        else if (choice == 3) {
            cout << "Donate to a Bill selected." << endl;
        }
        else if (choice == 4) {
            cout << "Thank you for using HopePay!" << endl;
        }
        else {
            cout << "Invalid choice. Please select 1 to 4." << endl;
        }

    } while (choice != 4);

    return 0;
}