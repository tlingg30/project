#include <cstdlib>
#include <fstream>
#include <string>

#include "Machine.h"
#include "abyssGame.h"
using namespace std;
string Machine::monster_type;
int Machine::game_level;
int main() {
  int total_line = 0;
  string temporary;
  ifstream check("game_saved.txt");
  if (!check.is_open()) {
    std::cout << "No saved game found." << std::endl;
    exit(1);
  }
  while (!check.eof()) {
    getline(check, temporary);
    total_line++;
  }
  check.clear();
  check.seekg(0, ios::beg);
  check.close();
  string option_holder;
  int option;
  // Display game title
  const char* filename = "theAbyssArt.txt";

  // Use the system function to run the cat command.
  string command = "cat " + string(filename);

  // Show the game interface when user first load the game. They have 2 options
  while (true) {
#ifdef _WIN32
    // Windows
    system("cls");
#else
    // Linux, Unix, macOS
    system("clear");
#endif
    system(command.c_str());
    cout << endl;
    cout << "     "
         << "1. [New game]" << endl;
    cout << "     "
         << "2. [Load game]" << endl;
    // Exceptional handling when user either enter string or unexpected integer
    while (true) {
      cin >> option_holder;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      try {
        option = stoi(option_holder);
      } catch (std::invalid_argument const& e) {
        cout << "Please enter a valid intege" << endl;
        continue;
      }
      if (cin.fail() || (option != 1 && option != 2)) {
        cout << "Please enter number 1 or 2" << endl;
        cin.clear();
        cin.ignore();
      } else if (option == 1 || option == 2) {
        break;
      }
    }

// show game title after click new or load game
#ifdef _WIN32
    // Windows
    system("cls");
#else
    // Linux, Unix, macOS
    system("clear");
#endif
    system(command.c_str());
    char option2;
    if (option == 2) {
      if (total_line <= 1) {
        cout << "no saved game" << endl;
        cout << "Type N to exit" << endl;
        cin >> option2;
        if (option2 == 'N') {
          exit(0);
        }
      }
      break;
    }
    char option1;
    if (total_line >= 7) {
      cout << "Max database capacity reach. If you play a new game, all of "
              "the "
              "existing games will be deleted!"
           << endl;
      cout << "Y/N" << endl;
      cin >> option1;
      if (option1 == 'Y') {
        ofstream save_file("game_saved.txt");
        save_file << 0 << endl;
        break;
      }
    } else if (total_line <= 6) {
      break;
    }
  }
  // Create game object
  abyssGame game;
  // When the player choose to play a new game. They will be greeted by
  // new_game() function and then be walked through tutorial ie. play
  // against the first level machine monster
  if (option == 1) {
    game.new_game();
    sleep(3);
#ifdef _WIN32
    // Windows
    system("cls");
#else
    // Linux, Unix, macOS
    system("clear");
#endif
    system(command.c_str());
    game.go_battle();
    // After the end of tutorial, the player comes back to user menu which
    // have 3 options
    while (true) {
      int option = game.game_menu();
      if (option == 1) {
        game.go_battle();
      } else if (option == 2) {
        game.level_up();
      } else if (option == 3) {
        game.save_game();
        exit(0);
      }
    }
    // if the player choose to load an existing game
  } else if (option == 2) {
    game = game.load_game();  // Load the game and assign it to the existing
                              // game object

    // continue the game
    while (true) {
      int option = game.game_menu();

      if (option == 1) {
        game.go_battle();
      } else if (option == 2) {
        game.level_up();
      } else if (option == 3) {
        game.save_game();
        exit(0);
      }
    }
  }

  return 0;
}