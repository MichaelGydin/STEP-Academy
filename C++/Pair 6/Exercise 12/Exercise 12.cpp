#include <iostream>
#define SIZE 5
using namespace std;

// task 1
void copyArray(int* source, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        *(dest + i) = *(source + i);
    }
}

// task 2
void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

// task 3
void reverseCopyArray(int* source, int* dest, int size) {
    int* srcp = source + size - 1;
    int* destp = dest;

    for (int i = 0; i < size; i++) {
        *destp = *srcp;
        srcp--;
        destp++;
    }
}

int main() 
{
    // task 1
    int arr1[SIZE] = { 1, 2, 3, 4, 5 }; int arr2[SIZE];
    int* psrc = arr1; int* pdest = arr2;

    copyArray(psrc, pdest, SIZE);

    cout << "Copied array:";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << arr2[i];
    } cout << endl << endl;

    // task 2
    int arr[SIZE] = { 1, 2, 3, 4, 5 };

    cout << "Original array:";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << arr[i];
    } cout << endl;

    reverseArray(arr, SIZE);

    cout << "Reversed array:";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << arr[i];
    } cout << endl << endl;

    // task 3
    int sourceArray[SIZE] = { 1, 2, 3, 4, 5 }; int destArray[SIZE];

    cout << "Source array:";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << sourceArray[i];
    } cout << endl;

    reverseCopyArray(sourceArray, destArray, SIZE);

    cout << "Reversed copy array:";
    for (int i = 0; i < SIZE; i++) {
        cout << " " << destArray[i];
    } cout << endl;
}
