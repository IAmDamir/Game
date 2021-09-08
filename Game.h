//
// Created by Damir on 9/8/2021.
//
#include <iostream>

#pragma once
#ifndef GAME_GAME_H
#define GAME_GAME_H


class Game {
public:
  Game();
  virtual ~Game();
  void mainMenu();

private:
  int choice;
  bool playing;
public:
  [[nodiscard]] bool isPlaying() const;

  void setPlaying(bool playing);
};


#endif //GAME_GAME_H
