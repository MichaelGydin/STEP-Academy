#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    /*// Завдання 1
    const int SIZE = 10; int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    cout << "Array: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    } cout << endl;

    int minElement = arr[0], maxElement = arr[0];

    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    cout << "The minimum element: " << minElement << endl;
    cout << "Maximum element: " << maxElement << endl << endl; 

    // Завдання 2
    const int MONTHS = 12; int profits[MONTHS];

    for (int i = 0; i < MONTHS; ++i) {
        cout << "Enter profit for month " << i + 1 << ": "; cin >> profits[i];
    }

    int startMonth, endMonth;
    cout << endl << "Enter start month of the range: "; cin >> startMonth;
    cout << "Enter end month of the range: "; cin >> endMonth; cout << endl;
    

    int maxProfit = profits[startMonth - 1], minProfit = profits[startMonth - 1];
    int maxMonth = startMonth, minMonth = startMonth;

    for (int i = startMonth; i <= endMonth; ++i) {
        if (profits[i - 1] > maxProfit) {
            maxProfit = profits[i - 1];
            maxMonth = i;
        }
        if (profits[i - 1] < minProfit) {
            minProfit = profits[i - 1];
            minMonth = i;
        }
    }
    cout << "The maximum profit was in month " << maxMonth << ": " << maxProfit << endl;
    cout << "The minimum profit was in month " << minMonth << ": " << minProfit << endl; 

    // Завдання 3
    const int N = 10; double arr[N];

    cout << "Enter " << N << " real numbers:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    double sumNegative = 0, productMinMax = 1, productEvenIndexes = 1, sumBetweenFirstLastNegative = 0;
    int firstNegativeIndex = -1, lastNegativeIndex = -1;
    for (int i = 0; i < N; ++i) {
        if (arr[i] < 0) {
            sumNegative += arr[i];
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            lastNegativeIndex = i;
        }
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            productMinMax *= arr[i];
        }
    }

    for (int i = 0; i < N; i += 2) {
        productEvenIndexes *= arr[i];
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; ++i) {
            sumBetweenFirstLastNegative += arr[i];
        }
    }

    cout << "Sum of negative elements: " << sumNegative << endl;
    cout << "Product of elements between first and last negative elements: " << productMinMax << endl;
    cout << "Product of elements with even indexes: " << productEvenIndexes << endl;
    cout << "Sum of elements between first and last negative elements: " << sumBetweenFirstLastNegative << endl; */
}