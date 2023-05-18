#ifndef HOTELLIST_H
#define HOTELLIST_H

#include "hotelNode.h"

class hotelList {
    
    public:
        hotelList();
        hotelList(const hotelList& other);
        ~hotelList();
        
        //utility methods
        void insert(hotelNode* s);
        bool deleteNode(string fName);
        bool update(string fName, string dateIn, string dateOut);
        hotelNode* search(string fName);
        bool isEmpty() const;
        void print() const;
        
    private:
        hotelNode* head;
};

#endif
