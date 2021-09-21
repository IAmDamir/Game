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

// A character class is a superclass of any class e.g. swordsman etc.
// Currently, character have no gold because it cannot be used inside the game
// TODO implement functions that will make gold valuable inside the game

/* Classes was made because of misunderstanding, when making them I thought of second task
 * 2.	List all classes and explain each of them with 1-2 sentence (20%)
 * I thought "classes" mentioned here is character classes that could be chosen by the player
 * So I made only one class, but it could be easily extended in the future
 * - Temirgaliyev Damir
 *  */
class Character {
public:

  Character();
  // This constructor will set all attributes equal to ones that is in argument
  // Made only for loading the exact same character from the file
  Character(string name, string classname, int maxHP, int HP, int atk, int level, int exp, Item* items);

  virtual ~Character();

  // Adds exp
  // TODO vary the exp gain for different characters
  // TODO balance the exp gain
  virtual void gainExp(int exp);

  // Equips the passed item if it is better than equipped one
  void equipItem(const Item&);

  string getStats();

  [[nodiscard]] const Item *getItems() const;

  [[nodiscard]] const string &getClassname() const;

  [[nodiscard]] const string &getName() const;

  void setName(const string &name);

  [[nodiscard]] int getMaxHp() const;

  void setMaxHp(int maxHp);

  [[nodiscard]] int getHp() const;

  void setHp(int hp);

  [[nodiscard]] int getAtk() const;

  void setAtk(int atk);

  [[nodiscard]] int getLevel() const;

  void setLevel(int level);

  [[nodiscard]] int getExp() const;

  void setExp(int exp);

  // Overloading output operator to save character in file
  friend ostream & operator << (std::ostream &out, const Character & obj);

  // Overloading input operator to load character from file
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
