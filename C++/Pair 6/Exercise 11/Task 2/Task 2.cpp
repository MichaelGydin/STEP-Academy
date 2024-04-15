#include <iostream>
#include <iomanip>
#define SIZE 4
int board[SIZE][SIZE];

using namespace std;

void initialize() {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = num++;
        }
    } board[SIZE - 1][SIZE - 1] = 0;
}

void shuffle() {
    srand(time(0));
    for (int i = 0; i < SIZE * SIZE * SIZE; i++) {
        int dir = rand() % 4;
        int dx[] = { 0, 0, 1, -1 };
        int dy[] = { 1, -1, 0, 0 };
        int x, y;
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (board[j][k] == 0) {
                    x = j; y = k;
                    break;
                }
            }
        }
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            board[x][y] = board[nx][ny];
            board[nx][ny] = 0;
        }
    }
}

void print() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) cout << setw(3) << ".";
            else cout << setw(3) << board[i][j];
        } cout << endl;
    } cout << endl;
}

bool isSolved() {
    int num = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != num++ && num != SIZE * SIZE) {
                return false;
            }
        }
    } return true;
}

bool move(int num) {
    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };
    int x, y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                x = i; y = j;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == num) {
            board[x][y] = num;
            board[nx][ny] = 0;
            return true;
        }
    } return false;
}

int main() {
    initialize();
    shuffle();
    print();

    while (!isSolved()) {
        int num; cout << "Enter number (1-15): "; cin >> num;
        if (num < 1 || num > 15) {
            cout << "Invalid input\n";
            continue;
        }
        if (!move(num)) {
            cout << "Invalid move\n";
            continue;
        } print();
        if (isSolved()) {
            cout << "You won!\n"; // я не знаю чому воно не працює :(
            break;
        }
    } return 0;
}