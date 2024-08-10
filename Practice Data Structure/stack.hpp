#include <iostream>
#include <cstring>

#pragma once

using std:: string, std:: cout;

class Stack{
    private:
    string *name;

    int capacity;
    int stackSize;

    public:
    
    Stack();
    ~Stack();

    Stack(const Stack &other) = delete;
    Stack operator = (const Stack &other) = delete;

    void push(string valueOne);
    void display();
    void updateAt(int index, string valueOne);
    void pop();
};

Stack :: Stack()
:name{nullptr}, capacity{5}, stackSize{0}
{
    name = new string[capacity];
}

Stack :: ~Stack(){

    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

void Stack :: push(string valueOne){

    if (capacity == stackSize)
    {
        capacity *= 2;
        string *temp = new string[capacity];

        memcpy(temp, name, sizeof(string) * stackSize);

        delete[] name;

        name = temp;
    }

    name[stackSize] = valueOne;
    stackSize++;
}

void Stack :: display(){

    for (int i = 0; i < stackSize; i++)
    {
        cout << "Name: " << name[i] << "\n";
    }
}

void Stack :: updateAt(int index, string valueOne){

    if (index > stackSize)
    {
        cout << "Index Not Found\n";
    }

    else
    {
        name[index] = valueOne;     
    }
}

void Stack :: pop(){

    int index = stackSize - 1;
    
    if (stackSize != 0)
    {
        memcpy(name + index, name + index + 1, sizeof(string) * (stackSize - index - 1));
        stackSize--;
    }

    else
    {
        cout << "Stack Is Empty\n";
    }
}