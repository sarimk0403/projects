#include "hotelNode.h"

hotelNode::hotelNode() {
    FullName = "";
    DateIn = "";
    DateOut = "";
    Next = nullptr;
}

hotelNode::hotelNode(string fName, string dateIn, string dateOut) {
    FullName = fName;
    DateIn = dateIn;
    DateOut = dateOut;
    Next = nullptr;
}

hotelNode::hotelNode(const hotelNode& other) {
    FullName = other.FullName;
    DateIn = other.DateIn;
    DateOut = other.DateOut;
    Next = other.Next;
}

hotelNode::~hotelNode() {
}

// Getter and Setter methods
string hotelNode::getFullName() const {
    return FullName;
}

string hotelNode::getDateIn() const {
    return DateIn;
}

string hotelNode::getDateOut() const {
    return DateOut;
}

hotelNode* hotelNode::getNext() const {
    return Next;
}

void hotelNode::setFullName(string fName) {
    FullName = fName;
}

void hotelNode::setDateIn(string dateIn) {
    DateIn = dateIn;
}

void hotelNode::setDateOut(string dateOut) {
    DateOut = dateOut;
}

void hotelNode::setNext(hotelNode* n) {
    Next = n;
}

// Print method
void hotelNode::print() const {
    cout << "---------------------------" << endl;
    cout << "Full Name: " << FullName << endl;
    cout << "Date In: " << DateIn << endl;
    cout << "Date Out: " << DateOut << endl;
    cout << "---------------------------" << endl;
}
