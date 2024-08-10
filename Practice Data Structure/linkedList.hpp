#include <iostream>

#pragma once

using std:: string, std:: cout;

struct Node
{
    string name;

    Node *next;
};

class LinkedList{
    private: 
    Node *head;

    int linkedSize;

    public:

    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList &other) = delete;
    LinkedList operator = (const LinkedList &other) = delete;

    void add(string valueOne);
    void display();
    void updateAt(int index, string valueOne);
    void deleteAt(int index);
};

LinkedList :: LinkedList()
:head{nullptr}, linkedSize{0}
{

}

LinkedList :: ~LinkedList(){

    if (head != nullptr)
    {
        delete head;
        head = nullptr;
    }
}

void LinkedList :: add(string valueOne){

    Node *add = new Node;
    add->name = valueOne;
    add->next = nullptr;

    if (head == nullptr)
    {
        head = add;
    }

    else
    {
        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = add;
    }

    linkedSize++;
}

void LinkedList :: display(){

    Node *current = head;

    while (current != nullptr)
    {
        cout << "Name: " << current->name;
        cout << " ----->";
        current = current->next;
    }
}

void LinkedList :: updateAt(int index, string valueOne){

    Node *current = head;
    int i = 0;

    if (index > linkedSize - 1)
    {
        cout << "Node Not Found\n";
    }

    else
    {
        while (current->next != nullptr && i < index)
        {
            current = current->next;
            i++;
        }

        current->name = valueOne;
    }   
} 

void LinkedList :: deleteAt(int index){

    Node *current = head;
    Node *prev = head;
    int i = 0;

    if (index > linkedSize - 1)
    {
        cout << "Node Not Found\n";
    }

    else
    {
        while (current->next != nullptr && i < index)
        {
            prev = current;
            current = current->next;
            i++;
        }

        if (index != 0)
        {
            prev->next = current->next;
            current->next = nullptr;

            delete current;
        }

        else
        {
            head = current->next;
        }
    }
}