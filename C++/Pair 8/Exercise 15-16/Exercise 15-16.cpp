#include <iostream>
#include <cstring>
using namespace std;

// task 1
void deleteChar1(char* str, int pos) {
    int len = strlen(str);
    if (pos >= 0 && pos < len) {
        for (int i = pos; i < len - 1; i++) {
            str[i] = str[i + 1];
        }
        str[len - 1] = ' ';
    }
}

// task 2
void deleteChar2(char* str, char ch) {
    int len = strlen(str), shift = 0;
    for (int i = 0; i < len - shift; i++) {
        if (str[i] == ch) {
            shift++;
            for (int j = i; j < len - shift; j++) {
                str[j] = str[j + 1];
            } i--;
        }
    }
}
// task 3
void insertChar(char* str, char ch, int pos) {
    int len = strlen(str);
    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    } str[pos] = ch;
}



// task 4
void replaceDots(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}

// task 5
int count(char* str, char ch) {
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ch) {
            count++;
        }
    } return count;
}

int main() {
    char str[] = "Hello, world!";

    // task 1
    cout << "Original string: " << str << endl;
    deleteChar1(str, 7);
    cout << "String after deletion: " << str << endl << endl;

    // task 2
    cout << "Original string: " << str << endl;
    deleteChar2(str, 'l');
    cout << "String after deletion: " << str << endl << endl;

    // task 3
    cout << "Original string: " << str << endl;
    insertChar(str, 'X', 7);
    cout << "String after insertion: " << str << endl << endl;

    // task 4
    char strFinal[100]; cout << "Enter string: "; fgets(strFinal, sizeof(strFinal), stdin);
    replaceDots(strFinal);
    cout << "Modified string: " << strFinal << endl;

    // task 5
    char ch; cout << "Enter a character to count: "; cin >> ch;
    int occurrences = count(strFinal, ch);
    cout << "Character '" << ch << "' occurs " << occurrences << " times in the string." << endl << endl;

    // task 6
    int letters = 0, digits = 0, others = 0;
    for (int i = 0; strFinal[i]; i++) {
        if ((strFinal[i] >= 'a' && strFinal[i] <= 'z') || (strFinal[i] >= 'A' && strFinal[i] <= 'Z')) {
            letters++;
        }
        else if (strFinal[i] >= '0' && strFinal[i] <= '9') {
            digits++;
        }
        else {
            others++;
        }
    }

    cout << "Number of letters: " << letters << endl;
    cout << "Number of digits: " << digits << endl;
    cout << "Number of other characters: " << others << endl;

    return 0;

    // я не знаю чому але код не показує "нажміть любу клавішу щоб закрити консоль" вона просто завісає і все. (навіть чатGBT не поміг)
}
