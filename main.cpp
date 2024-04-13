//main.cpp
#include "DataStructures.h"
#include "SnowSports.h"
#include <iostream>
#include <vector>
using namespace std;

//This function acts as user menu for adding data to the CLL
void CircularLinkedLis(CircularLinkedList& cll) {
    int choice, value;

    do {
        cout << "1. Add Element\n";
        cout << "2. Remove Element\n";
        cout << "3. Display List\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                cll.insert(value);
                break;
            case 2:
                cout << "Enter value to remove: ";
                cin >> value;
                cll.remove(value);
                break;
            case 3:
                cll.display();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {

  int choice;
  bool exit = false;
  CircularLinkedList cll;
  LinkedList list;

  //Menu to add to the data structures.
  while (!exit) {
    cout << "Choose to insert data in each Race:\n";
    cout << "1. Snowboarding\n";
    cout << "2. Skiing\n";
    cout << "3. Ice Skating\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            CircularLinkedLis(cll);
            break;
        case 2:
            list.manageLLL(list);
            break;
        case 3:
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
  }

  
  //Derived class funcrtions 
  Menu menu;
  menu.Interface();

  return 0; // Program ends
}
