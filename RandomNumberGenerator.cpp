//
// Created by Damir on 9/18/2021.
//

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() {
  srand(time(0));
}

RandomNumberGenerator::~RandomNumberGenerator() {

}

int RandomNumberGenerator::getRandomNumber() {
  return rand();
}
