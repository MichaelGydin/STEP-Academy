#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string make, string model, int year)
        : make{ make }, model{ model }, year{ year } {}

    virtual void displayInfo() const {
        cout << "Make: " << make << "\nModel: " << model << "\nYear: " << year << endl;
    }

    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }
};

class Engine {
protected:
    int horsepower;
    double displacement;

public:
    Engine(int horsepower, double displacement)
        : horsepower{ horsepower }, displacement{ displacement } {}

    int getHorsepower() const {
        return horsepower;
    }

    double getDisplacement() const {
        return displacement;
    }
};

class Car : public Vehicle, public Engine {
private:
    int numberOfDoors;

public:
    Car(string make, string model, int year, int horsepower, double displacement, int numberOfDoors)
        : Vehicle(make, model, year), Engine(horsepower, displacement), numberOfDoors{ numberOfDoors } {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Horsepower: " << getHorsepower() << "\nDisplacement: " << getDisplacement()
            << "\nNumber of Doors: " << numberOfDoors << endl;
    }

    int getNumberOfDoors() const {
        return numberOfDoors;
    }
};

class Truck : public Vehicle, public Engine {
private:
    double loadCapacity;

public:
    Truck(string make, string model, int year, int horsepower, double displacement, double loadCapacity)
        : Vehicle(make, model, year), Engine(horsepower, displacement), loadCapacity{ loadCapacity } {}

    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Horsepower: " << getHorsepower() << "\nDisplacement: " << getDisplacement()
            << "\nLoad Capacity: " << loadCapacity << " tons" << endl;
    }

    double getLoadCapacity() const {
        return loadCapacity;
    }
};

int main() {
    Car car("Toyota", "Camry", 2023, 203, 2.5, 4);
    Truck truck("Ford", "F-150", 2022, 290, 5.0, 1.5);

    cout << "Car Info:" << endl;
    car.displayInfo();
    cout << endl;

    cout << "Truck Info:" << endl;
    truck.displayInfo();
}
