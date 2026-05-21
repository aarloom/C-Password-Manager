#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct Accounts {
    string service;
    string username;
    string password;
};

int main()
{
    int response;

    vector<Accounts> accounts;

    cout << "==== Password Manager ====" << endl;
    cout << "1. Add account" << endl;
    cout << "2. View accounts" << endl;
    cout << "3. Exit" << endl;

    cin >> response;

    if (response == 1) {

        Accounts newAccount;

        cout << "Enter service: ";
        cin >> newAccount.service;

        cout << "Enter username: ";
        cin >> newAccount.username;

        cout << "Enter password: ";
        cin >> newAccount.password;

        accounts.push_back(newAccount);

        ofstream outfile("accounts.txt", ios::app);

        outfile << newAccount.service << " ";
        outfile << newAccount.username << " ";
        outfile << newAccount.password << endl;

        outfile.close();

        cout << "Account added successfully." << endl;

    }
    else if (response == 2) {

        ifstream infile("accounts.txt");

        Accounts temp;

        while (infile >> temp.service >> temp.username >> temp.password) {

            cout << "Service: " << temp.service << endl;
            cout << "Username: " << temp.username << endl;
            cout << "Password: " << temp.password << endl;
            cout << "----------------------" << endl;
        }

        infile.close();
    }
    else if (response == 3) {

        cout << "Program closed." << endl;
        return 0;
    }

    return 0;
}