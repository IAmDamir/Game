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

class Item {
public:
  Item();
  Item(string name, int modifier, string description);

  virtual ~Item();

  const string &getName() const;
  const string &getDescription() const;

  friend std::ostream & operator << (std::ostream &out, const Item & obj);

  friend istream & operator >> (istream& is, Item& item);

protected:
  string name;
  string description;
  int modifier;
public:
  int getModifier() const;
};


#endif //GAME_ITEM_H
