#include "Game.h"



int main() {
  // Initializing a game
  Game game;
  while (game.isPlaying()) {
    // Starts a game
    game.mainMenu();
  }

  return 0;
}
