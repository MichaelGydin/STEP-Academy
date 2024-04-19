#include <iostream>

using namespace std;

void distributeElements(int* arr, int size, int*& positive, int& positiveSize, int*& negative, int& negativeSize, int*& zero, int& zeroSize) {
    positiveSize = 0;
    negativeSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveSize++;
        }
        else if (arr[i] < 0) {
            negativeSize++;
        }
        else {
            zeroSize++;
        }
    }

    positive = new int[positiveSize];
    negative = new int[negativeSize];
    zero = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive[posIndex++] = arr[i];
        }
        else if (arr[i] < 0) {
            negative[negIndex++] = arr[i];
        }
        else {
            zero[zeroIndex++] = arr[i];
        }
    }
}

int main() {
    int arr[] = { 1, -2, 3, -4, 0, 5, -6, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* positive = nullptr;
    int positiveSize = 0;
    int* negative = nullptr;
    int negativeSize = 0;
    int* zero = nullptr;
    int zeroSize = 0;

    distributeElements(arr, size, positive, positiveSize, negative, negativeSize, zero, zeroSize);

    cout << "Positive elements:";
    for (int i = 0; i < positiveSize; i++) {
        cout << " " << positive[i];
    } cout << endl;

    cout << "Negative elements:";
    for (int i = 0; i < negativeSize; i++) {
        cout << " " << negative[i];
    } cout << endl;

    cout << "Zero elements:";
    for (int i = 0; i < zeroSize; i++) {
        cout << " " << zero[i];
    } cout << endl;

    delete[] positive;
    delete[] negative;
    delete[] zero;
}