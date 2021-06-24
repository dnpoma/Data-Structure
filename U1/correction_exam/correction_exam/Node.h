#pragma once

#include <iostream>
#include "Person.h"

class Node
{
private:

    //int data;
    Person client;
    Node* next;

public:

    Node();

    //Node(int, Node*);

    Node(Person, Node*);

    Person getDataClient();

    void setDataClient(Person);

    //int getData();

    Node* getNext();

    //void setData(int);

    void setNext(Node*);
};


