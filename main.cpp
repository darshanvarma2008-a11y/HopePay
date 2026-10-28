#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    double amount;

    cout << "Welcome to HopePay!" << endl;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your bill amount: ";
    cin >> amount;

    cout << endl;
    cout << "----- Bill Details -----" << endl;
    cout << "Name: " << name << endl;
    cout << "Bill Amount: Rs. " << amount << endl;

    return 0;
}