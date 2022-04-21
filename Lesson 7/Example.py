class Human:
    def __init__(self, name):
        self.name = name
    
class Auto:
    def __init__(self, brand):
        self.brand = brand
        self.passengers = []

    def add_passenger(self, human):
        self.passengers.append(human)

    def print_passengers(self):
        if self.passengers != []:
            print(f"Name of {self.brand} passengers: ")
            for i in self.passengers:
                print(i.name)
        else:
            print(f"There are no passenger in {self.brand}!")

name_1 = Human(input("Enter name first passenger: "))
name_2 = Human(input("Enter name second paseenger: "))

car = Auto(input("Enter brand your auto: "))
car.add_passenger(name_1)
car.add_passenger(name_2)
car.print_passengers()