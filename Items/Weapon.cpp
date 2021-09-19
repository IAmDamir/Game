//
// Created by Damir on 9/18/2021.
//

#include "Weapon.h"

Weapon::Weapon(int modifier) {
  name = "Weapon";
  RandomNumberGenerator randomNumberGenerator;
  this->modifier = randomNumberGenerator.getRandomNumber() % (3 + modifier) + 1;
  description = "gives you +" + to_string(this->modifier) + " ATK";
}

Weapon::~Weapon() = default;