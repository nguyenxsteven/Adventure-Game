#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
private:
    string name;
    int gold;
    int difficulty;

public:
    Player() {
        name = "";
        gold = 0;
        difficulty = 1;
    }

    void setName(string playerName) {
        name = playerName;
    }

    void setDifficulty(int gameDifficulty) {
        difficulty = gameDifficulty;
    }

    void addGold(int chestGold) {
        gold += chestGold;
    }

    void subtractGold(int stolenGold) {
        int randomLoss = rand() % stolenGold + 1;
        gold -= randomLoss;
    }


    void addDiamond() {
        gold += 500;
    }

    string getName() {
        return name;
    }

    int getDifficulty() {
        return difficulty;
    }

    int getGold() {
        return gold;
    }
};


int generateGold() {
    int gold = rand() % 151 + 50;
    return gold;
}


void displayGold(Player player) {
    cout << "You currently have " << player.getGold() << " gold coins.\n";
}

int main() {
    srand(time(NULL)); 

    Player player;
    string direction;

    cout << "Welcome to the Treasure Hunt!\n";
    cout << "You find yourself in a forest.\n";
    cout << "There are three paths in front of you.\n";

    string name;
    cout << "What is your name hunter?? ";
    getline(cin, name);
    player.setName(name);
    cout << "Welcome " << player.getName() << "!\n";

    int difficulty;
    cout << "Choose a difficulty level (1 = Easy, 2 = Medium, 3 = Hard): ";
    cin >> difficulty;
    player.setDifficulty(difficulty);
    cout << "You have chosen difficulty level " << player.getDifficulty() << ". Good luck!\n";

    // Game loop
    while (true) {
        cout << "Which direction do you want to go? (left/right/straight/quit): ";
        cin >> direction;

        if (direction == "left") {
            int chestGold = generateGold();
            cout << "You find a treasure chest full of " << chestGold << " gold coins!\n";
            player.addGold(chestGold);
        }
        else if (direction == "right") {
            // Determine amount of gold stolen based on difficulty level
            int stolenGold = 0;
            if (player.getDifficulty() == 1) {
                stolenGold = rand() % 26 + 25; // 25-50 gold coins
            }
            else if (player.getDifficulty() == 2) {
                stolenGold = rand() % 51 + 50; // 50-100 gold coins
            }
            else {
                stolenGold = rand() % 76 + 75; // 75-150 gold coins
            }

            cout << "You stumble upon a group of bandits!\n";
            cout << "They steal " << stolenGold << " gold coins from you.\n";
            player.subtractGold(stolenGold);
        }
        else if (direction == "straight") {
            cout << "You come across a river and see a shiny object on the other side.\n";
            cout << "Do you want to swim across to get it? (yes/no): ";
            cin >> direction;

            if (direction == "yes") {
                cout << "You find a diamond ring! It's worth 500 gold coins.\n";
                player.addGold(500);
            }
            else {
                cout << "You decide not to risk it and continue on your journey.\n";
            }
        }
        else if (direction == "quit") {
            // End the game if the player chooses to quit
            cout << "Thanks for playing!\n";
            break;
        }
        else {
            // Handle invalid input
            cout << "Invalid input. Please choose a valid direction.\n";
        }

        displayGold(player);
    }

    return 0;
}
