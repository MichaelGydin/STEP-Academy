list1 = [' 1', ' 2', ' 3', ' 4', ' 5', ' 6', ' 7', ' 8', ' 9', ' 0',]

with open("file1.txt", "w") as file1, open("file2.txt", "w") as file2:
    file1.write("\n Welcome to my World!")
    file1.write("\n Hello from Rivne!\n")
    file1.writelines(list1)
    print(" File1 is closed")

    file2.write("\n Welcome to my World!")
    file2.write("\n Hello from Kyiv!\n")
    file2.writelines(list1[::-1])
    print(" File2 is closed")

with open('file1.txt', 'r') as file1, open('file2.txt', 'r') as file2:
    lines1 = file1.readlines()
    lines2 = file2.readlines()

    for i in range(min(len(lines1), len(lines2))):
        if lines1[i] != lines2[i]:
            print(f"Рядок {i+1} не співпадає:")
            print(f"У file1.txt: {lines1[i]}")
            print(f"У file2.txt: {lines2[i]}")

