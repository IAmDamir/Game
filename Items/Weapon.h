//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "Item.h"

class Weapon : public Item {
public:
  Weapon(int);
  ~Weapon() override;
};


#endif //GAME_WEAPON_H
