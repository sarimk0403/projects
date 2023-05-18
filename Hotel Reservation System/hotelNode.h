#ifndef HOTELNODE_H
#define HOTELNODE_H

#include <iostream>
#include <string>

using namespace std;

class hotelNode {
        
    public:
        // Default constructor
        hotelNode();
        hotelNode(string fName, string dateIn, string dateOut);
        hotelNode(const hotelNode& other);
        ~hotelNode();
        
        // Getter and Setter methods
        string getFullName() const;
        string getDateIn() const;
        string getDateOut() const;
        hotelNode* getNext() const;
        
        
        void setFullName(string fName);
        void setDateIn(string dateIn);
        void setDateOut(string dateOut);
        void setNext(hotelNode* n);
        
        // Print method
        void print() const;
        
    private:
        string FullName;
        string DateIn;
        string DateOut;
        hotelNode* Next;
};

#endif
