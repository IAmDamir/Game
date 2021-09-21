//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_ARMOR_H
#define GAME_ARMOR_H

#include "Item.h"

// Subclass of item class, absorbs the damage taken
class Armor : public Item {
public:
  explicit Armor(int);
  ~Armor() override;
};

#endif //GAME_ARMOR_H
