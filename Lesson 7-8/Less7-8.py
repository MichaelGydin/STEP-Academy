import random
from turtle import clear

class Human:
    def __init__(self,name = "Human", job = None , home = None, car = None):
        self.name = name
        self.money = 100
        self.gladness = 100
        self.setiety = 100
        self.job = job
        self.home = home
        self.car = car

    def get_home(self):
        pass
        self.home = House()

    def get_car(self):
        pass
        self.car = Auto(brands_of_car)

    def get_job(self):
        pass
        self.job = Job(job_list)

    def eat(self):
        pass
        if self.home.food <= 0:
            self.shopping("Food")
        else:
            if self.setiety >= 100:
                self.setiety = 100
            self.setiety += 10
            self.home.food -= 10

    def work(self):
        pass
        self.money += self.job.salary
        self.gladness -= self.job.gladness_less
        self.setiety -= 4

    def shopping(self,manage):
        pass
        if manage == "Food":
            print("I bought food")
            self.money -= 50
            self.home.food += 30

    def chill(self):
        pass
        self.gladness += 20
        self.home.mess += 10

    def clean_home(self):
        pass
        self.gladness -= 10
        self.home.mess = 0

    def days_index(self,day):
        pass
        day = f"Today the {day} of {self.name}'s life"
        print(f"{day:=^50}")

    def is_alive(self):
        pass
        human_indexes = self.name + "'s indexes"       
        print(f"{human_indexes:=^50}","\n")
        print(f"Money: {self.money}")
        print(f"Setiety: {self.setiety}")
        print(f"Gladness: {self.gladness}")

        home_indexes = "Home indexes"
        print(f"{home_indexes:=^50}","\n")
        print(f"Food: {self.home.food}")
        print(f"Mess: {self.home.mess}")

        car_indexes = f"{self.car.brand} car indexes"
        print(f"{car_indexes:=^50}","\n")
        print(f"Fuel: {self.car.fuel}")
        print(f"Strength: {self.car.strength}")


    def is_alive(self):
        if self.gladness < 0:
            print("You are depressed...")
            return False
        
        if self.setiety < 0:
            print("You died of malnutrition...")
            return False

        if self.money < 0:
            print("You went bankrupt...")
            return False

    def live(self,day):
        pass
        if self.is_alive() == False:
            return False

        if self.home is None:
            print("Settled in the house")
            self.get_home()

        if self.car is None:
            self.get_car()
            print(f"I bought a car {self.car.brand}")

        if self.job is None:
            self.get_job()
            print(f"Now I have a job {self.job.job} with salary {self.job.salary}")   

        self.days_index(day)

        dice = random.randint(1,3)

        if self.setiety < 20:
            print("I will go eat")
            self.eat()

        elif self.gladness < 20:
            if self.home.mess > 15:
                print("I want to chill, but there is so much mess...\n So I will clean the house")
                self.clean_home()
            else:
                print("Let's chill!")
                self.chill()
        elif self.money < 0:
            print("Start working")
            self.work()
        elif dice == 1:
            print("Let's chill!")
            self.chill()
        elif dice == 2:
            print("Start working")
            self.work()
        elif dice == 3:
            print("Cleaning time!")
            self.clean_home()
class Auto:
    def __init__(self,brand_list):
        self.brand = random.choice(list (brand_list))
        self.fuel = brand_list[self.brand]["Fuel"]
        self.strength = brand_list[self.brand]["Strength"]

    def drive(self):
        if self.fuel <= 0:
            print("The car cannot move")
            return False

class House:
    def __init__(self):
        self.mess = 0
        self.food = 0

class Job:
    def __init__(self,job_list):
        self.job = random.choice(list(job_list))
        self.salary = job_list[self.job]["Salary"]
        self.gladness_less = job_list[self.job]["Gladness_less"]

brands_of_car = {
    "BMW": {"Fuel":70, "Strenght":100},
    "Mercedes": {"Fuel":55, "Strenght":100},
    "Ferrari": {"Fuel":40, "Strenght":100},
    "Porsche": {"Fuel":50, "Strenght":100},
    "Lamborghini": {"Fuel":20, "Strenght":100},
    "Audi": {"Fuel":35, "Strenght":100},
    "Ford": {"Fuel":75, "Strenght":100},
    "Jaguar": {"Fuel":25, "Strenght":100},
    }

job_list = {
    "Python Developer": {"Salary":40, "Gladnees less":4},
    "Java Developer": {"Salary":60, "Gladnees less":6},
    "HTML Developer": {"Salary":50, "Gladnees less":5},
    "C++ Developer": {"Salary":70, "Gladnees less":7},
    }

nick = Human(name="Nick")
for day in range(1,8):
    if nick.live(day == False):
        break
    clear()
    input("Press to continue...")