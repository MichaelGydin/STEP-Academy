with open('input.txt', 'w') as file:
    file.write("line\n")
    file.write("line 2\n")
    file.write("12345\n")
    file.write("@#%&*()\n")

with open('input.txt', 'r') as file:
    text = file.read()

bukva = len(text)
ryadok = text.count('\n')
litera = sum(text.count(lines) for lines in "qwertyQWERTY")
Bukva = sum(text.count(BIGbukva) for BIGbukva in "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ")
digit = sum(char.isdigit() for char in text)

with open('output.txt', 'w') as file:
    file.write(f"1: {bukva}\n")
    print(f"1: {bukva}")

    file.write(f"2: {ryadok}\n")
    print(f"2: {ryadok}")

    file.write(f"3: {litera}\n")
    print(f"3: {litera}")

    file.write(f"4: {Bukva}\n")
    print(f"4: {Bukva}")

    file.write(f"5: {digit}\n")
    print(f"5: {digit}")
