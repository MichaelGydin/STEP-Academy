import math
import random

print("\n\t Модуль 6. Функції.\n\t    Завдання 1\n")

def findSumOfList(listOfNums):
    sum = 1
    for num in listOfNums:
        sum *= num
    return sum

numbers1 = [1, 2, 3, 4, 5, 6]
print("Добуток елементів в списку цілих: ", findSumOfList(numbers1))


print("\n\t    Завдання 2\n")

def findMinOfList(listOfNums):
    if not listOfNums:
        return "Список порожній"
    else:
        return min(listOfNums)

numbers2 = [1, 2, 3, 4, 5, 6]
print("Мінімум в списку цілих: ", findMinOfList(numbers2))


print("\n\t    Завдання 3\n")

def isPrime(n):
    if n < 2:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def countPrimes(listOfNums):
    return sum(isPrime(num) for num in listOfNums)

numbers3 = [1, 2, 3, 4, 5, 6]
print("Кількість простих чисел у списку цілих: ", countPrimes(numbers3))


print("\n\t    Завдання 4\n")

def deleteCount(listOfNums, num):
    count = listOfNums.count(num)
    while num in listOfNums:
        listOfNums.remove(num)
    return count

numbers4 = [1, 2, 3, 4, 5, 6, 2, 2]
num_to_delete = 2
print("Кількість видалених елементів: ", deleteCount(numbers4, num_to_delete))


print("\n\t    Завдання 5\n")

def combineLists(list1, list2):
    return list1 + list2

numbers5 = [1, 2, 3, 4, 5, 6]
numbers6 = [7, 8, 9, 10, 11, 12]
print("Список, що містить елементи обох списків: ", combineLists(numbers5, numbers6))


print("\n\t    Завдання 6\n")

def powerList(listOfNums, power):
    return [num ** power for num in listOfNums]

numbers7 = [1, 2, 3, 4, 5, 6]
power = 2
print("Список, що містить результати піднесення до ступеня: ", powerList(numbers7, power))