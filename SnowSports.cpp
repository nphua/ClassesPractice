// SnowSports.cpp
#include "SnowSports.h"
#include "DataStructures.h" // This defines CircularLinkedList and LinkedList
#include <cstring>
#include <iostream>

using namespace std;

/***************************************/
// Gets intputs for the user.
/***************************************/

int Menu::GetUserInput(int min, int max, const char *errorMsg) {
  int input;
  while (true) {
    input = GetInt();
    if (cin.fail() || input < min || input > max) {
      cin.clear();
      cin.ignore(static_cast<std::streamsize>(-1), '\n');
      cout << errorMsg << endl;
    } else {
      cin.ignore(static_cast<std::streamsize>(-1), '\n');
      break;
    }
  }
  return input;
}

//Gets the int value if its wrong it asks the user to correctly input again
int Menu::GetInt() {
  int num;
  cin >> num;
  while (cin.fail()) // clear the fail flag
  {
    cin.clear();
    // clear out the entire buffer
    cin.ignore(200, '\n');
    // have user re-enter the number
    cout << "Not an integer. Please enter an integer. \n";
    cin >> num;
  }
  cin.ignore(200, '\n');
  return num;
}

/***************************************/
// Menu Function For Base & User Interaction
/***************************************/

bool Menu::Interface() {

  int choice;

  do {
    cout << "-----------------------------" << endl;
    cout << "Attending Events" << endl;
    cout << "(1)Skiing" << endl;
    cout << "(2)Ice Skating" << endl;
    cout << "(3)Snow Boarding" << endl;
    cout << "(4)EXIT" << endl;
    cout << "------------------------------" << endl;
    cout << "Enter your choice: ";
    choice = GetUserInput(1, 4, "Invalid choice. Please try again: ");

    switch (choice) {
    case 1:
      cout << "Skiings" << endl;
      DerivedClassFunctions(1);
      break;
    case 2:
      cout << "Ice Skating" << endl;
      DerivedClassFunctions(2);
      break;
    case 3:
      cout << "Snow Boarding" << endl;
      DerivedClassFunctions(3);
      break;
    case 4:
      cout << "EXIT" << endl;
      break;
    }

  } while (choice != 4);

  return true;
}

//Menu function to access the derived class functions
bool Menu::DerivedClassFunctions(int Sport) {
  int choice;

  do {
    // Display the menu based on the sport
    switch (Sport) {
    case 1:
      cout << "-----------------------------\n"
              "Attending Skiing Events\n"
              "(1)Buy New Skiis\n"
              "(2)View Slopes\n"
              "(3)Watch Races\n"
              "(4)EXIT\n"
              "------------------------------\n";
      break;
    case 2:
      cout << "-----------------------------\n"
              "Attending Ice Skating Events\n"
              "(1)View Dances\n"
              "(2)Drive Zamboni\n"
              "(3)Choose Music\n"
              "(4)EXIT\n"
              "------------------------------\n";
      break;
    case 3:
      cout << "-----------------------------\n"
              "Attending Snow Boarding Events\n"
              "(1)Practice Tricks\n"
              "(2)Do Tricks\n"
              "(3)Change Board\n"
              "(4)EXIT\n"
              "------------------------------\n";
      break;
    }

    cout << "Enter your choice: ";
    choice = GetUserInput(1, 4, "Invalid choice. Please try again: ");

    // Handle the choice
    switch (choice) {
    case 1: // Case for the first choice in any sport
      switch (Sport) {
      case 1:
        cout << "(1)Buy New Skiis" << endl;
        Ski.BuySkiis();
        break;
      case 2:
        cout << "(1)View Dances" << endl;
        IceSkate.ViewDances();
        break;
      case 3:
        cout << "(1)Practice Tricks" << endl;
        Snowboard.PracticeTricks();
        break;
      }
      break;
    case 2: // Case for the second choice in any sport
      switch (Sport) {
      case 1:
        cout << "(2)View Slopes" << endl;
        Ski.ViewSlopes();
        break;
      case 2:
        cout << "(2)Drive Zamboni" << endl;
        IceSkate.DriveZamboni();
        break;
      case 3:
        cout << "(2)Do Tricks" << endl;
        Snowboard.DoTricks();
        break;
      }
      break;
    case 3: // Case for the third choice in any sport
      switch (Sport) {
      case 1:
        cout << "(3)Watch Races" << endl;
        Ski.WatchRaces();
        break;
      case 2:
        cout << "(3)Choose Music" << endl;
        IceSkate.ChooseMusic();
        break;
      case 3:
        cout << "(3)Change Board" << endl;
        Snowboard.ChangeBoard();
        break;
      }
      break;
    case 4: // Exit case
      cout << "EXIT" << endl;
      break;
    }

  } while (choice != 4);

  return true;
}

