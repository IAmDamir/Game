//
// Created by Damir on 9/8/2021.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "Characters/Character.h"
#include "Characters/Swordsman.h"

#include "Enemy.h"
using namespace std;

#ifndef GAME_GAME_H
#define GAME_GAME_H

class Game {
public:
  Game();
  virtual ~Game();

  void mainMenu();
  bool isPlaying() const;
  void setPlaying(bool);

private:
  int choice;
  bool playing;

  void playMenu(Character&);
  void characterSelectMenu();

  static void explore(Character&);
  static void showStats(Character&);
  static void restoreHP(Character&, int);

  static void saveCharacter(Character&);
  static bool loadCharacter(Character&);
};


#endif //GAME_GAME_H
