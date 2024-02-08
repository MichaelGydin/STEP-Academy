with open('file.txt', 'w', encoding='utf-8') as file:
    file.write("Рядок 1\n")
    file.write("Рядок 2\n")
    file.write("12345\n")
    file.write("@#%&*()\n")

old_word = "Рядок"
new_word = "Строка"

with open('file.txt', 'r', encoding='utf-8') as file:
    text = file.read()

text = text.replace(old_word, new_word)
print(text)