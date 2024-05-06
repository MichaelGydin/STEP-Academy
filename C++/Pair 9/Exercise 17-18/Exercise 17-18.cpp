#include <iostream>
using namespace std;

void printArray(int arr[2][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void shiftRight(int arr[2][5], int rows, int cols, int numShifts) {
    for (int i = 0; i < numShifts; i++) {
        for (int j = 0; j < rows; j++) {
            int temp = arr[j][cols - 1];
            for (int k = cols - 1; k > 0; k--) {
                arr[j][k] = arr[j][k - 1];
            }
            arr[j][0] = temp;
        }
    }
}

int main() {
    // task 1
    /*int n;
    cout << "Enter number: ";
    cin >> n;

    int arr[5][5];
    arr[0][0] = n;

    for (int i = 1; i < 5; i++) {
        arr[0][i] = arr[0][i - 1] * 2;
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = arr[i - 1][j] * 2;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/

    // task 2
    /*int n;
    cout << "Enter a number: ";
    cin >> n;

    int arr[5][5];
    arr[0][0] = n;

    for (int i = 1; i < 5; i++) {
        arr[0][i] = arr[0][i - 1] + 1;
    }

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = arr[i - 1][j] + 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/

    // task 3
    srand(time(0));
    int rows = 2;
    int cols = 5;
    int arr[2][5];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "Before:" << endl;
    printArray(arr, rows, cols);
    cout << endl;

    int numShifts; cout << "Enter number of moves: "; cin >> numShifts; cout << endl;
    shiftRight(arr, rows, cols, numShifts);

    cout << "After:" << endl; printArray(arr, rows, cols);

}
