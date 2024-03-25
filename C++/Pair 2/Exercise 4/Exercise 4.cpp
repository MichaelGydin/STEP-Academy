#include <iostream>

using namespace std;

int main()
{   /* // Розділ 1
    // Завдання 1
    int a, sum = 0; cout << "Enter number: "; cin >> a;

    for (int i = a; i <= 500; i++) {
        sum += i;
    } cout << "Sum of integers from " << a << " to 500: " << sum << endl;

    // Завдання 2
    int x, y;
    cout << "Enter x: "; cin >> x;
    cout << "Enter y: "; cin >> y;

    int result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    } cout << x << " raised to the power of " << y << " is: " << result << endl;

    // Завдання 3
    int sum = 0, count = 0, avg = sum / count;

    for (int i = 1; i <= 1000; i++) {
        sum += i;
        count++;
    } cout << "Average 1 to 1000: " << avg << endl;

    // Завдання 4
    int a; cout << "Enter number (1 < a < 20): "; cin >> a;

    if (a < 1 || a > 20) {
        cout << "Invalid input." << endl;
        return 1;
    }

    int product = 1;
    for (int i = a; i <= 20; i++) {
        product *= i;
    } cout << "Product of numbers from " << a << " to 20: " << product << endl;

    // Завдання 5
    int k; cout << "Enter number: "; cin >> k;

    cout << "Multiplication table for " << k << ":" << endl;
    for (int i = 2; i <= 10; i++) {
        cout << k << " x " << i << " = " << k * i << endl;
    } */

    /* // Розділ 2
    // Завдання 1
    int count = 0;
    for (int i = 100; i < 1000; i++) {
        int hundreds = i / 100;
        int tens = (i / 10) % 10;
        int units = i % 10;
        if (hundreds == tens || hundreds == units || tens == units) {
            count++;
        }
    } cout << "Number of integers with two identical digits: " << count << endl;

    // Завдання 2
    int count = 0;
    for (int i = 100; i < 1000; i++) {
        int hundreds = i / 100;
        int tens = (i / 10) % 10;
        int units = i % 10;
        if (hundreds != tens && hundreds != units && tens != units) {
            count++;
        }
    } cout << "Number of integers with all different digits: " << count << endl;

    // Завдання 3
    int number, result = 0, multiplier = 1; cout << "Enter an integer: "; cin >> number;

    while (number != 0) {
        int digit = number % 10;
        if (digit != 3 && digit != 6) {
            result += digit * multiplier;
            multiplier *= 10;
        }
        number /= 10;
    } cout << "Number after removing digits 3 and 6: " << result << endl;

    // Завдання 4
    int a; cout << "Enter A: "; cin >> a;

    cout << "Integers B for which A divides B^2 but not B^3: ";
    for (int b = 1; b <= a; b++) {
        if (a % (b * b) == 0 && a % (b * b * b) != 0) {
            cout << b << " ";
        }
    } cout << endl;

    // Завдання 5
    int a, sum = 0, temp = a; cout << "Enter an integer A: "; cin >> a;

    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    if (sum * sum * sum == a * a) {
        cout << "The cube of the sum of the digits is equal to A*A." << endl;
    }
    else {
        cout << "The cube of the sum of the digits is not equal to A*A." << endl;
    }

    // Завдання 6
    int number; cout << "Enter an integer: "; cin >> number;

    cout << "Integers that " << number << " is divisible by without remainder: ";
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            cout << i << " ";
        }
    } cout << endl;

    // Завдання 7
    int number1, number2;
    cout << "Enter the first integer: "; cin >> number1;
    cout << "Enter the second integer: "; cin >> number2;

    int maxNumber = (number1 > number2) ? number1 : number2;

    cout << "Integers that both " << number1 << " and " << number2 << " are divisible by without remainder: ";
    for (int i = 1; i <= maxNumber; i++) {
        if (number1 % i == 0 && number2 % i == 0) {
            cout << i << " ";
        }
    } cout << endl << endl; */
}