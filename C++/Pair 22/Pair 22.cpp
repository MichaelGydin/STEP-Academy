#include <iostream>
#include <string>

using namespace std;

class Instrument
{
protected:
    string name;
    int yearOfInvention;

public:
    Instrument(string name = "", int year = 0) : name{ name }, yearOfInvention{ year } {}

    virtual void playSound() const = 0;
    virtual void adjustVolume(int level) = 0;

    virtual ~Instrument() {}
};

class StringInstrument : public Instrument
{
private:
    int numberOfStrings;

public:
    StringInstrument(string name, int year, int numStrings)
        : Instrument(name, year), numberOfStrings{ numStrings } {}

    void playSound() const override { cout << "Playing " << name << " with " << numberOfStrings << " strings." << endl; }
    void adjustVolume(int level) override {  cout << "Adjusting volume of " << name << " to level " << level << "." << endl; }
};

class WindInstrument : public Instrument
{
private:
    string mouthpieceType;

public:
    WindInstrument(string name, int year, string mouthpiece)
        : Instrument(name, year), mouthpieceType{ mouthpiece } {}

    void playSound() const override { cout << "Playing " << name << " with a " << mouthpieceType << " mouthpiece." << endl; }
    void adjustVolume(int level) override { cout << "Adjusting volume of " << name << " to level " << level << "." << endl; }
};

class PercussionInstrument : public Instrument
{
private:
    string strikingPart;

public:
    PercussionInstrument(string name, int year, string part)
        : Instrument(name, year), strikingPart{ part } {}

    void playSound() const override { cout << "Playing " << name << " with a " << strikingPart << "." << endl; }
    void adjustVolume(int level) override { cout << "Adjusting volume of " << name << " to level " << level << "." << endl; }
};

int main() {
    Instrument* instruments[3];
    instruments[0] = new StringInstrument("Guitar", 1940, 6);
    instruments[1] = new WindInstrument("Trumpet", 1800, "cup");
    instruments[2] = new PercussionInstrument("Drum", 1500, "drumstick");

    for (int i = 0; i < 3; ++i)
    {
        instruments[i]->playSound();
        instruments[i]->adjustVolume(10);
        cout << endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        delete instruments[i];
    }
}
