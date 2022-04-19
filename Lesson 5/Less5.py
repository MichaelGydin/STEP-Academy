class Hero:
    amount_students = 0
    def __init__(self, name, health, age, race, power):
        self.name = name
        self.health = health
        self.age = age
        self.race = race
        self.power = power
        self.lvl = 1

    def show(self):
        print("Name: " + str(self.name))
        print("Health: " + str(self.health))
        print("Age: " + str(self.age))
        print("Race: " + str(self.race))
        print("Power: " + str(self.power))
        print("Level: " + str(self.lvl))
        return(First)

    def LvlUp(self):
        self.lvl = 1
        print("Level Up!")
    
First = Hero(name=(input("Enter name: ")), health=(int(input("Enter age: "))), race=(input("Enter race: ")), power=(int(input("Enter power: "))))
