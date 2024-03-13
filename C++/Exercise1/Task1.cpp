#include <iostream>

using namespace std;

int main() {
    // Task 1
    float R1, R2, R3, R0;
    cout << "Enter R1: "; cin >> R1;
    cout << "Enter R2: "; cin >> R2;
    cout << "Enter R3: "; cin >> R3;
    R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);
    cout << "Result: R0 = " << R0 << endl << endl;

    // Task 2
    float L, S, R;
    cout << "Enter length: ";
    cin >> L;
    R = L / (2 * 3.14);
    S = 3.14 * R * R;
    cout << "Result: S = " << S << endl << endl;

    // Task 3
    float v, t, a, S2;
    cout << "Enter value: "; cin >> v;
    cout << "Enter time: "; cin >> t;
    cout << "Enter acceleration: "; cin >> a;
    S2 = v * t + (a * t * t) / 2;
    cout << "Result: S = " << S2 << endl;

    return 0;
}
