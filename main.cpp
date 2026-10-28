
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bill {
public:
    string name;
    double amount;
    double donatedAmount = 0;

    double remainingAmount() const {
        return amount - donatedAmount;
    }
};

// Register a new bill
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

// View all registered bills
void viewAllBills(const vector<Bill>& bills) {
    if (bills.empty()) {
        cout << "\nNo bills registered yet." << endl;
        return;
    }

    cout << "\n===== All Registered Bills =====" << endl;

    for (int i = 0; i < bills.size(); i++) {
        cout << "\nBill ID: " << i + 1 << endl;
        cout << "Person: " << bills[i].name << endl;

        cout << "Original Amount: Rs. "
             << bills[i].amount << endl;

        cout << "Donated Amount: Rs. "
             << bills[i].donatedAmount << endl;

        cout << "Remaining Amount: Rs. "
             << bills[i].remainingAmount() << endl;

        if (bills[i].donatedAmount == 0) {
            cout << "Status: Not Funded Yet" << endl;
        }
        else if (bills[i].remainingAmount() == 0) {
            cout << "Status: Fully Funded" << endl;
        }
        else {
            cout << "Status: Partially Funded" << endl;
        }
    }
}

// Donate to a bill
void donateToBill(vector<Bill>& bills) {
    if (bills.empty()) {
        cout << "\nNo bills available for donation." << endl;
        return;
    }

    viewAllBills(bills);

    int billId;
    double donation;

    cout << "\nEnter Bill ID to donate: ";
    cin >> billId;

    if (billId < 1 || billId > bills.size()) {
        cout << "Invalid Bill ID!" << endl;
        return;
    }

    Bill& selectedBill = bills[billId - 1];

    if (selectedBill.remainingAmount() <= 0) {
        cout << "This bill is already fully funded." << endl;
        return;
    }

    cout << "Enter donation amount (Rs.): ";
    cin >> donation;

    if (donation <= 0) {
        cout << "Donation must be greater than zero." << endl;
        return;
    }

    if (donation > selectedBill.remainingAmount()) {
        cout << "Donation cannot exceed the remaining bill amount." << endl;
        return;
    }

    selectedBill.donatedAmount += donation;

    cout << "\nDonation recorded successfully!" << endl;
    cout << "Total Donated: Rs. "
         << selectedBill.donatedAmount << endl;
    cout << "Remaining Amount: Rs. "
         << selectedBill.remainingAmount() << endl;

    if (selectedBill.remainingAmount() == 0) {
        cout << "Status: Fully Funded!" << endl;
    }
    else {
        cout << "Status: Partially Funded" << endl;
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
            donateToBill(bills);
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
