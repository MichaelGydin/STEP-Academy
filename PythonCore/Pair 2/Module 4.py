print("\n\t Модуль 4. Цикли.\n\t    Частина 2\n\t   Завдання 1\n")
start = int(input(" Введіть початкове число: "))
end = int(input(" Введіть кінцеве число: "))

sum_even = sum_odd = sum_mult9 = 0
count_even = count_odd = count_mult9 = 0

for i in range(start, end+1):
    if i % 2 == 0:
        sum_even += i
        count_even += 1
    else:
        sum_odd += i
        count_odd += 1

    if i % 9 == 0:
        sum_mult9 += i
        count_mult9 += 1

avg_even = sum_even / count_even if count_even > 0 else 0
avg_odd = sum_odd / count_odd if count_odd > 0 else 0
avg_mult9 = sum_mult9 / count_mult9 if count_mult9 > 0 else 0

print(f"\n Сума парних чисел: {sum_even}, середнє значення: {avg_even}")
print(f" Сума непарних чисел: {sum_odd}, середнє значення: {avg_odd}")
print(f" Сума чисел, кратних 9: {sum_mult9}, середнє значення: {avg_mult9}\n")


print("\n\t   Завдання 2\n")
length = int(input(" Введіть довжину лінії: "))
symbol = input(" Введіть символ для заповнення лінії: ")
for i in range(length):
    print(f"{symbol}")


print("\n\n\t   Завдання 3\n")
while True:
    num = int(input(" Введіть число: "))
    if num > 0:
        print("\n Число додатне\n")
    elif num < 0:
        print("\n Число від'ємне\n")
    elif num == 0:
        print("\n Число дорівнює нулю\n")
    if num == 7:
        print(" Бувай!\n")
        break


print("\n\t   Завдання 4\n")

sum = 0
max = 0
min = 0

while True:
    number = int(input(" Введіть число: "))

    sum += number
    if max is 0 or number > max:
        max = number
    if min is 0 or number < min:
        min = number
    if number == 7:
        print("\n Бувай!\n")
        break

print(f" Сума: {sum}")
print(f" Максимум: {max}")
print(f" Мінімум: {min}")