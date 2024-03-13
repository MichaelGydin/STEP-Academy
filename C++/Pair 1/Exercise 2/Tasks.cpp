#include <iostream>
using namespace std;

int main() {
    int choice; cout << "Enter 1(Task 1) or 2(Task 2): "; cin >> choice;

    if (choice == 1) {
        // Task 1
        float R1, R2, R3, R0;
        cout << "\nEnter R1: "; cin >> R1;
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
    else if (choice == 2) {
        // Task 1
        int sec;
        cout << "\nEnter seconds: "; cin >> sec;
        int hour = sec / 3600;
        int min = (sec % 3600) / 60;
        int remainS = sec % 60;
        cout << "Time: " << hour << " hours, " << min << " minutes, " << remainS << " seconds" << endl << endl;

        // Task 2
        float amount;
        cout << "Enter amount: "; cin >> amount;
        int dollars = amount;
        int cents = (amount - dollars) * 100;
        cout << "Money format: " << dollars << " dollars, " << cents << " cents" << endl << endl;

        // Task 3
        float distance, time;
        cout << "Enter meters: "; cin >> distance;
        cout << "Enter time (min.sec): "; cin >> time;
        float speed = distance / (time / 60);
        cout << "\nDistance: " << distance << " m" << endl;
        cout << "Time: " << (int)time << " min " << (time - (int)time) * 60 << " sec" << endl;
        cout << "Speed: " << speed << " km/h" << endl << endl;

        // Task 4
        int days;
        cout << "Enter days: "; cin >> days;
        int weeks = days / 7;
        int remainDay = days % 7;
        cout << "Weeks: " << weeks << ", Days: " << remainDay << endl;

        return 0;
    }
    else {
        cout << "Error: Invalid input." << endl;
    }

    return 0;
}