import warnings

warnings.simplefilter("error", TypeError)

print("Registration")
print("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
try:
    try:
        name = input("Enter your name: ")
        if type(name) != str:
            raise TypeError(f"Houston, I'm sorry, but I can't work with this text type {type(name)}, I need a text type str...")
        try:
            warnings.warn("Warning, type text not correct!", TypeError)
        except: 
            print("Warning process!")
    except:
        print("Houston text type is correct!")

    try:
        surname = input("Enter your surname: ")
        if type(surname) != str:
            raise TypeError(f"Houston, I'm sorry, but I can't work with this text type {type(surname)}, I need a text type str...")
        try:
            warnings.warn("Warning, type text not correct!", TypeError)
        except: 
            print("Warning process!")
    except:
        print("Houston text type is correct!")

    try:
        age = input("Enter your age: ")
        if type(age) != int:
            raise TypeError(f"Houston, I'm sorry, but I can't work with this text type {type(age)}, I need a text type int...")
        try:
            warnings.warn("Warning, type text not correct!", TypeError)
        except: 
            print("Warning process!")
    except:
        print("Houston text type is correct!")

except:
    print("Houston, type of all text is correct!")
    i
    