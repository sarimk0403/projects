/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>


Account Account_item[10];
int PinCount = 0;



void readFile(string filename){

    
    ifstream din;
    din.open(filename);
    
    if(din.fail()){
        cout << "Error; file " << "Account.txt" << " could not be opened" << endl;
        return;
    }
    string Name, Year, Pin, Amount;


    while(din.good()){
        
        getline (din, Name, ',');
        cout << Name << " ";
        getline (din, Year, ',');
        cout << Year << " ";
        getline (din, Pin, ',');
        cout << Pin << " ";
        getline (din, Amount);
        cout << Amount << endl;
        
        Account_item[PinCount].setName(Name);
        int Year1 = stoi(Year);
        Account_item[PinCount].setYear(Year1);
        int Pin1 = stoi(Pin);
        Account_item[PinCount].setPin(Pin1);
        float Amount1 = stof(Amount);
        Account_item[PinCount].setAmount(Amount1);
        
        PinCount++;
        
        
    }
    din.close();
    
}

void addAccount(){
    
    string Name;
    int Year;
    int Pin;
    float Amount;
    
    cin.ignore();
 
    cout << "Enter the name of the Account: ";
    getline (cin, Name);
    
    cout << "Enter the year it started: ";
    cin >> Year;
    while(Year <= 0)
        {
        cout << "Enter the year it started: ";
        cin >> Year;
        }
    
    cout << "What is the Pin Number: ";
    cin >> Pin;
    
    cout << "What is the Amount of the Account: ";
    cin >> Amount;
    while(Amount < 0)
        {
        cout << "What is the Amount of the Account: ";
        cin >> Amount;
        }
    
    Account_item[PinCount].setName(Name);
    Account_item[PinCount].setYear(Year);
    Account_item[PinCount].setPin(Pin);
    Account_item[PinCount].setAmount(Amount);
    
    PinCount++;
    
}


void ByYear(){
    int year;
    
    cout << "Enter the year you are trying to find: ";
    cin >> year;
    while(year <= 0)
        {
        cout << "Enter the year you are trying to find: ";
        cin >> year;
        }
    
    
    cout << "Accounts started in " << year << ":" << endl;
    for(int i = 0; i < PinCount; i++){
        if(Account_item[i].getYear() == year){
            cout << Account_item[i].getName() << ", " << Account_item[i].getAmount() << endl;
        }
    }
    
}

void updateAccount() {
    string name;
    cin.ignore();
    cout << "Enter the name of the Account you want to update: ";
    getline (cin, name);

    // find the account
    int indexToUpdate = -1;
    for (int i = 0; i < PinCount; i++) {
        if (Account_item[i].getName() == name) {
            indexToUpdate = i;
            break;
        }
    }

    if (indexToUpdate == -1) {
        cout << "Account not found with the provided name." << endl;
        return;
    }

    // get attribute to update
    cout << "Which attribute do you want to update?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Year" << endl;
    cout << "3. Pin" << endl;
    cout << "4. Amount" << endl;
    int choice;
    cin >> choice;

    // update the selected attribute
    switch (choice) {
        case 1: {
            cin.ignore();
            string newName;
            cout << "Enter new name: ";
            getline(cin, newName);
            Account_item[indexToUpdate].setName(newName);
            break;
        }
        case 2: {
            int newYear;
            cout << "Enter new year: ";
            cin >> newYear;
            Account_item[indexToUpdate].setYear(newYear);
            break;
        }
        case 3: {
            int newPin;
            cout << "Enter new pin: ";
            cin >> newPin;
            Account_item[indexToUpdate].setPin(newPin);
            break;
        }
        case 4: {
            float newAmount;
            cout << "Enter new amount: ";
            cin >> newAmount;
            Account_item[indexToUpdate].setAmount(newAmount);
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
    }

    cout << "Account updated successfully." << endl;
}


void deleteAccount() {
    string name;
    cin.ignore();
    cout << "Enter the name of the Account you want to delete: ";
    getline (cin, name);

    int indexToDelete = -1;
    for (int i = 0; i < PinCount; i++) {
        if (Account_item[i].getName() == name) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        cout << "Account not found with the provided name." << endl;
        return;
    }

    // shift all elements to the left from the index to delete
    for (int i = indexToDelete; i < PinCount - 1; i++) {
        Account_item[i] = Account_item[i + 1];
    }

    // Decrease the count of Pin
    PinCount--;

    cout << "Account deleted successfully." << endl;
}


void printAllAccounts(){
    cout << "All Accounts: " << endl;
    for (int i = 0; i < PinCount; i++) {
        cout << Account_item[i].getName() << ", " << Account_item[i].getYear() << ", " << Account_item[i].getPin() << ", " << Account_item[i].getAmount() << endl;
    }
}


void QuitFile(string filename) {
    ofstream outFile;
    outFile.open(filename);
    for (int i = 0; i < PinCount; i++) {
        outFile << Account_item[i].getName() << ", " << Account_item[i].getYear() << ", " << Account_item[i].getPin() << ", " << Account_item[i].getAmount() << endl;
    }
    outFile.close();
}



int main()
{

    
    string filename = "Account.txt";

    int input;
    do {
        cout << "|------------------------------------------|" << endl;
        cout << "   1. Load Accounts from an ASCII file" << endl;
        cout << "   2. Insert a new Account" << endl;
        cout << "   3. Search Accounts by year" << endl;
        cout << "   4. Update an Account" << endl;
        cout << "   5. Delete an account" << endl;
        cout << "   6. Print all Accounts" << endl;
        cout << "   7. Quit the program and save the array" << endl;
        cout << "|------------------------------------------|" << endl;
        
        cout << "Enter your input: ";
        cin >> input;
        cout << endl;
        switch (input) {
            case 1:
                readFile(filename);
                break;
            case 2:
                addAccount();
                break;
            case 3:
                ByYear();
                break;
            case 4:
                updateAccount();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                printAllAccounts();
                break;
            case 7:
                QuitFile(filename);
                break;
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (input != 7);


    return 0;
}