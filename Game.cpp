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
      // Proceeds to select a character
      characterSelectMenu();
      break;
    }
    case 2: {
      Character character;
      // Checks a character.txt file and creates a new character from the data in the file
      if (loadCharacter(character)) {
        // Starts a game
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

  // TODO a number of different characters
  switch (choice) {
    case 1: {
      // Initializes a class of a character
      character = Swordsman();
      break;
    }
    default: {
      return;
    }
  }

  // Sets a name for the character
  while (character.getName().empty()) {
    cout << "Enter the name: ";
    string tempName;
    cin >> tempName;

    // Checks if name contains only alphanumeric symbols
    // If not, it would be hard to load a character
    if (find_if(tempName.begin(), tempName.end(),
                [](char c) { return !(isalnum(c)); }) == tempName.end()) {
      character.setName(tempName);
    } else {
      cout << "Character name should contain only alphanumeric symbols" << endl;
    }
  }
  // Starts a game
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
        // Explores a new room
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
        // Saves a data of a current character to character.txt file (stats, items)
        saveCharacter(character);
      }
      default:
        break;
    }
    // Returns to mainMenu if character's HP falls below 0
    if (character.getHp() <= 0) {
      cout << "Game over" << endl;
      break;
    }
  }
}

void Game::explore(Character &character) {
  // Forces a boss fight
  if (character.getLevel() > 9) {
    // Creates an enemy called Boss
    // TODO create a class Boss with different mechanics to make Boss fight special
    Enemy boss(character.getLevel() + 5, "Boss");
    // Starts a fight between Player and Boss
    boss.encounter(character);

    if (boss.getHp() <= 0) {
      // The reward for defeating a Boss
      cout << "Congrats, You've won the game" << endl;
      // Forces to end the game
      character.setHp(0);
    }
  } else {
    RandomNumberGenerator randomNumberGenerator;
    int randNum = randomNumberGenerator.getRandomNumber() % 10 + 1;

    // Randomly defines will the room be empty or with an enemy
    // Currently chances are 80% to encounter
    // TODO fill a rooms with different things
    if (randNum < 3) {
      character.gainExp(20);
      cout << "You've walked into empty room" << endl;
    } else {
      // Creates an enemy called Enemy
      Enemy enemy(character.getLevel(), "Enemy");
      // Starts a fight
      enemy.encounter(character);
      // If enemy is defeated congratulates a player gives him an exp and item
      if (enemy.getHp() <= 0) {
        cout << "Congrats, You've defeated the Enemy" << endl;
        // Character equips dropped item if it is better than current one
        character.equipItem(enemy.getItem());
        // If enemy's lvl is higher than 4 gives twice less exp
        // TODO balance an exp gain in different levels
        int enemyLvl = enemy.getModifier();
        int exp = enemyLvl > 4? 20*enemyLvl: 10*enemyLvl;
        character.gainExp(exp);
      }
    }
  }
}

// Shows character's stats and items
void Game::showStats(Character &character){
  cout << character.getStats() << endl;
}

// Restores an n amount of HP
void Game::restoreHP(Character &character, int amount) {
  cout << "restored " + to_string(amount) + " HP" << endl;
  character.setHp(character.getHp() + amount);
}

bool Game::isPlaying() const{
  return playing;
}

[[maybe_unused]] void Game::setPlaying(bool playing) {
  Game::playing = playing;
}

// Saves character to character.txt via overloaded output operator in Character and Item classes
void Game::saveCharacter(Character &character) {
  ofstream saver("character.txt");
  saver << character;
  saver.close();
}

// Loads a character from character.txt
bool Game::loadCharacter(Character &character) {
  // Checks if the file exists
  if (filesystem::exists("character.txt")) {
    // Creates a file reader
    ifstream loader("character.txt", ios_base::in | ios_base::binary);

    // Checks if file is empty
    // If empty fills a character with data via overloaded input operator
    bool isEmpty = (filesystem::file_size("character.txt") == 0);
    if (loader.is_open() && !isEmpty) {
      loader >> character;
      loader.close();
      return true;
    } else {
      cout << "A character hasn't been saved" << endl;
      return false;
    }
  } else {
    cout << "File doesn't exist" << endl;
    return false;
  }
}
