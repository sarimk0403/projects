#include "hotelList.h"


hotelList::hotelList() {
    head = nullptr;
}


hotelList::hotelList(const hotelList& other) {

    head = new hotelNode(*other.head);
    

    hotelNode* otherPtr = other.head->getNext();
    hotelNode* currPtr = head;
    while (otherPtr != nullptr) {
        currPtr->setNext(new hotelNode(*otherPtr));
        otherPtr = otherPtr->getNext();
        currPtr = currPtr->getNext();
    }
}


hotelList::~hotelList() {

    hotelNode* currPtr = head;
    while (currPtr != nullptr) {
        hotelNode* temp = currPtr;
        currPtr = currPtr->getNext();
        delete temp;
    }
}

bool hotelList::isEmpty() const {
    return head == nullptr;
}


void hotelList::insert(hotelNode* s) {
    s->setNext(head);
    head = s;
}


bool hotelList::deleteNode(string fName) {
    hotelNode* currPtr = head;
    hotelNode* prevPtr = nullptr;
    
    while (currPtr != nullptr) {
        if (currPtr->getFullName() == fName) {
            if (prevPtr == nullptr) {

                head = currPtr->getNext();
            } else {

                prevPtr->setNext(currPtr->getNext());
            }
            delete currPtr;
            return true;
        }
        
        prevPtr = currPtr;
        currPtr = currPtr->getNext();
    }
    
    return false;
}


bool hotelList::update(string fName, string dateIn, string dateOut) {
    hotelNode* currPtr = head;
    
    while (currPtr != nullptr) {
        if (currPtr->getFullName() == fName) {
            currPtr->setDateIn(dateIn);
            currPtr->setDateOut(dateOut);
            return true;
        }
        
        currPtr = currPtr->getNext();
    }
    
    return false;
}


hotelNode* hotelList::search(string fName) {
    hotelNode* currNode = head;
    
    while (currNode != nullptr) {
        if (currNode->getFullName() == fName) {
            return currNode;
        }
        
        currNode = currNode->getNext();
    }
    
    return nullptr;
}


void hotelList::print() const {
    hotelNode* currNode = head;
    
    while (currNode != nullptr) {
        currNode->print();
        currNode = currNode->getNext();
    }
}

