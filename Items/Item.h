//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <string>
#include <iostream>
#include "../RandomNumberGenerator.h"

using namespace std;

// Superclass of all ...Item classes
// TODO make items that ACTUALLY can change character's stats
class Item {
public:
  Item();
  explicit Item(int modifier);
  // This constructor will set all attributes equal to ones that is in argument
  // Made only for loading the exact same Items from the file, since default constructor generates random items

/* Is it better to use this constructor or default constructor and Setters?
 * - Temirgaliyev Damir
 *  */
  Item(string name, int modifier, string description);

  virtual ~Item();

  [[nodiscard]] const string &getName() const;
  [[nodiscard]] const string &getDescription() const;
  [[nodiscard]] int getModifier() const;

  // Overloading output operator to save items in file
  friend std::ostream & operator << (std::ostream &out, const Item & obj);

  // Overloading input operator to load items from file
  friend istream & operator >> (istream& is, Item& item);

protected:
  string name;
  string description;
  int modifier;
};


#endif //GAME_ITEM_H
