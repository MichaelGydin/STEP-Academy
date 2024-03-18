#include <iostream>

using namespace std;

int main() {
    /*// Завдання 1
    char symbol;
    int length, speed, orientation;

    cout << "Enter symbol: ";
    cin >> symbol;

    cout << "Enter length: ";
    cin >> length;

    cout << "Choose speed (0 - slow, 1 - normal, 2 - fast): ";
    cin >> speed;

    cout << "Choose orientation (0 - horizontal, 1 - vertical): ";
    cin >> orientation;

    if (orientation == 0) {
        for (int i = 0; i < length; ++i) {
            cout << symbol;
            for (int j = 0; j < (speed == 0 ? 500000 : (speed == 1 ? 100000 : 10000)); ++j) {}
        }
        cout << endl;
    }
    else if (orientation == 1) {
        for (int i = 0; i < length; ++i) {
            cout << symbol << endl;
            for (int j = 0; j < (speed == 0 ? 500000 : (speed == 1 ? 100000 : 10000)); ++j) {}
        }
    }
    else {
        cout << "Invalid choice." << endl;
    } */

    // Завдання 2
    srand(time(0));

    int playerScore = 0, computerScore = 0;

    cout << "The game 'Dice'!\n";
    cout << "The player and the computer take turns rolling the dice.\n";
    cout << "The winner is the one who has the highest score after 3 throws.\n\n";

    for (int i = 0; i < 3; ++i) {
        cout << "Round " << i + 1 << ":\n";

        cout << "The player rolls the dice...\n";
        int playerRoll1 = rand() % 6 + 1;
        int playerRoll2 = rand() % 6 + 1;
        int playerTotal = playerRoll1 + playerRoll2;
        cout << "The player threw " << playerRoll1 << " and " << playerRoll2 << " (sum: " << playerTotal << ")\n";
        playerScore += playerTotal;

        cout << "The computer rolls the dice...\n";
        int computerRoll1 = rand() % 6 + 1;
        int computerRoll2 = rand() % 6 + 1;
        int computerTotal = computerRoll1 + computerRoll2;
        cout << "The computer threw " << computerRoll1 << " and " << computerRoll2 << " (sum: " << computerTotal << ")\n";
        computerScore += computerTotal;

        cout << endl;
    }

    cout << "Result:\n";
    cout << "Player: " << playerScore << ", Computer: " << computerScore << endl;

    if (playerScore > computerScore)
        cout << "The player has won!\n";
    else if (computerScore > playerScore)
        cout << "The computer has won!\n";
    else
        cout << "A draw!\n";
}
