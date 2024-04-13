// SnowSports.h
#ifndef SNOW_SPORTS_H
#define SNOW_SPORTS_H
#include "DataStructures.h"

#include <string>
#include <vector>

using namespace std;

/*--------Base Class--------*/

class SnowSport {
public:
  SnowSport(const char *name = nullptr, int age = 0);
  SnowSport(const SnowSport &other);
  SnowSport &operator=(const SnowSport &other);
  virtual ~SnowSport();

  const char *getEntryName() const;
  void setEntryName(const char *name);
  void setAge(int age);
  virtual void display() const;

protected:
  char *EntryName; // Dynamically allocated array of characters
  int Age;
};

/*--------Derived Classes--------*/

// Derived class for Skiing
class Skiing : public SnowSport {
public:
  bool BuySkiis();
  bool ViewSlopes();
  bool WatchRaces();

private:
  string Skates;
};

// Derived class for Ice Skating
class IceSkating : public SnowSport {
public:
  IceSkating(const char *name = nullptr, int age = 0,
             const char *song = nullptr);
  IceSkating(const IceSkating &other);
  IceSkating &operator=(const IceSkating &other);
  ~IceSkating();

  void setSong(const char *song);
  void display() const override;

  bool ViewDances();
  bool DriveZamboni();
  bool ChooseMusic();

private:
  char *Song; // Dynamically allocated array of characters for entries
};

// Derived class for Snowboarding
class Snowboarding : public SnowSport {
public:
  bool PracticeTricks();
  bool DoTricks();
  bool ChangeBoard();

private:
  string Board;
};

//Class functions for the menu
class Menu {
public:
  int GetUserInput(int min, int max, const char *errorMsg);
  int GetInt();
  bool Interface();
  bool DerivedClassFunctions(int Sport);
  void displayMenu();

protected:
  int Choice;
  SnowSport Sport;
  Snowboarding Snowboard;
  IceSkating IceSkate;
  Skiing Ski;
};

#endif // SNOW_SPORTS_H
