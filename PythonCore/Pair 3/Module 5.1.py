print("\n\t Модуль 5. Рядки\n\t    Завдання 1\n")

str1 = input(" Введіть рядок: ")
str1 = str1.lower()
str2 = str1.replace(" ", "")

if str2 == str2[::-1]:
    print(" Введений рядок є паліндромом.\n")
else:
    print(" Введений рядок не є паліндромом.\n")


print("\n\t    Завдання 2\n")

str3 = input(" Введіть текст: ")
str4 = input(" Введіть зарезервовані слова, розділені комами: ").split(",")

for word in str4:
    if word in str3:
        str3 = str3.replace(word, word.upper())

print(f" {str3}")


print("\n\t    Завдання 3\n")

str5 = input(" Введіть текст: ")
str6 = str5.count(".") + str5.count("!") + str5.count("?")
print(f" Кількість речень у тексті: {str6}")