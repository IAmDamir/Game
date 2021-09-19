//
// Created by Damir on 9/8/2021.
//

#pragma once
#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include "../Items/NullItem.h"
#include "../Items/Weapon.h"
#include "../Items/Armor.h"
#include "../Items/Book.h"

using namespace std;

class Character {
public:

  Character();

  Character(string name, string classname, int maxHP, int HP, int atk, int level, int exp, Item* items);

  virtual ~Character();

  virtual void gainExp(int exp);

  void equipItem(const Item&);

  string getStats();

  const Item *getItems() const;

  const string &getClassname() const;

  const string &getName() const;

  void setName(const string &name);

  int getMaxHp() const;

  void setMaxHp(int maxHp);

  int getHp() const;

  void setHp(int hp);

  int getAtk() const;

  void setAtk(int atk);

  int getLevel() const;

  void setLevel(int level);

  int getExp() const;

  void setExp(int exp);

  friend ostream & operator << (std::ostream &out, const Character & obj);

  friend istream & operator >> (istream& is, Character& character);

protected:
  string classname;
  string name;
  int maxHP;
  int HP;
  int atk;
  int level;
  int exp;
  Item items[3];
};


#endif //GAME_CHARACTER_H
