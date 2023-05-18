#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "hotelList.h"

class HashTable {
public:
    HashTable();
    HashTable(int tableSize);
    HashTable(const HashTable& other);
    ~HashTable();
    
    
    int hash(string key);
    void insert(hotelNode* s);
    bool deleteNode(string fName);
    bool update(string fName, string dateIn, string dateOut);
    hotelNode* search(string fName);
    int getCollisions();
    int getSize();
    int getCount();
    void print() const;
    
    
private:
    int count;
    int size;
    int collisions;
    hotelList* hashtable;
};

#endif
