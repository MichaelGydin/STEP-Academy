import random

print("\n\t Модуль 6. Списки.\n\t    Завдання 1\n")

print(" Арифметичний вираз може складатися тільки\n з трьох частин: число, операція, число(5 + 3).\n Можливі операції:\n Додавання: +\n Віднімання: -\n Множення: *\n Ділення: /")
str1 = input(" Ведіть рифметичний вираз: ").split()
print(" Результат: ", eval(str1[0] + str1[1] + str1[2]))


print("\n\t    Завдання 2\n")

str2 = [random.randint(-10, 10) for _ in range(20)]

min_num = min(str2)
max_num = max(str2)

countN = len([num for num in str2 if num < 0])
countP = len([num for num in str2 if num > 0])
countZ = len([num for num in str2 if num == 0])

print(f"Мінімальне число: {min_num}")
print(f"Максимальне число: {max_num}")
print(f"Кількість від'ємних чисел: {countN}")
print(f"Кількість додатних чисел: {countP}")
print(f"Кількість нулів: {countZ}")