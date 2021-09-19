//
// Created by Damir on 9/18/2021.
//

#include "Enemy.h"

Enemy::Enemy(int modifier) {
  this->modifier = modifier;
  RandomNumberGenerator randomNumberGenerator;
  maxHP = 12 + randomNumberGenerator.getRandomNumber() % 5 + this->modifier;
  HP = maxHP;
  atk = 2 + (randomNumberGenerator.getRandomNumber() % this->modifier) + this->modifier;
}

Enemy::~Enemy() = default;

Item Enemy::getItem() {
  Item randItem;
  RandomNumberGenerator randomNumberGenerator;
  int itemType = randomNumberGenerator.getRandomNumber() % 12;
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
  RandomNumberGenerator randomNumberGenerator;

  while (HP > 0 && character.getHp() > 0) {
    cout << randomNumberGenerator.getRandomNumber() << endl;
    cout << "Choose your actions" << endl << endl;
    cout << "1: Attack" << endl;
    cout << "0: Run" << endl;

    cout<<endl<<"Choice: ";
    int choice;
    cin>>choice;

    switch (choice) {
      case 1: {
        int atkModifier = randomNumberGenerator.getRandomNumber() % character.getLevel() + 1;
        int characterAttackValue = character.getAtk() + atkModifier;
        if (character.getItems()[0].getName() == "Weapon") {
          characterAttackValue += character.getItems()[0].getModifier();
        }
        HP  = HP - characterAttackValue;
        cout << "You've attacked the Enemy by " + to_string(characterAttackValue) << endl;

        if (HP <= 0) {
          cout << "Congrats, You've defeated the enemy" << endl;
          character.equipItem(getItem());
          int exp = modifier > 4? 20*modifier: 10*modifier;
          character.gainExp(exp);
          break;
        }

        attack(character);
        break;
      }
      case 2: {
        int chanceOfBeingCaught = randomNumberGenerator.getRandomNumber() % (maxHP - HP);
        if (chanceOfBeingCaught < 5) {
          cout << "You've successfully slipped from enemy" << endl;
          break;
        }
        cout << "You've been caught by the enemy";
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

void Enemy::setHp(int hp) {
  HP = hp;
}

int Enemy::getMaxHp() const {
  return maxHP;
}

void Enemy::attack(Character character) const {
  RandomNumberGenerator randomNumberGenerator;
  int atkModifier = randomNumberGenerator.getRandomNumber() % modifier + 1;
  int enemyAttackValue = atk + atkModifier - character.getItems()[1].getModifier();
  if (enemyAttackValue < 0) {
    enemyAttackValue = 0;
  }
  character.setHp(character.getHp() - enemyAttackValue);
  cout << "The Enemy attacked You by " + to_string(enemyAttackValue) << endl;
}
