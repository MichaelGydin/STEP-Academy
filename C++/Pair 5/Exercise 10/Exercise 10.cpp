#include <iostream>

using namespace std;

const int SIZE = 100;

// TASK 1
void initializeMatrix(int matrix[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 101;
        }
    }
}

void printMatrix(int matrix[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void findDiagonal(int matrix[][SIZE], int size, int& minDiagonal, int& maxDiagonal) {
    minDiagonal = matrix[0][0];
    maxDiagonal = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minDiagonal) {
            minDiagonal = matrix[i][i];
        }
        if (matrix[i][i] > maxDiagonal) {
            maxDiagonal = matrix[i][i];
        }
    }
}

void sortRows(int matrix[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
}

// TASK 2
int searchDiv(int a, int b) {
    if (b == 0) {
        return a;
    }
    return searchDiv(b, a % b);
}

// TASK 3
int cows = 0, bulls = 0;
string secretNumber;

string generateSecretNumber() {
    srand(time(NULL));
    string number = "";
    while (number.length() < 4) {
        char digit = '0' + rand() % 10;
        if (number.find(digit) == string::npos) {
            number += digit;
        }
    }
    return number;
}

void checkGuess(string guess) {
    cows = 0;
    bulls = 0;
    for (int i = 0; i < 4; i++) {
        if (guess[i] == secretNumber[i]) {
            bulls++;
        }
        else if (secretNumber.find(guess[i]) != string::npos) {
            cows++;
        }
    }
}

void playGame(int attempts) {
    string guess;
    cout << "Enter your guess (4-digit number): ";
    cin >> guess;
    checkGuess(guess);
    if (bulls == 4) {
        cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
    }
    else {
        cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
        playGame(attempts + 1);
    }
}

int main() {
    srand(time(NULL));

    // TASK 1
    /*int matrix[SIZE][SIZE];
    int size;

    cout << "Enter size: ";
    cin >> size;

    initializeMatrix(matrix, size);

    cout << "Matrix:" << endl; printMatrix(matrix, size);

    int minDiagonal, maxDiagonal;
    findDiagonal(matrix, size, minDiagonal, maxDiagonal);
    cout << "Minimum element on diagonal: " << minDiagonal << endl;
    cout << "Maximum element on diagonal: " << maxDiagonal << endl;

    sortRows(matrix, size);

    cout << "Sorted matrix:" << endl; printMatrix(matrix, size); */

    // TASK 2
    /*int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = searchDiv(a, b);

    cout << "Divisor of " << a << " and " << b << " is: " << result << endl;*/

    // TASK 3
    secretNumber = generateSecretNumber();
    playGame(1);
    return 0;
}
