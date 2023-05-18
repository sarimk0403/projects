#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hotelList.h"
#include "hashTable.h"

using namespace std;


void displayMenu() {
    cout << "Choose an option:" << endl;
    cout << "1. Add a new customer " << endl;
    cout << "2. Delete customer" << endl;
    cout << "3. Update customer" << endl;
    cout << "4. Search customer" << endl;
    cout << "5. Print all the customers" << endl;
    cout << "6. Exit" << endl;
}

void insertRecord(HashTable& hashTable) {
    string fName, dateIn, dateOut;
    cin.ignore();
    cout << "Enter customer's full name: ";
    getline(cin, fName);
    cout << "Enter your check in date (MM-DD-YYYY): ";
    getline(cin, dateIn);
    cout << "Enter your check out date (MM-DD-YYYY): ";
    getline(cin, dateOut);
    hotelNode* student = new hotelNode(fName, dateIn, dateOut);
    hashTable.insert(student);
    cout << "Record inserted." << endl;
}

void deleteRecord(HashTable& hashTable) {
    string fName;
    cin.ignore();
    cout << "Enter customer's full name to delete: ";
    getline(cin, fName);
    if (hashTable.deleteNode(fName)) {
        cout << "Record deleted." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

void updateRecord(HashTable& hashTable) {
    string fName, dateIn, dateOut;
    cin.ignore();
    cout << "Enter full name of customer to update: ";
    getline(cin, fName);
    cout << "Enter your new check in date (MM-DD-YYYY): ";
    getline(cin, dateIn);
    cout << "Enter your new check out date (MM-DD-YYYY): ";
    getline(cin, dateOut);
    if (hashTable.update(fName, dateIn, dateOut)) {
        cout << "Record updated successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

void searchRecord(HashTable& hashTable) {
    string fName;
    cin.ignore();
    cout << "Enter full name of customer to search: ";
    getline(cin, fName);
    hotelNode* result = hashTable.search(fName);
    if (result) {
        result->print();
    } else {
        cout << "Record not found." << endl;
    }
}

void printTable(HashTable& hashTable) {
    cout << "Customers' information :" << endl;
    hashTable.print();
}



int main() {

    HashTable hashTable;
    // Display menu
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                insertRecord(hashTable);
                break;
            case 2:
                deleteRecord(hashTable);
                break;
            case 3:
                updateRecord(hashTable);
                break;
            case 4:
                searchRecord(hashTable);
                break;
            case 5:
                printTable(hashTable);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}



