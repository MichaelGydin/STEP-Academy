#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Resident {
private:
    string name;
    int age;
    char gender;

public:
    Resident(string name = "", int age = 0, char gender = ' ') : name(name), age(age), gender(gender) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    char getGender() const { return gender; }

    void setName(const string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGender(char gender) { this->gender = gender; }

    friend ostream& operator<<(ostream& os, const Resident& resident) {
        os << "Name: " << resident.name << ", Age: " << resident.age << ", Gender: " << resident.gender << endl;
        return os;
    }
};

class Premises {
protected:
    int numberOfRooms;
    double area;
    string address;
    vector<Resident*> residents;

public:
    Premises(int numberOfRooms = 0, double area = 0.0, const string& address = "") : numberOfRooms(numberOfRooms), area(area), address(address) {}

    int getNumberOfRooms() const { return numberOfRooms; }
    double getArea() const { return area; }
    string getAddress() const { return address; }
    const vector<Resident*>& getResidents() const { return residents; }

    void setNumberOfRooms(int numberOfRooms) { this->numberOfRooms = numberOfRooms; }
    void setArea(double area) { this->area = area; }
    void setAddress(const string& address) { this->address = address; }

    void addResident(Resident* resident) { residents.push_back(resident); }
    void removeResident(Resident* resident) {
        for (auto it = residents.begin(); it != residents.end(); ++it) {
            if (*it == resident) {
                residents.erase(it);
                break;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const Premises& premises) {
        os << "Number of rooms: " << premises.numberOfRooms << ", Area: " << premises.area << ", Address: " << premises.address << endl;
        os << "Residents:" << endl;
        for (const auto& resident : premises.residents) {
            os << *resident;
        }
        return os;
    }
};

class Apartment : public Premises {
private:
    int entranceNumber;
    int floor;
    int apartmentNumber;

public:
    Apartment(int entranceNumber = 0, int floor = 0, int apartmentNumber = 0, int numberOfRooms = 0, double area = 0.0, const string& address = "")
        : Premises(numberOfRooms, area, address), entranceNumber(entranceNumber), floor(floor), apartmentNumber(apartmentNumber) {}

    int getEntranceNumber() const { return entranceNumber; }
    int getFloor() const { return floor; }
    int getApartmentNumber() const { return apartmentNumber; }

    void setEntranceNumber(int entranceNumber) { this->entranceNumber = entranceNumber; }
    void setFloor(int floor) { this->floor = floor; }
    void setApartmentNumber(int apartmentNumber) { this->apartmentNumber = apartmentNumber; }

    friend ostream& operator<<(ostream& os, const Apartment& apartment) {
        os << static_cast<const Premises&>(apartment);
        os << "Entrance number: " << apartment.entranceNumber << ", Floor: " << apartment.floor << ", Apartment number: " << apartment.apartmentNumber << endl;
        return os;
    }
};

class PrivateHouse : public Premises {
private:
    double yardArea;

public:
    PrivateHouse(double yardArea = 0.0, int numberOfRooms = 0, double area = 0.0, const string& address = "")
        : Premises(numberOfRooms, area, address), yardArea(yardArea) {}

    double getYardArea() const { return yardArea; }

    void setYardArea(double yardArea) { this->yardArea = yardArea; }

    friend ostream& operator<<(ostream& os, const PrivateHouse& house) {
        os << static_cast<const Premises&>(house);
        os << "Yard area: " << house.yardArea << endl;
        return os;
    }
};

class Cottage : public Premises {
private:
    int numberOfBathrooms;
    int numberOfBeds;

public:
    Cottage(int numberOfBathrooms = 0, int numberOfBeds = 0, int numberOfRooms = 0, double area = 0.0, const string& address = "")
        : Premises(numberOfRooms, area, address), numberOfBathrooms(numberOfBathrooms), numberOfBeds(numberOfBeds) {}

    int getNumberOfBathrooms() const { return numberOfBathrooms; }
    int getNumberOfBeds() const { return numberOfBeds; }

    void setNumberOfBathrooms(int numberOfBathrooms) { this->numberOfBathrooms = numberOfBathrooms; }
    void setNumberOfBeds(int numberOfBeds) { this->numberOfBeds = numberOfBeds; }

    friend ostream& operator<<(ostream& os, const Cottage& cottage) {
        os << static_cast<const Premises&>(cottage);
        os << "Number of bathrooms: " << cottage.numberOfBathrooms << ", Number of beds: " << cottage.numberOfBeds << endl;
        return os;
    }
};

class Hotel : public Premises {
private:
    int numberOfRooms;
    double priceOfMostExpensiveRoom;
    double priceOfCheapestRoom;

public:
    Hotel(int numberOfRooms = 0, double priceOfMostExpensiveRoom = 0.0, double priceOfCheapestRoom = 0.0, int numberOfRoomsBase = 0, double area = 0.0, const string& address = "")
        : Premises(numberOfRoomsBase, area, address), numberOfRooms(numberOfRooms), priceOfMostExpensiveRoom(priceOfMostExpensiveRoom), priceOfCheapestRoom(priceOfCheapestRoom) {}

    int getNumberOfRooms() const { return numberOfRooms; }
    double getPriceOfMostExpensiveRoom() const { return priceOfMostExpensiveRoom; }
    double getPriceOfCheapestRoom() const { return priceOfCheapestRoom; }

    void setNumberOfRooms(int numberOfRooms) { this->numberOfRooms = numberOfRooms; }
    void setPriceOfMostExpensiveRoom(double priceOfMostExpensiveRoom) { this->priceOfMostExpensiveRoom = priceOfMostExpensiveRoom; }
    void setPriceOfCheapestRoom(double priceOfCheapestRoom) { this->priceOfCheapestRoom = priceOfCheapestRoom; }

    friend ostream& operator<<(ostream& os, const Hotel& hotel) {
        os << static_cast<const Premises&>(hotel);
        os << "Number of rooms: " << hotel.numberOfRooms << ", Price of most expensive room: " << hotel.priceOfMostExpensiveRoom << ", Price of cheapest room: " << hotel.priceOfCheapestRoom << endl;
        return os;
    }
};

class HousingManager {
private:
    vector<Premises*> premises;

public:
    HousingManager() {}

    void addPremises(Premises* premises) { this->premises.push_back(premises); }
    void removePremises(Premises* premises) {
        for (auto it = this->premises.begin(); it != this->premises.end(); ++it) {
            if (*it == premises) {
                this->premises.erase(it);
                break;
            }
        }
    }

    void printAllPremises() const {
        for (const auto& premises : this->premises) {
            cout << *premises << endl;
        }
    }

    void printSpecificTypeOfPremises(const string& type) const {
        for (const auto& premises : this->premises) {
            if (typeid(*premises) == typeid(Apartment) && type == "Apartment") {
                cout << *premises << endl;
            }
            else if (typeid(*premises) == typeid(PrivateHouse) && type == "PrivateHouse") {
                cout << *premises << endl;
            }
            else if (typeid(*premises) == typeid(Cottage) && type == "Cottage") {
                cout << *premises << endl;
            }
            else if (typeid(*premises) == typeid(Hotel) && type == "Hotel") {
                cout << *premises << endl;
            }
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& premises : this->premises) {
                file << *premises;
            }
            file.close();
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.find("Apartment") != string::npos) {
                    int entranceNumber, floor, apartmentNumber, numberOfRooms;
                    double area;
                    string address;
                    istringstream iss(line);
                    iss >> entranceNumber >> floor >> apartmentNumber >> numberOfRooms >> area;
                    getline(iss, address);
                    Apartment* apartment = new Apartment(entranceNumber, floor, apartmentNumber, numberOfRooms, area, address);
                    premises.push_back(apartment);
                }
                else if (line.find("PrivateHouse") != string::npos) {
                    double yardArea;
                    int numberOfRooms;
                    double area;
                    string address;
                    istringstream iss(line);
                    iss >> yardArea >> numberOfRooms >> area;
                    getline(iss, address);
                    PrivateHouse* house = new PrivateHouse(yardArea, numberOfRooms, area, address);
                    premises.push_back(house);
                }
                else if (line.find("Cottage") != string::npos) {
                    int numberOfBathrooms, numberOfBeds;
                    int numberOfRooms;
                    double area;
                    string address;
                    istringstream iss(line);
                    iss >> numberOfBathrooms >> numberOfBeds >> numberOfRooms >> area;
                    getline(iss, address);
                    Cottage* cottage = new Cottage(numberOfBathrooms, numberOfBeds, numberOfRooms, area, address);
                    premises.push_back(cottage);
                }
                else if (line.find("Hotel") != string::npos) {
                    int numberOfRooms;
                    double priceOfMostExpensiveRoom, priceOfCheapestRoom;
                    int numberOfRoomsBase;
                    double area;
                    string address;
                    istringstream iss(line);
                    iss >> numberOfRooms >> priceOfMostExpensiveRoom >> priceOfCheapestRoom >> numberOfRoomsBase >> area;
                    getline(iss, address);
                    Hotel* hotel = new Hotel(numberOfRooms, priceOfMostExpensiveRoom, priceOfCheapestRoom, numberOfRoomsBase, area, address);
                    premises.push_back(hotel);
                }
            }
            file.close();
        }
    }
};

int main() {
    HousingManager manager;

    Apartment apartment(1, 2, 3, 4, 50.0, "Address 1");
    apartment.addResident(new Resident("John", 25, 'M'));
    apartment.addResident(new Resident("Jane", 30, 'F'));

    PrivateHouse house(100.0, 5, 200.0, "Address 2");
    house.addResident(new Resident("Bob", 40, 'M'));
    house.addResident(new Resident("Alice", 35, 'F'));

    Cottage cottage(2, 3, 3, 150.0, "Address 3");
    cottage.addResident(new Resident("Mike", 45, 'M'));
    cottage.addResident(new Resident("Emma", 40, 'F'));

    Hotel hotel(10, 100.0, 50.0, 5, 200.0, "Address 4");
    hotel.addResident(new Resident("Tom", 50, 'M'));
    hotel.addResident(new Resident("Lily", 45, 'F'));

    manager.addPremises(&apartment);
    manager.addPremises(&house);
    manager.addPremises(&cottage);
    manager.addPremises(&hotel);

    manager.printAllPremises();

    manager.printSpecificTypeOfPremises("Apartment");

    manager.saveToFile("premises.txt");

}