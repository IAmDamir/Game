//
// Created by Damir on 9/18/2021.
//

#pragma once
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "Characters/Character.h"

using namespace std;

// An enemy, attacks a player if encountered
class Enemy {
public:
  explicit Enemy(int, string);
  ~Enemy();

  // Starts a battle between player and enemy
  // Player can attack or try to escape
  // Player's escape chances increases as much as player damaged an enemy
  // No matter what player chooses enemy will attack him if not defeated
  // TODO make more interactions with enemy
  // TODO usable character specific skills on attack
  void encounter(Character&);

  [[nodiscard]] int getMaxHp() const;

  [[nodiscard]] int getHp() const;

  [[nodiscard]] int getAtk() const;

  [[nodiscard]] int getModifier() const;

  // Drops a random item with random Item.modifier between 1 and Enemy.modifier
  Item getItem() const;

private:
  string name;
  int maxHP;
  int HP;
  int atk;
  int modifier;

  // Attacks a character by random amount between 1 and modifier
  // TODO balance an enemy's attack depending on character's level
  void attack(Character&) const;
};


#endif //GAME_ENEMY_H