/****************************
--Base Class--
****************************/
// SnowSport class implementations

SnowSport::SnowSport(const char *name, int age) : Age(age) {
  EntryName = name ? new char[strlen(name) + 1] : nullptr;
  if (name)
    strcpy(EntryName, name);
}

SnowSport::SnowSport(const SnowSport &other) : Age(other.Age) {
  EntryName = other.EntryName ? new char[strlen(other.EntryName) + 1] : nullptr;
  if (other.EntryName)
    strcpy(EntryName, other.EntryName);
}

SnowSport &SnowSport::operator=(const SnowSport &other) {
  if (this != &other) {
    delete[] EntryName;
    Age = other.Age;
    EntryName =
        other.EntryName ? new char[strlen(other.EntryName) + 1] : nullptr;
    if (other.EntryName)
      strcpy(EntryName, other.EntryName);
  }
  return *this;
}

SnowSport::~SnowSport() { delete[] EntryName; }

void SnowSport::setEntryName(const char *name) {
  delete[] EntryName;
  EntryName = name ? new char[strlen(name) + 1] : nullptr;
  if (name)
    strcpy(EntryName, name);
}

void SnowSport::setAge(int age) { Age = age; }

void SnowSport::display() const {
  cout << "Name: " << (EntryName ? EntryName : "No Name") << ", Age: " << Age;
}

/****************************
--Dervied Classes--
****************************/

//****************************************

// The User can buy new Skiis
bool Skiing::BuySkiis() {
  // Implementation
  cout << "You need some new skiis?" << endl;
  return true;
}

// The User can see the Slopes their on.
bool Skiing::ViewSlopes() {
  // Implementation
  cout << "This slope is really pretty!" << endl;
  return true;
}

// The User can watch the Races.
bool Skiing::WatchRaces() {
  // Implementation
  cout << "Lets watch the race!" << endl;
  return true;
}

//Derived Ice Skating functions.
//*******************************************

IceSkating::IceSkating(const char* name, int age, const char* song) : SnowSport(name, age) {
    Song = song ? new char[strlen(song) + 1] : nullptr;
    if (song) strcpy(Song, song);
}

IceSkating::~IceSkating() {
    delete[] Song;
}

void IceSkating::setSong(const char* song) {
    delete[] Song;
    Song = song ? new char[strlen(song) + 1] : nullptr;
    if (song) strcpy(Song, song);
}

void IceSkating::display() const {
    SnowSport::display();
    cout << ", Song: " << (Song ? Song : "No Song") << endl;
}

//***************************************************

bool IceSkating::ViewDances() {
  // Implementation
  cout << "This dance is really cool!" << endl;
  return true;
}

bool IceSkating::DriveZamboni() {
  // Implementation
  cout << "This is a really fun activity!" << endl;
  return true;
}

bool IceSkating::ChooseMusic() {
  // Implementation
  cout << "Groovy!" << endl;
  return true;
}

//Derived Snowboarding Functions
//***************************************************

bool Snowboarding::PracticeTricks() {
  // Implementation
  cout << "I think you getting better at this!" << endl;
  return true;
}

bool Snowboarding::DoTricks() {
  // Implementation
  cout << "You do tricks!" << endl;
  return true;
}

bool Snowboarding::ChangeBoard() {
  // Implementation
  cout << "Trying to replace your old board?" << endl;
  return true;
}

//**************************************************
