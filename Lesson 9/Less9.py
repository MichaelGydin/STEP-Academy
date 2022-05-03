import random

class Hero:
    height = str(random.randint(150, 200)) + " cm"
    race = "Hero"
    age = str(random.randint(16, 40))

class Elf(Hero):
    race = "Elf"

class Dwarf(Hero):
    race = "Dwarf"

class Mage(Hero):
    race = "Mage"

nick = Elf()
stas = Dwarf()
vika = Mage()

print("Nick's height is: " + str(nick.height))
print("Nika's race: " + str(nick.race))
print("Nick is " + str(nick.age) + " years old")
print("---------------------------")
print("Stas's height is: " + str(stas.height))
print("Stas's race: " + str(stas.race))
print("Stas is " + str(stas.age) + " years old")
print("---------------------------")
print("Vika's height is: " + str(stas.height))
print("Vika's race is: " + str(stas.race))
print("Vika is " + str(stas.age) + " years old")