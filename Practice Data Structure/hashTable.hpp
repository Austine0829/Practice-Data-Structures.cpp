#include <iostream>
#include <list>
#include <cstring>

#pragma once

using namespace std;

class Hash{
    private:
    static const int hashSize = 10;
    list<pair<int, string>> table[hashSize];

    public:

    int hash(int key);
    void add(int key, string valueOne);
    void display();
    void updateValue(int key, string valueOne);
    void deleteKey(int key);
    
};

int Hash :: hash(int key){

    return key % hashSize;
}

void Hash :: add(int key, string valueOne){

    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto iterator = begin(cell);
    bool keyExisting = false;

    for (; iterator != end(cell); iterator++)
    {
        if (iterator->first == key)
        {
            keyExisting = true;
            iterator->second = valueOne;

            break;
        }
    }

    if (!keyExisting)
    {
        cell.emplace_back(key, valueOne);
    }
}

void Hash :: display(){

    for (int i = 0; i < hashSize; i++)
    {
        if (table[i].size() == 0)
        {
            continue;
        }
        
        auto iterator = table[i].begin();

        for (; iterator != table[i].end(); iterator++)
        {
            cout << "Key: " << iterator->first << "\n";
            cout << "Name: " << iterator->second << "\n";
            cout << "--------------------------------\n";
        }
        
    }
}

void Hash :: updateValue(int key, string valueOne){

    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto iterator = begin(cell);

    for (; iterator != end(cell); iterator++)
    {
        if (iterator->first == key)
        {
            iterator->second = valueOne;
        }
    }
}

void Hash :: deleteKey(int key){

    int hashValue = hash(key);
    auto &cell = table[hashValue];
    auto iterator = begin(cell);

    for (; iterator != end(cell); iterator++)
    {
        if (iterator->first == key)
        {
            iterator = cell.erase(iterator);
        }
    }
}

