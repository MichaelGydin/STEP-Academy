print("\n\t Модуль 4. Цикли.\n\t    Частина 1\n\t   Завдання 1\n")
start = int(input(" Введіть початкове число: "))
end = int(input(" Введіть кінцеве число: "))
for i in range(start, end+1):
    if i % 7 == 0:
        print(f"\n {i}")


print("\n\n\t   Завдання 2\n")
start1 = int(input(" Введіть початкове число: "))
end1 = int(input(" Введіть кінцеве число: "))

print("\n Всі числа діапазону: ")
for i1 in range(start1, end1+1):
    print(f"\n {i1}")

print("\nВсі числа діапазону в спадному порядку:")
for i1 in range(end1, start1-1, -1):
    print(f"\n {i1}")

print("\nВсі числа, кратні 7:")
for i1 in range(start1, end1+1):
    if i1 % 7 == 0:
        print(f"\n {i1}")

print("\nКількість чисел, кратних 5:")
count = 0
for i1 in range(start1, end1+1):
    if i1 % 5 == 0:
        count += 1
print(f"\n {count}")


print("\n\t   Завдання 3\n")
start2 = int(input("Введіть початкове число: "))
end2 = int(input("Введіть кінцеве число: "))

for i2 in range(start2, end2+1):
    if i2 % 3 == 0 and i2 % 5 == 0:
        print(" Fizz Buzz")
    elif i2 % 3 == 0:
        print(" Fizz")
    elif i2 % 5 == 0:
        print(" Buzz")
    else:
        print(f"\n {i2}")