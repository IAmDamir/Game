//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_RANDOMNUMBERGENERATOR_H
#define GAME_RANDOMNUMBERGENERATOR_H

#include <random>
#include <ctime>


class RandomNumberGenerator {
public:
  RandomNumberGenerator();
  ~RandomNumberGenerator();
  int getRandomNumber();
};


#endif //GAME_RANDOMNUMBERGENERATOR_H
