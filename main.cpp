#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bill {
public:
    string name;
    double amount;
};

void registerBill(vector<Bill>& bills) {
    Bill newBill;

    cout << "\nEnter person's name: ";
    getline(cin, newBill.name);

    cout << "Enter bill amount (Rs.): ";
    cin >> newBill.amount;
    cin.ignore(10000, '\n');

    bills.push_back(newBill);

    cout << "\n----- Bill Registered Successfully -----" << endl;
    cout << "Person: " << newBill.name << endl;
    cout << "Bill Amount: Rs. " << newBill.amount << endl;
}


void viewAllBills(const vector<Bill>& bills) {
    if (bills.empty()) {
        cout << "\nNo bills registered yet." << endl;
        return;
    }

    cout << "\n===== All Registered Bills =====" << endl;

    for (int i = 0; i < bills.size(); i++) {
        cout << "\nBill ID: " << i + 1 << endl;
        cout << "Person: " << bills[i].name << endl;
        cout << "Amount: Rs. " << bills[i].amount << endl;
    }
}

int main() {
    int choice;
    vector<Bill> bills;

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
            registerBill(bills);
        }
        else if (choice == 2) {
            viewAllBills(bills);
        }
        else if (choice == 3) {
            cout << "\nDonation feature will be added next!" << endl;
        }
        else if (choice == 4) {
            cout << "\nThank you for using HopePay!" << endl;
        }
        else {
            cout << "\nInvalid choice. Please select 1 to 4." << endl;
        }

    } while (choice != 4);

    return 0;
}