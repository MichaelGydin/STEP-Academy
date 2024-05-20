#include <iostream>
using namespace std;

const int MAX_CARS = 10;

struct CarNumber {
    union {
        int number;
        char word[9];
    };
    bool isNumber;
};

struct Car {
    string color;
    string model;
    CarNumber number;
};

void fillCar(Car& car) {
    cout << "Enter car color: "; cin >> car.color;
    cout << "Enter car model: "; cin >> car.model;

    cout << "Enter car number (1 for integer, 2 for word): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        car.number.isNumber = true;
        cout << "Enter 5-digit number: ";
        cin >> car.number.number;
    }
    else if (choice == 2) {
        car.number.isNumber = false;
        cout << "Enter word (up to 8 characters): ";
        cin >> car.number.word;
    }
    else {
        cout << "Invalid choice! Setting default number to 0." << endl;
        car.number.isNumber = true;
        car.number.number = 0;
    }
}

void printCar(const Car& car) {
    cout << "Color: " << car.color << ", Model: " << car.model << ", Number: ";
    if (car.number.isNumber) {
        cout << car.number.number;
    }
    else {
        cout << car.number.word;
    }
    cout << endl;
}

void editCar(Car& car) {
    fillCar(car);
}

void printAllCars(const Car cars[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". ";
        printCar(cars[i]);
    }
}

void searchCarByNumber(const Car cars[], int size, const CarNumber& number) {
    for (int i = 0; i < size; ++i) {
        if ((number.isNumber && cars[i].number.isNumber && cars[i].number.number == number.number) ||
            (!number.isNumber && !cars[i].number.isNumber && strcmp(cars[i].number.word, number.word) == 0)) {
            cout << "Found car at index " << i + 1 << ": ";
            printCar(cars[i]);
            return;
        }
    }
    cout << "Car with the specified number not found." << endl;
}

int main() {
    Car cars[MAX_CARS];
    int choice;
    while (true) {
        cout << "\nCar Menu:\n";
        cout << "1. Fill a car\n";
        cout << "2. Print all cars\n";
        cout << "3. Edit a car\n";
        cout << "4. Search car by number\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter the index of the car to fill (0-9): ";
            cin >> index;
            if (index >= 0 && index < MAX_CARS) {
                fillCar(cars[index]);
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 2:
            printAllCars(cars, MAX_CARS);
            break;
        case 3: {
            int index;
            cout << "Enter the index of the car to edit (0-9): ";
            cin >> index;
            if (index >= 0 && index < MAX_CARS) {
                editCar(cars[index]);
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 4: {
            cout << "Enter the type of number to search (1 for integer, 2 for word): ";
            int choice;
            cin >> choice;
            CarNumber searchNumber;
            if (choice == 1) {
                searchNumber.isNumber = true;
                cout << "Enter 5-digit number: ";
                cin >> searchNumber.number;
            }
            else if (choice == 2) {
                searchNumber.isNumber = false;
                cout << "Enter word (up to 8 characters): ";
                cin >> searchNumber.word;
            }
            else {
                cout << "Invalid choice!" << endl;
                break;
            }
            searchCarByNumber(cars, MAX_CARS, searchNumber);
            break;
        }
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
