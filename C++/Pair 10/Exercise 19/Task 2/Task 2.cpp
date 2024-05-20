#include <iostream>
using namespace std;

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string transmissionType;

    void setValues(double len, double clr, double engVol, double engPow, double whlDia, string colr, string transType) {
        length = len;
        clearance = clr;
        engineVolume = engVol;
        enginePower = engPow;
        wheelDiameter = whlDia;
        color = colr;
        transmissionType = transType;
    }

    void display() const {
        cout << "Length: " << length << " meters" << endl;
        cout << "Clearance: " << clearance << " meters" << endl;
        cout << "Engine Volume: " << engineVolume << " liters" << endl;
        cout << "Engine Power: " << enginePower << " hp" << endl;
        cout << "Wheel Diameter: " << wheelDiameter << " inches" << endl;
        cout << "Color: " << color << endl;
        cout << "Transmission Type: " << transmissionType << endl;
    }

    bool search(double len, double clr, double engVol, double engPow, double whlDia, string colr, string transType) const {
        return (length == len && clearance == clr && engineVolume == engVol &&
            enginePower == engPow && wheelDiameter == whlDia && color == colr &&
            transmissionType == transType);
    }
};

int main() {
    Car myCar;

    myCar.setValues(4.5, 0.2, 2.0, 250, 18, "Red", "Automatic");
    myCar.display();

    if (myCar.search(4.5, 0.2, 2.0, 250, 18, "Red", "Automatic")) {
        cout << "Car found!" << endl;
    }
    else {
        cout << "Car not found." << endl;
    }
}
