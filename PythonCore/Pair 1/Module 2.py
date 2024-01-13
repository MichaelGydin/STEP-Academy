print("\n Модуль 2. Зміннні та типи данних.\n\t Завдання 1\n")

number1 = int(input(" Введіть перше число: "))
number2 = int(input(" Введіть друге число: "))
number3 = int(input(" Введіть третє число: "))
suma = number1 + number2 + number3 
dobutok = number1 * number2 * number3 

print(f"\n {number1} + {number2} + {number3} = {suma}")
print(f" {number1} • {number2} • {number3} = {dobutok}\n")


print("\n\t Завдання 2\n")

salary = int(input(" Введіть зарплату за місяць: "))
debt = int(input(" Введіть суму місячного платежу за кредитом у банку: "))
utilityBill = int(input(" Введіть заборгованість за комунальні послуги: "))
residue = salary - debt - utilityBill

print(f"\n Сума, яка залишиться у вас після всіх виплат: {residue} грн.\n")


print("\n\t Завдання 3\n")

d1 = int(input(" Введіть довжину першої діагоналі ромба: "))
d2 = int(input(" Введіть довжину другої діагоналі ромба: "))
area = (d1 * d2) / 2

print(f"\n Площа ромба: {area}\n")