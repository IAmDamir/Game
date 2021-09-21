//
// Created by Damir on 9/8/2021.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "Characters/Swordsman.h"

#include "Enemy.h"
using namespace std;

#ifndef GAME_GAME_H
#define GAME_GAME_H
// A class that executes both main and playing menus and executes all choices that player can make in them
class Game {
public:
  Game();
  virtual ~Game();

  // A main menu where player can start, load or quit the game
  // calls loadCharacter() and playMenu() or characterSelectMenu() functions
  void mainMenu();
  [[nodiscard]] bool isPlaying() const;

  [[maybe_unused]] void setPlaying(bool);

private:
  // Player's choice in the both menus
  int choice;
  // Using this boolean we can quit the game from main menu when player wants to quit
  bool playing;

  // A menu where player can choose one from number of characters to start the game
  // Creates a Character class and initializes with a class that was chosen by player
  // Calls playMenu() function after execution
  void characterSelectMenu();
  // A game itself
  // Calls explore(), showStats(), restoreHP, or saveCharacter() functions
  void playMenu(Character&);

  // In this function player can encounter an enemy or go to the empty room
  // Empty room will give player some exp and return to the playMenu()
  // if player encounters an enemy, the Enemy class will be created and Enemy.encounter() function will be executed
  // if players lvl > 9, creates an Enemy called Boss. Boss is stronger than regular enemy. executes Enemy.encounter()
  // when the Boss is defeated, Players HP is set 0
  // if player's hp falls below 1, Player is forced to move to mainMenu without saving a character
  // TODO some motivation for winning the game e.g. leaderboards, in-game rewards etc.
  static void explore(Character&);
  // Shows stats of a current character
  static void showStats(Character&);
  // Restores half of character's maxHP
  static void restoreHP(Character&, int);

  // Saves current character's stats and items in character.txt file
  static void saveCharacter(Character&);
  // Loads a character from character.txt file
  // Checks if file is filled and exits, if not says to player that character hasn't been saved
  // TODO check if data in character.txt is corrupted
  static bool loadCharacter(Character&);
};


#endif //GAME_GAME_H
