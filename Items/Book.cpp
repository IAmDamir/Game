//
// Created by Damir on 9/18/2021.
//

#include "Book.h"

Book::Book(int modifier) {
  name = "Book";
  RandomNumberGenerator randomNumberGenerator;
  this->modifier = (randomNumberGenerator.getRandomNumber() % (3 + modifier/4) + 2);
  description = "gives you +" + to_string(this->modifier - 1) + "00% exp";
}

Book::~Book() = default;