#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Student {
    string name; // ім'я студента
    int id; // ідентифікаційний номер студента
    int age; // вік студента
    string major; // спеціальність студента

public:
    // Конструктор з параметрами для ініціалізації всіх полів
    Student() : name(""), id(0), age(0), major("") {}
    Student(const string& name, int id, int age, const string& major)
        : name(name), id(id), age(age), major(major) {}

    // Методи для отримання та встановлення значень полів (геттери і сеттери)
    string getName() const { return name; }
    int getId() const { return id; }
    int getAge() const { return age; }
    string getMajor() const { return major; }

    void setName(const string& name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setAge(int age) { this->age = age; }
    void setMajor(const string& major) { this->major = major; }

    // Метод print() для виведення інформації про студента.
    void print() const {
        cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nMajor: " << major << endl;
    }

    // Функції створювання та читання файлу
    void writeFile(ofstream& fout) const {
        fout << id << '\n' << name << '\n' << age << '\n' << major << '\n';
    }

    void readFile(ifstream& fin) {
        fin >> id;
        fin.ignore();
        getline(fin, name);
        fin >> age;
        fin.ignore();
        getline(fin, major);
    }
};

class StudentDatabase {
    Student* students; // динамічний масив вказівників на студентів
    int capacity; // максимальна кількість студентів, що може зберігати база даних
    int count; // поточна кількість студентів

    void resize() {
        capacity *= 2;
        Student* newStudents = new Student[capacity];
        for (int i = 0; i < count; ++i) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
    }

public:
    // Конструктор з параметром для ініціалізації початкової ємності
    StudentDatabase(int c = 10) : capacity(c), count(0) {
        students = new Student[capacity];
    }

    // Деструктор для звільнення пам'яті
    ~StudentDatabase() {
        if (students != nullptr && count > 0) {
            delete[] students;
        }
    }

    // додавання студента у базу даних
    bool isIdUnique(int id) const {
        for (int i = 0; i < count; i++) {
            if (students[i].getId() == id) {
                return false;
            }
        } return true;
    }

    void addStudent(const Student& s, bool printCreated = true) {
        if (!isIdUnique(s.getId())) {
            cout << "student " << s.getId() << " already exists" << endl;
            return;
        }
        if (s.getId() <= 0) {
            cout << "id must be greater than 0" << endl;
            return;
        }
        if (count == capacity) {
            resize();
        }
        students[count++] = s;
        if (printCreated) {
            cout << "created" << endl;
        }
    }

