#include <iostream>
using namespace std;

const int N = 8;
bool visited[N][N] = { false };
int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]);
}

bool solve(int x, int y, int moveCount) {
    visited[x][y] = true;
    if (moveCount == N * N - 1) {
        cout << endl << "Way:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << visited[i][j] << " ";
            } cout << endl;
        } return true;
    }

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY)) {
            if (solve(newX, newY, moveCount + 1)) {
                return true;
            }
        }
    } visited[x][y] = false; return false;
}

int main() {
    int startX, startY;
    cout << "Enter starting position (x): "; cin >> startX;
    cout << "Enter starting position (y): "; cin >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "Invalid position\n";
        return 1;
    } solve(startX, startY, 0);
}
