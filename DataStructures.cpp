//DataStructures.cpp
#include "DataStructures.h"
#include "SnowSports.h"
#include <iostream>
#include <cstring>

using namespace std;

// --- Node Class Implementation ---

Node::Node(SnowSport* sport) : sport(sport), next(nullptr) {}

Node::~Node() {
    delete sport;
}

// --- LinkedList Class Implementation ---

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear(head);
}

void LinkedList::clear(Node* node) {
    if (node) {
        clear(node->next);
        delete node;
    }
}

void LinkedList::add() {
    char name[100], song[100];
    int age;

    cout << "Enter name: ";
    cin.getline(name, 100);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(); // To consume the newline character after integer input
    cout << "Enter song: ";
    cin.getline(song, 100);

    IceSkating* skating = new IceSkating(name, age, song);
    addRecursive(head, skating);
}

void LinkedList::addRecursive(Node*& node, SnowSport* sport) {
    if (!node) {
        node = new Node(sport);
    } else {
        addRecursive(node->next, sport);
    }
}

void LinkedList::display() const {
    displayRecursive(head);
}

void LinkedList::displayRecursive(Node* node) const {
    if (node) {
        node->sport->display();
        cout << endl;
        displayRecursive(node->next);
    }
}

bool LinkedList::remove(const char* name) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->sport->getEntryName(), name) == 0) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return true; // Node found and removed
        }
        prev = current;
        current = current->next;
    }
    return false; // Node not found
}

SnowSport* LinkedList::get(const char* name) const {
    Node* current = head;
    while (current != nullptr) {
        if (strcmp(current->sport->getEntryName(), name) == 0) {
            return current->sport;
        }
        current = current->next;
    }
    return nullptr; // Not found
}

void LinkedList::removeAll() {
    clear(head);
    head = nullptr; // Ensure the head is reset after clearing
}

const char* SnowSport::getEntryName() const {
    return EntryName;
}

SnowSport* LinkedList::retrieval(const char* name) const {
    Node* current = head;
    while (current != nullptr) {
        if (strcmp(current->sport->getEntryName(), name) == 0) {
            return current->sport;
        }
        current = current->next;
    }
    return nullptr; // Not found
}

Node* LinkedList::removeRecursive(Node* node, const char* name, bool& removed) {
    if (node == nullptr) { // Base case: reached the end of the list without finding a match
        removed = false;
        return nullptr;
    }

    if (strcmp(node->sport->getEntryName(), name) == 0) { // Match found
        Node* nextNode = node->next;
        delete node->sport; // Delete the SnowSport object
        delete node; // Delete the node
        removed = true; // Indicate that removal was successful
        return nextNode; // Return the next node to reconnect the list
    }

    // Recursive call for the next node, reconnecting the potentially new next node
    node->next = removeRecursive(node->next, name, removed);
    return node; // Return the current node to maintain the list structure
}

bool LinkedList::removal(const char* name) {
    bool removed = false;
    head = removeRecursive(head, name, removed); // Start recursion from the head of the list
    return removed; // Return the status of removal
}

void LinkedList::removeSportByNameLLL(LinkedList &list) {
  char nameToRemove[100]; // Buffer to hold the input name

  cout << "Enter the name of the sport to remove: ";
  cin.getline(nameToRemove,
              sizeof(nameToRemove)); // Read the full line of input

  bool removed = list.removal(nameToRemove);
  if (removed) {
    cout << nameToRemove << " has been successfully removed." << endl;
  } else {
    cout << "No entry found for " << nameToRemove << "." << endl;
  }
}

void LinkedList::retrieveSportByNameLLL(const LinkedList &list) {
  char nameToRetrieve[100]; // Buffer to hold the input name

  cout << "Enter the name of the sport to retrieve: ";
  cin.getline(nameToRetrieve,
              sizeof(nameToRetrieve)); // Read the full line of input

  SnowSport *sport = list.retrieval(nameToRetrieve);
  if (sport != nullptr) {
    sport->display(); // Assuming display prints the details
  } else {
    cout << "No entry found for " << nameToRetrieve << "." << endl;
  }
}

void LinkedList::manageLLL(LinkedList& list) {
    int choice;

    do {
        cout << "\nSnow Sports Management Menu\n";
        cout << "1. Add a Sport\n";
        cout << "2. Remove a Sport by Name\n";
        cout << "3. Retrieve a Sport by Name\n";
        cout << "4. Display All Sports\n";
        cout << "5. Remove All Sports\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Properly clear the input buffer

        switch (choice) {
        case 1:
            list.add();
            break;
        case 2:
            removeSportByNameLLL(list);
            break;
        case 3:
            retrieveSportByNameLLL(list);
            break;
        case 4:
            list.display();
            break;
        case 5:
            list.removeAll();
            cout << "All sports have been removed from the list." << endl;
            break;
        case 6:
            cout << "Exiting the menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

// CLLNode constructor
CLLNode::CLLNode(int val) : data(val), next(nullptr) {}

// Constructor
CircularLinkedList::CircularLinkedList() : tail(nullptr) {}

// Destructor
CircularLinkedList::~CircularLinkedList() {
    if (tail) {
        CLLNode* head = tail->next;
        tail->next = nullptr; // Break the circular link

        while (head != nullptr) {
            CLLNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

// Insertion Method
void CircularLinkedList::insert(int value) {
    CLLNode* newCLLNode = new CLLNode(value);
    if (!tail) {
        tail = newCLLNode;
        tail->next = tail;
    } else {
        newCLLNode->next = tail->next;
        tail->next = newCLLNode;
        tail = newCLLNode; // update tail to new CLLNode
    }
}

// Deletion Method
void CircularLinkedList::remove(int value) {
    if (!tail) return;

    CLLNode* current = tail;
    do {
        if (current->next->data == value) {
            CLLNode* temp = current->next;
            current->next = temp->next;
            if (temp == tail) tail = current; // If tail was deleted
            if (temp == tail->next) tail = nullptr; // List becomes empty
            delete temp;
            break;
        }
        current = current->next;
    } while (current != tail);
}

// Display Method
void CircularLinkedList::display() const {
    if (!tail) return;

    CLLNode* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}
