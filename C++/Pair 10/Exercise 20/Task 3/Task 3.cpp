#include <iostream>
using namespace std;

enum EntityType { BIRD, CATTLE, HUMAN };

struct Characteristic {
    double flightSpeed;
    bool isEvenToed;
    int iq;
};

struct LivingEntity {
    double movementSpeed;
    EntityType type;
    string color;
    Characteristic characteristic;
};

void inputEntity(LivingEntity& entity) {
    int type;
    cout << "Enter type (0 for Bird, 1 for Cattle, 2 for Human): "; cin >> type;
    entity.type = static_cast<EntityType>(type);

    cout << "Enter movement speed: ";
    cin >> entity.movementSpeed;

    cout << "Enter color: ";
    cin >> entity.color;

    switch (entity.type) {
    case BIRD:
        cout << "Enter flight speed: ";
        cin >> entity.characteristic.flightSpeed;
        break;
    case CATTLE:
        cout << "Is even-toed? (1 for Yes, 0 for No): ";
        cin >> entity.characteristic.isEvenToed;
        break;
    case HUMAN:
        cout << "Enter IQ: ";
        cin >> entity.characteristic.iq;
        break;
    }
}

void displayEntity(const LivingEntity& entity) {
    cout << "Movement Speed: " << entity.movementSpeed << endl;
    cout << "Type: ";
    switch (entity.type) {
    case BIRD:
        cout << "Bird" << endl;
        cout << "Flight Speed: " << entity.characteristic.flightSpeed << endl;
        break;
    case CATTLE:
        cout << "Cattle" << endl;
        cout << "Even-Toed: " << (entity.characteristic.isEvenToed ? "Yes" : "No") << endl;
        break;
    case HUMAN:
        cout << "Human" << endl;
        cout << "IQ: " << entity.characteristic.iq << endl;
        break;
    }
    cout << "Color: " << entity.color << endl;
}

void editEntity(LivingEntity& entity) {
    inputEntity(entity);
}

void displayAllEntities(const LivingEntity entities[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Entity " << i + 1 << ":" << endl;
        displayEntity(entities[i]);
    }
}

void searchByCharacteristic(const LivingEntity entities[], int size) {
    int type;
    cout << "Enter type to search (0 for Bird, 1 for Cattle, 2 for Human): ";
    cin >> type;

    for (int i = 0; i < size; ++i) {
        if (entities[i].type == static_cast<EntityType>(type)) {
            cout << "Entity " << i + 1 << ":" << endl;
            displayEntity(entities[i]);
        }
    }
}

int main() {
    const int SIZE = 10;
    LivingEntity entities[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        cout << "Enter details for entity " << i + 1 << ":" << endl;
        inputEntity(entities[i]);
    }

    cout << "\nAll Entities:\n";
    displayAllEntities(entities, SIZE);

    int index;
    cout << "\nEnter index of entity to edit (1 to 10): ";
    cin >> index;
    if (index >= 1 && index <= 10) {
        editEntity(entities[index - 1]);
    }

    cout << "\nAll Entities after editing:\n";
    displayAllEntities(entities, SIZE);

    cout << "\nSearch by characteristic:\n";
    searchByCharacteristic(entities, SIZE);

    return 0;
}
