#include <iostream>

using namespace std;

int* allocateMemory(int size) {
    return new int[size];
}

void initializeArray(int* arr, int size) {
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    cout << "Array elements:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int* addElement(int* arr, int& size, int element) {
    int newSize = size + 1;
    int* newArr = new int[newSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    size = newSize;
    delete[] arr;
    return newArr;
}

int* insertElement(int* arr, int& size, int index, int element) {
    int newSize = size + 1;
    int* newArr = new int[newSize];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = element;
    for (int i = index + 1; i < newSize; i++) {
        newArr[i] = arr[i - 1];
    }
    size = newSize;
    delete[] arr;
    return newArr;
}

int* removeElement(int* arr, int& size, int index) {
    int newSize = size - 1;
    int* newArr = new int[newSize];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index; i < newSize; i++) {
        newArr[i] = arr[i + 1];
    }
    size = newSize;
    delete[] arr;
    return newArr;
}

int main() {
    int M, N;
    cout << "Enter size A(M): "; cin >> M;
    cout << "Enter size B(N): "; cin >> N; cout << endl;

    int* A = allocateMemory(M);
    int* B = allocateMemory(N);

    initializeArray(A, M);
    initializeArray(B, N);

    cout << endl << "Array A: " << endl; printArray(A, M); cout << endl;
    cout << "Array B: " << endl; printArray(B, N);

    deleteArray(A);
    deleteArray(B);
}
