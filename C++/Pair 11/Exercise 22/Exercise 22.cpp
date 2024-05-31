#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Abonent {
    char* name;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

    void copyString(char*& dest, const char* src) {
        int length = 0;
        while (src[length] != '\0') {
            ++length;
        }
        dest = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            dest[i] = src[i];
        }
        dest[length] = '\0';
    }

public:
    Abonent() : name(nullptr), homePhone(""), workPhone(""), mobilePhone(""), additionalInfo("") {}

    Abonent(const char* n, const string& home, const string& work, const string& mobile, const string& info) {
        copyString(name, n);
        homePhone = home;
        workPhone = work;
        mobilePhone = mobile;
        additionalInfo = info;
    }

    Abonent(const Abonent& other) {
        copyString(name, other.name);
        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        additionalInfo = other.additionalInfo;
    }

    Abonent& operator=(const Abonent& other) {
        if (this == &other) {
            return *this;
        }
        delete[] name;
        copyString(name, other.name);
        homePhone = other.homePhone;
        workPhone = other.workPhone;
        mobilePhone = other.mobilePhone;
        additionalInfo = other.additionalInfo;
        return *this;
    }

    ~Abonent() {
        delete[] name;
    }

    void input() {
        char tempName[100];
        cout << "Enter name: "; cin.ignore(); cin.getline(tempName, 100);
        copyString(name, tempName);
        cout << "Enter home phone: "; getline(cin, homePhone);
        cout << "Enter work phone: "; getline(cin, workPhone);
        cout << "Enter mobile phone: "; getline(cin, mobilePhone);
        cout << "Enter additional info: "; getline(cin, additionalInfo);
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Additional Info: " << additionalInfo << endl;
    }

    const char* getName() const {
        return name;
    }

    void writeFile(ofstream& fout) const {
        fout << name << '\n' << homePhone << '\n' << workPhone << '\n' << mobilePhone << '\n' << additionalInfo << '\n';
    }

    void readFile(ifstream& fin) {
        char tempName[100];
        fin.getline(tempName, 100);
        copyString(name, tempName);
        getline(fin, homePhone);
        getline(fin, workPhone);
        getline(fin, mobilePhone);
        getline(fin, additionalInfo);
    }
};

class PhoneBook {
    Abonent* abonents;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        Abonent* newAbonents = new Abonent[capacity];
        for (int i = 0; i < size; ++i) {
            newAbonents[i] = abonents[i];
        }
        delete[] abonents;
        abonents = newAbonents;
    }

public:
    PhoneBook() : size(0), capacity(10) {
        abonents = new Abonent[capacity];
    }

    ~PhoneBook() {
        delete[] abonents;
    }

    void addAbonent() {
        if (size == capacity) {
            resize();
        }
        abonents[size].input();
        ++size;
    }

    void deleteAbonent(const char* name) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(abonents[i].getName(), name) == 0) {
                for (int j = i; j < size - 1; ++j) {
                    abonents[j] = abonents[j + 1];
                }
                --size;
                cout << "Abonent " << name << " deleted.\n" << endl;
                return;
            }
        }
        cout << "Abonent " << name << " not found.\n" << endl;
    }

    void searchAbonent(const char* name) const {
        for (int i = 0; i < size; ++i) {
            if (strcmp(abonents[i].getName(), name) == 0) {
                abonents[i].display();
                return;
            }
        }
        cout << "Abonent " << name << " not found.\n" << endl;
    }

    void showAll() const {
        for (int i = 0; i < size; ++i) {
            abonents[i].display();
            cout << "--------------------" << endl;
        }
    }

    void saveToFile(const string& path) const {
        ofstream fout(path);
        if (!fout.is_open()) {
            cerr << "Error opening file\n" << endl;
            return;
        }
        fout << size << endl;
        for (int i = 0; i < size; ++i) {
            abonents[i].writeFile(fout);
        }
        fout.close();
    }

    void loadFromFile(const string& path) {
        ifstream fin(path);
        if (!fin.is_open()) {
            cerr << "Error opening file\n" << endl;
            return;
        }
        fin >> size;
        fin.ignore();
        delete[] abonents;
        abonents = new Abonent[size];
        for (int i = 0; i < size; ++i) {
            abonents[i].readFile(fin);
        }
        fin.close();
    }
};

void output() {
    PhoneBook phoneBook;
    int choice;
    string filePath = "phonebook.txt";
    string input;
    do {
        cout << "1. Add abonent\n2. Delete abonent\n3. Search abonent\n4. Show all abonents\n5. Save to File\n6. Load from File\n0. Exit\n\nEnter your choice: "; cin >> choice; cout << endl;

        switch (choice) {
        case 1:
            phoneBook.addAbonent(); cout << endl; break;
        case 2:
            cout << "Enter name of abonent to delete: "; getline(cin, input); phoneBook.deleteAbonent(input.c_str()); cout << endl; break;
        case 3:
            cout << "Enter name of abonent to search: ";
            cin.ignore(); getline(cin, input); // ???????? cin.ignore(); ???????????????? ??? ??????????? ??????? ?????? ????? ?? ????????? ? ??????
            phoneBook.searchAbonent(input.c_str()); cout << endl; break;
        case 4:
            phoneBook.showAll(); cout << endl; break;
        case 5:
            phoneBook.saveToFile(filePath); cout << "Saved!\n" << endl; break;
        case 6:
            phoneBook.loadFromFile(filePath); cout << "Loaded!\n" << endl; break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

int main() {
    output();
}