//DataStructures.h
//This holds the data for the data structures
#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include "SnowSports.h"

class SnowSport;

// LLL
// **********************************

class Node {
public:
    SnowSport* sport;
    Node* next;

    Node(SnowSport* sport);
    ~Node();
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool remove(const char* name);
    SnowSport* get(const char* name) const;
    void removeAll();
    void add();
    void display() const;
    SnowSport* retrieval(const char* name) const;
    bool removal(const char* name); 
    void removeSportByNameLLL(LinkedList &list);
    void retrieveSportByNameLLL(const LinkedList &list);
    void manageLLL(LinkedList& list);

private:
    Node* head;
    Node* removeRecursive(Node* node, const char* name, bool& removed);
    void clear(Node* node);
    void addRecursive(Node*& node, SnowSport* sport);
    void displayRecursive(Node* node) const;
};



// CLL
//****************************

class CLLNode {
public:
    int data;
    CLLNode* next;

    CLLNode(int val);
};

class CircularLinkedList {
private:
    CLLNode* tail;

public:
    CircularLinkedList();
    ~CircularLinkedList();

    void insert(int value);
    void remove(int value);
    void display() const;
};


#endif // DATASTRUCTURES_H
