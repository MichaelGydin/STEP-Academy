#include <iostream>

using namespace std;

int main()
{
    /*// Цикли for:
    // Вивести на екран числа від 1 до 10.
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    // Просумувати числа від 1 до 100 і вивести результат.
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    cout << "Sum from 1 to 100: " << sum << endl;

    // Вивести парні числа від 2 до 20.
    for (int i = 2; i <= 20; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    // Вивести таблицю множення для введеного користувачем числа.
    int num;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 1; i <= 10; i++) {
        cout << num << " * " << i << " = " << num * i << endl;
    }

    // Знайти суму квадратів чисел від 1 до 5.
    sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += i * i;
    }
    cout << "Sum of squares from 1 to 5: " << sum << endl;

    // Вивести факторіал введеного користувачем числа.
    int fact = 1;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    cout << "Factorial of " << num << ": " << fact << endl;

    // Визначити, чи є введене число простим.
    bool Prime = true;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            Prime = false;
            break;
        }
    }
    if (Prime && num > 1) {
        cout << num << " is a prime number." << endl;
    }
    else {
        cout << num << " is not a prime number." << endl;
    }

    // Вивести числа від 10 до 1 у зворотному порядку.
    for (int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;

    // Визначити суму перших 10 чисел Фібоначчі.
    int n1 = 0, n2 = 1, nextTerm;
    sum = 0;
    for (int i = 1; i <= 10; ++i) {
        sum += n1;
        nextTerm = n1 + n2;
        n1 = n2;
        n2 = nextTerm;
    }
    cout << "Sum of first 10 Fibonacci numbers: " << sum << endl;

    // Вивести кожну літеру слова за допомогою циклу for.
    string word = "Hello";
    int i = 0;
    while (word[i] != '\0') {
        cout << word[i] << " ";
        i++;
    }
    cout << endl;

    // Вивести на екран кожну парну букву слова "HELLO".
    i = 0;
    while (word[i] != '\0') {
        cout << word[i] << " ";
        i += 2;
    }
    cout << endl;

    // Вивести всі прості числа від 10 до 50.
    for (int i = 10; i <= 50; i++) {
        Prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                Prime = false;
                break;
            }
        }
        if (Prime) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Вивести на екран зірочки у вигляді прямокутника (5x5).
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // Реалізувати виведення чисел у пірамідальній формі (піраміда зі зірочок).
    int rows;
    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    } */
    
    /* // Цикли while:
    // Питати користувача про пароль, продовжувати запитувати, доки він не введе правильний пароль.
    string password = "secret";
    string input;
    while (true) {
        cout << "Enter the password: ";
        cin >> input;
        if (input == password) {
            cout << "Access granted!" << endl;
            break;
        }
        else {
            cout << "Access denied. Try again." << endl;
        }
    }

    // Знайти суму парних чисел від 1 до 50 за допомогою циклу while.
    int sum = 0;
    int i = 2;
    while (i <= 50) {
        sum += i;
        i += 2;
    }
    cout << "Sum of even numbers from 1 to 50: " << sum << endl;

    // Визначити кількість цифр у введеному користувачем числі.
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    cout << "Number of digits: " << count << endl;

    // Вивести всі дільники введеного користувачем числа.
    cout << "Enter a number: ";
    cin >> number;
    cout << "Divisors of " << number << ": ";
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Зчитувати числа від користувача, доки він не введе 0, і вивести їх суму.
    sum = 0;
    while (true) {
        cout << "Enter a number (0 to stop): ";
        cin >> number;
        if (number == 0) {
            break;
        }
        sum += number;
    }
    cout << "Sum of numbers: " << sum << endl;

    // Визначити, чи є введене користувачем число паліндромом.
    cout << "Enter a number: ";
    cin >> number;
    int originalNumber = number;
    int reversedNumber = 0;
    while (number != 0) {
        int remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }
    if (originalNumber == reversedNumber) {
        cout << "Palindrome!" << endl;
    }
    else {
        cout << "Not a palindrome." << endl;
    }

    // Обчислити середнє арифметичне чисел, введених користувачем, доки він не введе від'ємне число.
    sum = 0;
    int numCount = 0;
    while (true) {
        cout << "Enter a number (negative number to stop): ";
        cin >> number;
        if (number < 0) {
            break;
        }
        sum += number;
        numCount++;
    }
    if (numCount > 0) {
        cout << "Average: " << 1.0 * sum / numCount << endl;
    }
    else {
        cout << "No numbers entered." << endl;
    }

    // Реалізувати гру "вгадай число" за допомогою циклу while.
    int secretNumber = 42;
    int guess;
    cout << "Guess the number (1-100): ";
    while (true) {
        cin >> guess;
        if (guess < secretNumber) {
            cout << "Too low. Try again: ";
        }
        else if (guess > secretNumber) {
            cout << "Too high. Try again: ";
        }
        else {
            cout << "Correct! The number was " << secretNumber << endl;
            break;
        }
    }

    // Знайти суму факторіалів чисел від 1 до 10.
    sum = 0;
    int factorial = 1;
    i = 1;
    while (i <= 10) {
        factorial *= i;
        sum += factorial;
        i++;
    }
    cout << "Sum of factorials from 1 to 10: " << sum << endl;

    // Вивести кожну цифру введеного користувачем числа у зворотньому порядку.
    cout << "Enter a number: ";
    cin >> number;
    cout << "Digits in reverse order: ";
    while (number != 0) {
        int digit = number % 10;
        cout << digit << " ";
        number /= 10;
    }
    cout << endl; */
    
    /* // Цикли do-while (15%):
    // Питати користувача про введення числа, доки він не введе парне число.
    int number;
    do {
        cout << "Enter an even number: ";
        cin >> number;
    } while (number % 2 != 0);

    // Знайти суму непарних чисел від 1 до 25 за допомогою циклу do-while.
    int sum = 0;
    int i = 1;
    do {
        if (i % 2 != 0) {
            sum += i;
        }
        i++;
    } while (i <= 25);
    cout << "Sum of odd numbers from 1 to 25: " << sum << endl;

    // Вивести таблицю множення для введеного користувачем числа за допомогою циклу do-while.
    cout << "Enter a number: ";
    cin >> number;
    i = 1;
    do {
        cout << number << " * " << i << " = " << number * i << endl;
        i++;
    } while (i <= 10);

    // Питати користувача про введення пароля, доки він не введе правильний пароль.
    string password = "secret";
    string input;
    do {
        cout << "Enter the password: ";
        cin >> input;
    } while (input != password);

    // Вивести числа Фібоначчі до n за допомогою циклу do-while, де n - введене користувачем число.
    cout << "Enter a number: ";
    cin >> number;
    int a = 0, b = 1, nextTerm;
    cout << "Fibonacci Series up to " << number << ": ";
    do {
        cout << a << " ";
        nextTerm = a + b;
        a = b;
        b = nextTerm;
    } while (a <= number); */
}