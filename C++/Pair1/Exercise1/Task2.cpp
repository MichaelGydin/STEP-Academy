#include <iostream>
using namespace std;

int main() {
    // Task 1
    int sec;
    cout << "Enter seconds: "; cin >> sec;
    int hour = sec / 3600;
    int min = (sec % 3600) / 60;
    int remainS = sec % 60;
    cout << "Time: " << hour << " hours, " << min << " minutes, " << remainS << " seconds" << endl;

    // Task 2
    float amount;
    cout << "Enter amount: "; cin >> amount;
    int dollars = amount;
    int cents = (amount - dollars) * 100;
    cout << "Money format: " << dollars << " dollars, " << cents << " cents" << endl;

    // Task 3
    float distance, time;
    cout << "Enter meters: "; cin >> distance;
    cout << "Enter time (min.sec): "; cin >> time;
    float speed = distance / (time / 60);
    cout << "Distance: " << distance << " m" << endl;
    cout << "Time: " << (int)time << " min " << (time - (int)time) * 60 << " sec" << endl;
    cout << "Speed: " << speed << " km/h" << endl;

    // Task 4
    int days;
    cout << "Enter days: "; cin >> days;
    int weeks = days / 7;
    int remainDay = days % 7;
    cout << "Weeks: " << weeks << ", Days: " << remainDay << endl;

    return 0;
}