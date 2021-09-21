//
// Created by Damir on 9/18/2021.
//

#include "Enemy.h"

Enemy::Enemy(int modifier, string name) {
  this->name = std::move(name);
  this->modifier = modifier;
  RandomNumberGenerator randomNumberGenerator;
  maxHP = 10 + randomNumberGenerator.getRandomNumber() % 10 + this->modifier*2;
  HP = maxHP;
  atk = 2 + (randomNumberGenerator.getRandomNumber() % this->modifier + 1) + this->modifier;
}

Enemy::~Enemy() = default;

Item Enemy::getItem() const {
  Item randItem;
  RandomNumberGenerator randomNumberGenerator;
  int itemType = randomNumberGenerator.getRandomNumber() % 12;
  // Defines a chances to drop item
  // currently it is 1/12 chance to drop nothing or a Book
  // and 5/12 chances to drop Weapon or Armor
  if (itemType == 0) {
    randItem = NullItem();
  } else if (itemType == 11) {
    randItem = Book(modifier);
  } else if (itemType < 6){
    randItem = Weapon(modifier);
  } else {
    randItem = Armor(modifier);
  }

  return randItem;
}

void Enemy::encounter(Character &character) {
  cout << "You've encountered a " + name << endl;
  RandomNumberGenerator randomNumberGenerator;
  bool run = false;

  // Fight will continue until enemy or character dies or character escapes
  while (HP > 0 && character.getHp() > 0 && !run) {
    cout << "Choose your actions" << endl << endl;
    cout << "1: Attack" << endl;
    cout << "2: Run" << endl;

    cout<<endl<<"Choice: ";
    int choice;
    cin>>choice;

    switch (choice) {
      case 1: {
        // Sets a attack value for an attack
        int characterAttackValue = randomNumberGenerator.getRandomNumber() % character.getLevel() + 1;
        characterAttackValue += character.getAtk() + characterAttackValue;
        // Checks if character have a weapon and adds its modifier to attack value
        if (character.getItems()[0].getName() == "Weapon") {
          characterAttackValue += character.getItems()[0].getModifier();
        }
        // Subtracts attack value from enemy HP
        HP  = HP - characterAttackValue;
        cout << "You've attacked the " + name + " by " + to_string(characterAttackValue) << endl;
        // Ends fight if enemy is defeated
        if (HP <= 0) {
          break;
        }

        attack(character);
        break;
      }
      case 2: {
        int chanceOfBeingCaught = randomNumberGenerator.getRandomNumber() % HP;
        if (chanceOfBeingCaught < modifier) {
          run = true;
          cout << "You've successfully slipped from " + name << endl;
          break;
        }
        cout << "You've been caught by the " + name;
        attack(character);
        break;
      }
      default: break;
    }
  }
}

int Enemy::getHp() const {
  return HP;
}

int Enemy::getAtk() const {
  return atk;
}

int Enemy::getModifier() const {
  return modifier;
}

int Enemy::getMaxHp() const {
  return maxHP;
}

void Enemy::attack(Character &character) const {
  RandomNumberGenerator randomNumberGenerator;
  int atkModifier = randomNumberGenerator.getRandomNumber() % modifier + 1;
  int enemyAttackValue = atk + atkModifier - character.getItems()[1].getModifier();
  // Sets enemy's attack value to 0 if it is below 0
  if (enemyAttackValue < 0) {
    enemyAttackValue = 0;
  }
  character.setHp(character.getHp() - enemyAttackValue);
  cout << "The " + name + " attacked You by " + to_string(enemyAttackValue) << endl;
}
