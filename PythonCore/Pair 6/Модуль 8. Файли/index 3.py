with open('input.txt', 'w', encoding='utf-8') as file:
    file.write("Рядок 1\n")
    file.write("Рядок 2\n")
    file.write("12345\n")
    file.write("@#%&*()\n")

with open('input.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()

print("Файл до видалення рядка: \n")
print(''.join(lines))

lines = lines[:-1]


print("\nФайл після видалення рядка: \n")
print(''.join(lines))