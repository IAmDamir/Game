//
// Created by Damir on 9/8/2021.
//

#include "Game.h"

Game::Game() {
  choice = 0;
  playing = true;
}

Game::~Game() {

}

void Game::mainMenu() {
  std::cout << "Main Menu" << std::endl << std::endl;
  std::cout << "1: Start" << std::endl;
  std::cout << "0: Quit" << std::endl;

  std::cout << std::endl << "Choice: ";

  std::cin >> choice;
  switch (choice) {
    case 0: playing = false;
      break;
    case 1: ;
    default: break;
  }
}

bool Game::isPlaying() const {
  return playing;
}

void Game::setPlaying(bool playing) {
  Game::playing = playing;
}
