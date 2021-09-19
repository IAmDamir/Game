//
// Created by Damir on 9/18/2021.
//

#include "Armor.h"

Armor::Armor(int modifier) {
  name = "Armor";
  RandomNumberGenerator randomNumberGenerator;
  this->modifier = randomNumberGenerator.getRandomNumber() % (3 + modifier/2) + 1;
  description = "gives you -" + to_string(this->modifier) + " of received ATK";
}

Armor::~Armor() = default;
