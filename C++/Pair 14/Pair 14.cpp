#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    int size;
    static int objectCount;

public:
    String() : String(80) {
    }

    String(int size) {
        this->size = size;
        str = new char[size + 1];
        str[0] = '\0';
        objectCount++;
    }

    String(const char* inputStr) : String(strlen(inputStr)) {
        strcpy_s(str, size + 1, inputStr);
    }

    ~String() {
        delete[] str;
        objectCount--;
    }

    void input() {
        cout << "Enter string: ";
        cin.getline(str, size + 1);
    }

    void print() const {
        cout << str << endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {
    String str1;
    str1.input();
    str1.print();
    cout << "Object count: " << String::getObjectCount() << endl;

    String str2(100);
    str2.input();
    str2.print();
    cout << "Object count: " << String::getObjectCount() << endl;

    String str3("Hello, World!");
    str3.print();
    cout << "Object count: " << String::getObjectCount() << endl;
}