#include <iostream>
#include <fstream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            cout << "cannot be zero setting to 1" << endl;
            denominator = 1;
        }
        simplify();
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "cannot be zero setting to 1" << endl;
            denominator = 1;
        }
        simplify();
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "cannot divide by zero" << endl;
            return Fraction(0, 1);
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file) {
            file << numerator << " " << denominator;
            file.close();
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file) {
            file >> numerator >> denominator;
            file.close();
        }
        if (denominator == 0) {
            cout << "cannot be zero setting to 1" << endl;
            denominator = 1;
        }
        simplify();
    }
};

int main() {
    Fraction frac1, frac2;
    frac1.input();
    frac2.input();

    cout << "Fraction 1: ";
    frac1.print();
    cout << "Fraction 2: ";
    frac2.print();

    Fraction sum = frac1 + frac2;
    cout << "Sum: ";
    sum.print();

    Fraction diff = frac1 - frac2;
    cout << "Difference: ";
    diff.print();

    Fraction prod = frac1 * frac2;
    cout << "Product: ";
    prod.print();

    Fraction quot = frac1 / frac2;
    cout << "Quotient: ";
    quot.print();

    frac1.saveToFile("fraction.txt");
    Fraction fracFromFile;
    fracFromFile.loadFromFile("fraction.txt");
    cout << "loaded: ";
    fracFromFile.print();
}