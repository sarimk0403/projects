#include "hashTable.h"

HashTable::HashTable() {
    count = 0;
    size = 10;
    collisions = 0;
    hashtable = new hotelList[size];
}

HashTable::HashTable(int tableSize) {
    count = 0;
    size = tableSize;
    collisions = 0;
    hashtable = new hotelList[size];
}

HashTable::HashTable(const HashTable& other) {
    count = other.count;
    size = other.size;
    collisions = other.collisions;
    hashtable = new hotelList[size];
    for (int i = 0; i < size; i++) {
        hashtable[i] = other.hashtable[i];
    }
}

HashTable::~HashTable() {
    delete[] hashtable;
}

int HashTable::getSize(){
    return size;
}

int HashTable::getCollisions(){
    return collisions;
}

int HashTable::getCount(){
    return count;
}

int HashTable::hash(string key) {
    long int num = 42;
    for (int i = 0; i < int(key.length()); i++)
        num = (num * 17 + key[i]) % size;
    return num;
}

void HashTable::insert(hotelNode* s) {
    int index = hash(s->getFullName());
    hashtable[index].insert(s);
    count++;
}

bool HashTable::deleteNode(string fName) {
    int index = hash(fName);
    bool result = hashtable[index].deleteNode(fName);
    if (result) {
        count--;
    }
    return result;
}

bool HashTable::update(string fName, string dateIn, string dateOut) {
    int index = hash(fName);
    return hashtable[index].update(fName, dateIn, dateOut);
}

hotelNode* HashTable::search(string fName) {
    int index = hash(fName);
    return hashtable[index].search(fName);
}

void HashTable::print() const {
    for (int i = 0; i < size; i++) {
        if (!hashtable[i].isEmpty()) {
            //std::cout << "Index " << i << ":\n";
            hashtable[i].print();
        }
    }
}
