#include <iostream>
#include <cstring>

using std:: string, std:: cout;

#pragma once

class Queue{
    private:
    string *name;

    int capacity;
    int queueSize;

    public:

    Queue();
    ~Queue();

    Queue(const Queue &other) = delete;
    Queue operator = (const Queue &other) = delete;

    void enque(string valueOne);
    void display();
    void updateAt(int index, string valueOne);
    void deque();
};

Queue :: Queue()
:name{nullptr}, capacity{5}, queueSize{0}
{
    name = new string[capacity];
}

Queue :: ~Queue(){

    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

void Queue :: enque(string valueOne){

    if (capacity == queueSize)
    {
        capacity *= 2;
        string *temp = new string[capacity];

        memcpy(temp, name, sizeof(string) * queueSize);

        delete[] name;

        name = temp;
    }

    name[queueSize] = valueOne;
    queueSize++;
}

void Queue :: display(){

    for (int i = 0; i < queueSize; i++)
    {
        cout << "Name: " << name[i] << "\n";
    }
}

void Queue :: updateAt(int index, string valueOne){

    if (index > queueSize)
    {
        cout << "Index Not Found\n";
    }

    else
    {
        name[index] = valueOne;
    }
}

void Queue :: deque(){

    int index = 0;

    if (queueSize != 0)
    {
        memcpy(name + index, name + index + 1, sizeof(string) * (queueSize - index - 1));
        queueSize--;
    }

    else
    {
        cout << "Queue Is Empty\n";
    }   
}

