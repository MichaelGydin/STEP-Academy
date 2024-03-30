#include <iostream>

using namespace std;

template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template <typename T>
T findMin(T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template <typename T>
int binarySearch(T arr[], int size, T key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void replaceElement(T arr[], int size, int index, T value) {
    if (index >= 0 && index < size) {
        arr[index] = value;
    }
}

int main() {
    srand(time(NULL));
    const int SIZE = 30;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Max: " << findMax(arr, SIZE) << endl;
    cout << "Min: " << findMin(arr, SIZE) << endl;

    selectionSort(arr, SIZE);
    cout << "Sorted array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key = 10;
    int index = binarySearch(arr, SIZE, key);
    if (index != -1) {
        cout << "Found at index " << index << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    replaceElement(arr, SIZE, 3, 99);
    cout << "After replacement: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
