//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "Item.h"

// Subclass of item class, adds an extra value to character's attacks
class Weapon : public Item {
public:
  // Randomly generates modifier value for this item
  explicit Weapon(int);
  ~Weapon() override;
};


#endif //GAME_WEAPON_H
