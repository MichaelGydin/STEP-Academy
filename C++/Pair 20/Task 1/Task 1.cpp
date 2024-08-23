#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
    string name;
    int age;

public:
    Pet(const string& name, int age) : name(name), age(age) {}

    virtual void ShowInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Dog : public Pet {
private:
    string breed;

public:
    Dog(const string& name, int age, const string& breed)
        : Pet(name, age), breed(breed) {}

    void ShowInfo() const override {
        cout << "Dog - ";
        Pet::ShowInfo();
        cout << "Breed: " << breed << endl;
    }
};

class Cat : public Pet {
private:
    string color;

public:
    Cat(const string& name, int age, const string& color)
        : Pet(name, age), color(color) {}

    void ShowInfo() const override {
        cout << "Cat - ";
        Pet::ShowInfo();
        cout << "Color: " << color << endl;
    }
};

class Parrot : public Pet {
private:
    string species;

public:
    Parrot(const string& name, int age, const string& species)
        : Pet(name, age), species(species) {}

    void ShowInfo() const override {
        cout << "Parrot - ";
        Pet::ShowInfo();
        cout << "Species: " << species << endl;
    }
};

int main() {
    Dog dog("Buddy", 5, "Golden Retriever");
    Cat cat("Whiskers", 3, "Black");
    Parrot parrot("Polly", 2, "Macaw");

    dog.ShowInfo();
    cat.ShowInfo();
    parrot.ShowInfo();
}
