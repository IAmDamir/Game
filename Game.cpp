#include "Game.h"

Game::Game() {
  choice = 0;
  playing = true;
}

Game::~Game() {

}

void Game::mainMenu() {
  cout << "Main Menu" << endl << endl;
  cout << "1: Start" << endl;
  cout << "2: Load" << endl;
  cout << "0: Quit" << endl;

  cout<<endl<<"Choice: ";
  cin>>choice;
  switch (choice) {
    case 0: playing = false;
      break;
    case 1: {
      characterSelectMenu();
      break;
    }
    case 2: {
      Character character;
      if (loadCharacter(character)) {
        playMenu(character);
      }
      break;
    }
    default: break;
  }
}

void Game::characterSelectMenu() {
  cout << "Character select" << endl << endl;
  cout << "1: Swordsman" << endl;
  cout << "0: Back" << endl;

  cout<<endl<<"Choice: ";
  cin>>choice;
  Character character;

  switch (choice) {
    case 1: {
      character = SwordsmanChar();
      break;
    }
    default: {
      return;
    }
  }

  while (character.getName().empty()) {
    cout << "Enter the name: ";
    string tempName;
    cin >> tempName;

    if (find_if(tempName.begin(), tempName.end(),
                [](char c) { return !(isalnum(c)); }) == tempName.end()) {
      character.setName(tempName);
    } else {
      cout << "Character name should contain only alphanumeric symbols" << endl;
    }
  }
  playMenu(character);
}

void Game::playMenu(Character &character) {
  while (choice!=0) {
    cout << "Play Menu" << endl << endl;
    cout << "1: Explore" << endl;
    cout << "2: Show stats" << endl;
    cout << "3: Rest" << endl;
    cout << "4: Save" << endl;
    cout << "0: Go back" << endl;

    cout << endl << "Choice: ";
    cin >> choice;
    switch (choice) {
      case 0: break;
      case 1: {
        explore(character);
        break;
      }
      case 2: {
        // Shows stats of a hero
        showStats((character));
        break;
      }
      case 3: {
        // Restores half of HP
        restoreHP((character), character.getMaxHp() / 2);
        break;
      }
      case 4: {
        saveCharacter(character);
      }
      default:
        break;
    }

    if (character.getHp() <= 0) {
      cout << "Game over" << endl;
      break;
    }
  }
}

void Game::explore(Character &character) {
  if (character.getLevel() > 9) {

  } else {
    RandomNumberGenerator randomNumberGenerator;
    int randNum = randomNumberGenerator.getRandomNumber() % 10;

    if (randNum < 3) {
      character.gainExp(20);
      cout << "You've walked into empty room" << endl;
    } else {
      Enemy enemy(character.getLevel());
      enemy.encounter(character);
    }
  }
}

void Game::showStats(Character &character){
  cout << character.getStats() << endl;
}

void Game::restoreHP(Character &character, int amount) {
  cout << "restored " + to_string(amount) + " HP" << endl;
  character.setHp(character.getHp() + amount);
}

bool Game::isPlaying() const{
  return playing;
}

void Game::setPlaying(bool playing) {
  Game::playing = playing;
}

void Game::saveCharacter(Character &character) {
  ofstream saver("character.txt");
  saver << character;
  saver.close();
}

bool Game::loadCharacter(Character &character) {
  if (filesystem::exists("character.txt")) {
    ifstream loader("character.txt", ios_base::in | ios_base::binary);
    bool isEmpty = (filesystem::file_size("character.txt") == 0);
    if (loader.is_open() && !isEmpty) {
      loader >> character;
      loader.close();
      return true;
    } else {
      cout << "Load failed" << endl;
      return false;
    }
  } else {
    cout << "File doesn't exist" << endl;
    return false;
  }
}
