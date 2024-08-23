#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    char* str;
    size_t length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy_s(str, length + 1, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;

        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
        return *this;
    }

    size_t Length() const {
        return length;
    }

    void Clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    virtual ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        strcpy_s(newStr, length + 1, str);
        strcat_s(newStr, newLength + 1, other.str);

        String result;
        result.length = newLength;
        result.str = newStr;
        return result;
    }

    String& operator+=(const String& other) {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];
        strcpy_s(newStr, length + 1, str);
        strcat_s(newStr, newLength + 1, other.str);

        delete[] str;
        str = newStr;
        length = newLength;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const String& s) {
        if (s.str) {
            os << s.str;
        } return os;
    }

    const char* GetStr() const {
        return str;
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) {
        bool isValid = true;
        for (size_t i = 0; i < strlen(s); i++) {
            if (s[i] != '0' && s[i] != '1') {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            length = strlen(s);
            str = new char[length + 1];
            strcpy_s(str, length + 1, s);
        }
        else {
            str = nullptr;
            length = 0;
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        if (this == &other) return *this;
        String::operator=(other);
        return *this;
    }

    void Invert() {
        if (!str) return;
        for (size_t i = 0; i < length; i++) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }

        for (size_t i = length - 1; i >= 0; i--) {
            if (str[i] == '0') {
                str[i] = '1';
                break;
            }
            else {
                str[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        String result = String::operator+(other);
        return BitString(result.GetStr());
    }

    BitString& operator+=(const BitString& other) {
        String::operator+=(other);
        return *this;
    }

    bool operator==(const BitString& other) const { return String::operator==(other); }
    bool operator!=(const BitString& other) const { return String::operator!=(other); }
};

int main() {
    BitString b1("1010");
    BitString b2("0101");

    cout << "BitString 1: " << b1 << endl;
    cout << "BitString 2: " << b2 << endl;

    BitString b3 = b1 + b2;
    cout << "Concatenated BitString: " << b3 << endl;

    b1.Invert();
    cout << "Inverted BitString 1: " << b1 << endl;

    bool isEqual = b1 == b2;
    cout << "BitString 1 == BitString 2: " << (isEqual ? "True" : "False") << endl;
}