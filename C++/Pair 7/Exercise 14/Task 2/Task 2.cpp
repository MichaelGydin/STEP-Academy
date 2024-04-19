#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    } return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            count++;
        }
    }

    int* newArr = new int[count];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[index] = arr[i];
            index++;
        }
    }

    newSize = count;
    return newArr;
}

int main() {
    int size = 5;
    int arr[] = { 1, 2, 3, 4, 5 };

    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    int newSize;
    int* newArr = removePrimes(arr, size, newSize);

    cout << "New array without primes: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArr[i] << " ";
    } cout << endl;

    delete[] newArr;
}
