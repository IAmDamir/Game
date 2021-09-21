//
// Created by Damir on 9/18/2021.
//

#include "Item.h"


Item::Item() {
  name = "";
  description = "";
  modifier = 0;
}

Item::Item(int modifier) {
  this->modifier = modifier;
  name = "";
  description = "";
}

Item::Item(string name, int modifier, string description) {
  this->name = std::move(name);
  this->modifier = modifier;
  this->description = std::move(description);
}

Item::~Item() = default;

const string &Item::getName() const {
  return name;
}

const string &Item::getDescription() const {
  return description;
}

int Item::getModifier() const {
  return modifier;
}

istream &operator>>(istream &is, Item &item) {
  string name, description;
  int modifier;
  is >> name >> modifier;

  // Ignores the endline characters to make sure that getline() will catch the next line
  is.ignore();
  is.ignore();

  // Using a getline() function to get a full line until endline (not until whitespace)
  getline(is, description);

  item = Item(name, modifier, description);
  return is;
}

std::ostream &operator<<(ostream &out, const Item &item) {
  out << item.getName() << "\n"
      << item.getModifier() << "\n"
      << item.getDescription();
  return out;
}

