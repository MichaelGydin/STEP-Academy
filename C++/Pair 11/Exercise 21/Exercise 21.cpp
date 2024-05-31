#include <iostream>

using namespace std;

class Drib {
    int numerator;
    int denominator;

    int findNCD(int a, int b) { // NCD - N: найбільший; C: спільний; D: дільник
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int ncd = findNCD(numerator, denominator);
        numerator /= ncd;
        denominator /= ncd;
    }

public:
    Drib() : numerator(0), denominator(1) {}
    Drib(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
        reduce();
    }

    void input() {
        cout << "Enter numerator: "; cin >> numerator;
        cout << "Enter denominator: "; cin >> denominator;
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
        reduce();
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }

    Drib add(const Drib& other) const {
        int num = numerator * other.denominator + other.numerator * denominator; // other - представляє інше число цьго класу з яким виконуються дробові операції (Вигляд в множенні: a/b * o.a/o.b = a*o.a/b*o.b)
        int den = denominator * other.denominator;
        return Drib(num, den);
    }

    Drib subtract(const Drib& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Drib(num, den);
    }

    Drib multiply(const Drib& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Drib(num, den);
    }

    Drib divide(const Drib& other) const {
        if (other.numerator == 0) {
            cout << "Division by zero." << endl;
            return Drib(numerator, denominator);
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Drib(num, den);
    }
};

void output() {
    Drib d1, d2;
    cout << "Enter first drib:" << endl; d1.input(); cout << endl;
    cout << "Enter second drib:" << endl; d2.input(); cout << endl;

    cout << "First drib: "; d1.display();
    cout << "Second drib: "; d2.display();

    Drib result;
    result = d1.add(d2); cout << "Addition: "; result.display();
    result = d1.subtract(d2); cout << "Subtraction: "; result.display();
    result = d1.multiply(d2); cout << "Multiplication: "; result.display();
    result = d1.divide(d2); cout << "Division: "; result.display();
}

int main() {
    output();
}