    // видалення студента за ідентифікаційним номером
    void removeStudent(int id) {
        for (int i = 0; i < count; ++i) {
            if (students[i].getId() == id) {
                for (int j = i; j < count - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --count;
                cout << "deleted" << endl;
                return;
            }
        }
        cout << "\nnot found" << endl;
    }

    // пошук студента за ідентифікаційним номером (повертає вказівник на студента або nullptr, якщо студент не знайдений)
    Student* findStudent(int id) const {
        for (int i = 0; i < count; ++i) {
            if (students[i].getId() == id) {
                return &students[i];
            }
        } return nullptr;
    }

    // виведення списку всіх студентів.
    void listStudents() const {
        for (int i = 0; i < count; ++i) {
            students[i].print();
            cout << "--------------------" << endl;
        }
    }

    // запис всіх студентів у файл
    void saveToFile(const string& filename) const {
        ofstream fout(filename);
        if (!fout.is_open()) {
            cerr << "error save file" << endl;
            return;
        }
        fout << count << endl;
        for (int i = 0; i < count; ++i) {
            students[i].writeFile(fout);
        }
        fout.close();
        cout << "saved\n" << endl;
    }

    // зчитування студентів з файлу
    void loadFromFile(const string& filename) {
        ifstream fin(filename);
        if (!fin.is_open()) {
            cerr << "error open file\n" << endl;
            return;
        }
        else {
            cout << "loaded\n" << endl;
        }
        int fileCount;
        fin >> fileCount;
        fin.ignore();

        if (fileCount > capacity) {
            delete[] students;
            capacity = fileCount;
            students = new Student[capacity];
        } count = 0;

        for (int i = 0; i < fileCount; ++i) {
            Student temp;
            temp.readFile(fin);
            addStudent(temp, false);
        } fin.close();
    }

    // оновлення даних студента за ідентифікаційним номером
    void updateStudent(int id, const Student& newdata) {
        Student* student = findStudent(id);
        if (!student) {
            cout << "not found" << endl;
        }
        else {
            *student = newdata;
            cout << "\nupdated" << endl;
        }
    }

    // виведення студентів, що навчаються за певною спеціальністю
    void filterByMajor(const string& major) const {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (students[i].getMajor() == major) {
                students[i].print();
                cout << "--------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "not found" << endl;
        }
    }

    // Додатково
    // функція сортування студентів за ідентифікаційним номером, ім'ям або віком
    bool compStudents(const Student& a, const Student& b, const string& criterion) {
        if (criterion == "id") { return a.getId() < b.getId(); }
        else if (criterion == "name") { return a.getName() < b.getName(); }
        else if (criterion == "age") { return a.getAge() < b.getAge(); }
        else { cout << "\nInvalid!" << endl; return false; }
    }

    void sortStudents(const string& criterion) {
        sort(students, students + count, [&](const Student& a, const Student& b) { return compStudents(a, b, criterion);  });
        cout << "\nsorted" << endl;
    }

    // функція фільтрації студентів за віком
    void filterByAge(int age) const {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (students[i].getAge() == age) {
                students[i].print();
                cout << "--------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "not found" << endl;
        }
    }

    // функція для підрахунку кількості студентів у базі даних
    int getStudentCount() const {
        return count;
    }
};

void menu() {
    StudentDatabase studentDB; int choice;
    string filename = "students.txt";

    do {
        cout << "1. Add student\t\t7. Filter by age\n2. Delete student\t8. Filter by major\n3. Update student\t9. Get student count\n4. Search student\t10. Save to file\n5. Sort students\t11. Load from file\n6. List all students\t0. Exit\n\nEnter your choice: ";
        cin >> choice; cout << endl;

        switch (choice) {
        case 1: {
            string name, major; int id, age;
            cout << "Enter student ID: "; cin >> id; cin.ignore();
            cout << "Enter student name: "; getline(cin, name);
            cout << "Enter student age: "; cin >> age; cin.ignore();
            cout << "Enter student major: "; getline(cin, major);
            Student student(name, id, age, major);
            studentDB.addStudent(student); cout << endl;
            break;
        }
        case 2: {
            int id;
            cout << "Enter student ID to delete: "; cin >> id;
            studentDB.removeStudent(id); cout << endl;
            break;
        }
        case 3: {
            int id, age;
            string name, major;
            cout << "Enter student ID to update: "; cin >> id; cin.ignore();
            cout << "Enter new student name: "; getline(cin, name);
            cout << "Enter new student age: "; cin >> age; cin.ignore();
            cout << "Enter new student major: "; getline(cin, major);
            studentDB.updateStudent(id, Student(name, id, age, major)); cout << endl;
            break;
        }
        case 4: {
            int id;
            cout << "Enter student ID to search: "; cin >> id; cout << endl;
            Student* student = studentDB.findStudent(id);
            if (student) {
                student->print();
            }
            else {
                cout << "not found" << endl;
            } cout << endl;
            break;
        }
        case 5: {
            string criterion;
            cout << "Sort by (id, name, age): "; cin >> criterion;
            studentDB.sortStudents(criterion); cout << endl;
            break;
        }
        case 6: {
            studentDB.listStudents(); cout << endl;
            break;
        }
        case 7: {
            int age;
            cout << "Enter age to filter: "; cin >> age;
            studentDB.filterByAge(age); cout << endl;
            break;
        }
        case 8: {
            string major;
            cout << "Enter major to filter: "; cin.ignore(); getline(cin, major);
            studentDB.filterByMajor(major); cout << endl;
            break;
        }
        case 9: {
            cout << "Student count: " << studentDB.getStudentCount() << endl << endl;
            break;
        }
        case 10: {
            studentDB.saveToFile(filename);
            break;
        }
        case 11:
        {
            studentDB.loadFromFile(filename);
            break;
        }
        case 0:
        {
            cout << "Exiting...\n";
            break;
        }
        default: {
            cout << "Invalid!\n";
            break;
        }
        }
    } while (choice != 0);
}

int main() {
    menu();
}