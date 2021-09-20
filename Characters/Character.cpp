#include "Character.h"

Character::Character() {
  name = "";
  level = 1;
  exp = 0;
  items[0] = Weapon(0);
  items[1] = Armor(0);
  items[2] = Book(0);
}

Character::Character(string name, string classname, int maxHP, int HP, int atk, int level, int exp, Item *items) {
  this->name = std::move(name);
  this->classname = std::move(classname);
  this->maxHP = maxHP;
  this->HP = HP;
  this->atk = atk;
  this->level = level;
  this->exp = exp;

  this->items[0] = items[0];
  this->items[1] = items[1];
  this->items[2] = items[2];

  delete (items);
}

Character::~Character() = default;

string Character::getStats(){
  string string1;
  string1.append("\n--------------\n");
  string1.append("Name: " + name + "\n" +
                 "Class: " + classname + "\n" +
                 "HP: " + to_string(HP) + "/" + to_string(maxHP) + "\n" +
                 "Atk: " + to_string(atk) + "\n" +
                 "Exp: " + to_string(exp) + "\n" +
                 "Level: " + to_string(level) + "\n" +
                 "Item 1: " + items[0].getName() + " " + items[0].getDescription() + "\n" +
                 "Item 2: " + items[1].getName() + " " + items[1].getDescription() + "\n" +
                 "Item 3: " + items[2].getName() + " " + items[2].getDescription() + "\n");
  string1.append("\n--------------\n");

  return string1;
}

void Character::gainExp(int exp) {
  int bonusExp = items[2].getName() != "No item"? 1 : items[2].getModifier();
  if (level > 5) {
    exp = exp/2;
  }

  this->exp = this->exp + exp*bonusExp;
  while (this->exp >= 100){
    level++;

    maxHP += 5;
    HP = maxHP;
    atk += 2;

    this->exp -= 100;
  }
}

const string &Character::getName() const {
  return name;
}

void Character::setName(const string &name) {
  Character::name = name;
}

int Character::getMaxHp() const {
  return maxHP;
}

void Character::setMaxHp(int maxHp) {
  maxHP = maxHp;
}

int Character::getHp() const {
  return HP;
}

void Character::setHp(int hp) {
  if (hp > maxHP) {
    HP = maxHP;
  } else {
    HP = hp;
  }
}

int Character::getAtk() const {
  return atk;
}

void Character::setAtk(int atk) {
  Character::atk = atk;
}

int Character::getLevel() const {
  return level;
}

void Character::setLevel(int level) {
  Character::level = level;
}

int Character::getExp() const {
  return exp;
}

void Character::setExp(int exp) {
  Character::exp = exp;
}

const string &Character::getClassname() const {
  return classname;
}

const Item *Character::getItems() const {
  return items;
}

void Character::equipItem(const Item &item) {
  bool isEquipped = false;
  if (item.getName() == "Weapon") {
    if (items[0].getModifier() < item.getModifier()) {
      items[0] = item;
      isEquipped = true;
    }
  } else if (item.getName() == "Armor") {
    if (items[1].getModifier() < item.getModifier()) {
      items[1] = item;
      isEquipped = true;
    }
  } else if (item.getName() == "Book") {
    if (items[2].getModifier() < item.getModifier()) {
      items[2] = item;
      isEquipped = true;
    }
  } else {
    cout << "The Enemy haven't dropped any Item, good luck on your next time" << endl;
  }
  if (isEquipped) {
    cout << "You've equipped " + item.getName() + " " + item.getDescription() << endl;
  } else {
    cout << "Enemy dropped " + item.getName() + " " + item.getDescription() << endl;
    cout << "Since your equipment is better, You've decided to ignore it" << endl;
  }
}

std::ostream &operator<<(ostream &out, const Character &obj) {
  out << obj.getName() << " " << obj.getClassname() << "\n"
      << obj.getHp() << " " << obj.getMaxHp() << "\n"
      << obj.getAtk() << "\n"
      << obj.getLevel() << " " << obj.getExp() << "\n"
      << obj.getItems()[0] << "\n"
      << obj.getItems()[1] << "\n"
      << obj.getItems()[2] << "\n"
      << endl;
  return out;
}

istream &operator>>(istream &is, Character &character) {
  string name, classname;
  int maxHP, HP, atk, level, exp;
  is >> name >> classname >> HP >> maxHP >> atk >> level >> exp;

  Item items[3];
  is >> items[0] >> items[1] >> items[2];

  character = Character(name, classname, maxHP, HP, atk, level, exp, items);
  return is;
}


