import random
class Hero:
    def __init__(self, name, age, race,):
        self.name = name
        self.health = 100
        self.age = age
        self.race = race
        self.power = 100
        self.gladness = 50
        self.money = 1000
        self.lvl = 1
        self.alive = True

    def to_market(self):
        print("Time for shopping!")
        self.money -= 150
        self.gladness += 3

    def to_hunting(self):
        print("Time to hunt!")
        self.money += 175
        self.gladness -= 6
        self.health -= 10
        self.power -= 15
        self.lvl += 1
        print("Level Up!")

    def to_chill(self):
        print("Rest time!")
        self.gladness += 5
        self.power += 7.5

    def to_eat(self):
        print("Om-Nom-nom")
        self.power += 10
        self.health += 10
        self.gladness += 2

    def is_alive(self):
        if self.money < -50:
            print("You are poor...")
            self.alive = False
        elif self.gladness <= 0:
            print("Depression...")
            self.alive = False
        elif self.power < 0:
            print("You are too frail...")
            self.alive = False
        elif self.health < 0:
            print("You died...")
            self.alive = False

    def end_of_date(self):
        print(f"Gladness = {round(self.gladness)}")
        print(f"Power = {round(self.power)}")
        print(f"Health = {round(self.health)}")
        print(f"Money = {round(self.money)}")

    def live(self, day):
        day = "Day " + str(day) + " of " + self.name + "'s" + " life"
        print(f"{day:=^50}")
        live = random.randint(1,4)
        if live == 1:
            self.to_chill()
        elif live == 2:
            self.to_eat()
        elif live == 3:
            self.to_hunting()
        elif live == 4:
            self.to_market()
        self.end_of_date()
        self.is_alive()

    def show(self):
        print("Name: " + str(self.name))
        print("Age: " + str(self.age))
        print("Race: " + str(self.race))
        print("Level: " + str(self.lvl))
        return(First)
    
First = Hero(name=(input("Enter name: ")), age=(int(input("Enter age: "))), race=(input("Enter race: ")))

for day in range(1, 365):
    if First.is_alive == False:
        break
    First.live(day)
    input("Press Enter to continue...")