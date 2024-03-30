#include <iostream>

using namespace std;

void fillArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101 - 50;;
    }
}

void Show(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// task 1
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;
    while (day1 != day2 || month1 != month2 || year1 != year2) {
        days++;
        day1++;
        if (day1 > daysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
    }
    return days;
}

// task 2
double average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

// task 3
void countElements(int arr[], int size, int& positive, int& negative, int& zero) {
    positive = 0;
    negative = 0;
    zero = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive++;
        }
        else if (arr[i] < 0) {
            negative++;
        }
        else {
            zero++;
        }
    }
}

int main()
{
	srand(time(NULL));
	const int SIZE = 25;
	int arr1[SIZE];

	// task 1
    int day1, month1, year1, day2, month2, year2;
    cout << "Enter the first date (day): "; cin >> day1;
    cout << "Enter the first date (month): "; cin >> month1;
    cout << "Enter the first date (year): "; cin >> year1; cout << endl;

    cout << "Enter the second date (day): "; cin >> day2;
    cout << "Enter the second date (month): "; cin >> month2;
    cout << "Enter the second date (year): "; cin >> year2; cout << endl;

    int days = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    cout << "The difference in days between the two dates is: " << days << endl << endl;

    // task 2
    int arr2[SIZE];
    fillArr(arr2, SIZE);
    double avg = average(arr2, SIZE);
    cout << "Array: "; Show(arr2, SIZE); cout << endl;
    cout << "Average: " << avg << endl << endl;


    // task 3
    int arr3[SIZE] = { 3, -2, 0, 5, -1, 0, -4 };
    int positive, negative, zero;
    fillArr(arr3, SIZE);
    countElements(arr3, SIZE, positive, negative, zero);

    cout << "Array: "; Show(arr3, SIZE); cout << endl;
    cout << "Positive elements: " << positive << endl;
    cout << "Negative elements: " << negative << endl;
    cout << "Zero elements: " << zero << endl;
}

