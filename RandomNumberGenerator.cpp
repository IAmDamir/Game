//
// Created by Damir on 9/18/2021.
//

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() {
  // sets a seed for a random number generator
  // seed is equal to current time
  srand(time(nullptr));
}

RandomNumberGenerator::~RandomNumberGenerator() {

}
// Returns random a pseudo number
int RandomNumberGenerator::getRandomNumber() {
  return rand();
}
