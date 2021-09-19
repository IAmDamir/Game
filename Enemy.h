//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Characters/Character.h"

using namespace std;

class Enemy {
public:
  explicit Enemy(int);
  ~Enemy();

  void encounter(Character&);

  void attack(Character) const;

  int getMaxHp() const;

  int getHp() const;

  void setHp(int hp);

  int getAtk() const;

  int getModifier() const;

  Item getItem();

private:
  int maxHP;
  int HP;
  int atk;
  int modifier;
};


#endif //GAME_ENEMY_H
