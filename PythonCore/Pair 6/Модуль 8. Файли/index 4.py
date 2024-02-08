with open('file.txt', 'w', encoding='utf-8') as file:
    file.write("Звичайний рядок\n")
    file.write("ДууУУууже довгий рядок\n")
    file.write("1234567890\n")
    file.write("!@#№$;%^:&?*()-_=+\n")

with open('file.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()

max_length = max(len(line) for line in lines)

print(f"Довжина найдовшого рядка: {max_length}")