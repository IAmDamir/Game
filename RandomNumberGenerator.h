//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_RANDOMNUMBERGENERATOR_H
#define GAME_RANDOMNUMBERGENERATOR_H

#include <random>
#include <ctime>

// Class to generate a pseudo random numbers
class RandomNumberGenerator {
public:
  RandomNumberGenerator();
  ~RandomNumberGenerator();
  // Returns random a pseudo number
  // TODO set a smaller name for a method and a class since RandomNumberGenerator.getRandomNumber() is too large
  int getRandomNumber();
};


#endif //GAME_RANDOMNUMBERGENERATOR_H
