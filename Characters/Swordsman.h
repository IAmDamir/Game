//
// Created by Damir on 9/18/2021.
//

#pragma once

#ifndef GAME_SWORDSMAN_H
#define GAME_SWORDSMAN_H

#include <string>
#include "Character.h"

// A subclass of Character
class Swordsman : public Character {
public:
  // Sets stats that is made for this character
  // TODO balance the starting stats for this class
  Swordsman();
};
#endif //GAME_SWORDSMAN_H
