#include <iostream>
#include <cstring>

using std:: string, std:: cout;

#pragma once

class DynamicArray{
    private:
    string *name;

    int capacity;
    int arrSize;

    public:

    DynamicArray();
    ~DynamicArray();

    DynamicArray(const DynamicArray &other) = delete;
    DynamicArray operator = (const DynamicArray &other) = delete;

    void add(string valueOne);
    void display();
    void updateAt(int index, string valueOne);
    void deleteAt(int index);
};

DynamicArray :: DynamicArray()
:name{nullptr}, capacity{5}, arrSize{0}
{
    name = new string[capacity];
}

DynamicArray :: ~DynamicArray(){

    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

void DynamicArray :: add(string valueOne){

    if (capacity == arrSize)
    {
        capacity *= 2;

        string *temp = new string[capacity];

        memcpy(temp, name, sizeof(string) * arrSize);

        delete[] name;

        name = temp;
    }
    
    name[arrSize] = valueOne;
    arrSize++;
}

void DynamicArray :: display(){

    for (int i = 0; i < arrSize; i++)
    {
        cout << "Name: " << name[i] << "\n";
    }
}

void DynamicArray :: updateAt(int index, string valueOne){

    if (index > arrSize - 1)
    {
        cout << "Index Not Found\n";
    }

    else
    {
        name[index] = valueOne;
    }
}

void DynamicArray :: deleteAt(int index){

    if (index > arrSize - 1)
    {
        cout << "Index Not Found\n";
    }

    else
    {
        memcpy(name + index, name + index + 1, sizeof(string) * (arrSize - index - 1));
        arrSize--;
    }
}