//
// Created by Damir on 9/18/2021.
//

#include "Item.h"

Item::Item() {
  name = "";
  description = "";
}

Item::Item(string name, int modifier, string description) {
  this->name = name;
  this->modifier = modifier;
  this->description = description;
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
  is >> name;


  is >> modifier;
  is.ignore();
  is.ignore();

  getline(is, description);
  cout << name << " " << modifier << "\n" << description << "\n";

  item = Item(name, modifier, description);
  cout << name << " " << modifier << "\n" << description << "\n";
  return is;
}

std::ostream &operator<<(ostream &out, const Item &item) {
  out << item.getName() << "\n"
      << item.getModifier() << "\n"
      << item.getDescription();
  return out;
}