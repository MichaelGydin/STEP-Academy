#include <iostream>
#include <iomanip>
#define SIZE 8
using namespace std;

int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

bool isValid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

bool solve(int x, int y, int movei, int sol[SIZE][SIZE]) {
    if (movei == SIZE * SIZE) return true;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isValid(nx, ny) && sol[nx][ny] == -1) {
            sol[nx][ny] = movei;
            if (solve(nx, ny, movei + 1, sol)) return true;
            else sol[nx][ny] = -1;
        }
    }
    return false;
}

void print(int sol[SIZE][SIZE]) {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            cout << setw(3) << sol[x][y] << " ";
        }
        cout << endl;
    }
}

void tour() {
    int sol[SIZE][SIZE];
    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++) sol[x][y] = -1;


    int x, y;
    cout << "Enter the starting position (x): "; cin >> x;
    cout << "Enter the starting position (y): "; cin >> y;
    sol[x][y] = 0;

    if (solve(x, y, 1, sol)) print(sol);
    else cout << "No solution exists\n";
}

int main() {
    tour();
}
