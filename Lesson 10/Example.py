try:
    try:
        print("Starting code...")
    except SyntaxError:
        print("Houston, we have a SyntaxError!")
except NameError as error:
    print(error)
else:
    print("Houston, we do not have problems!")
finally:
    print("Turn offing the code...")
    print("Code off...")

def checker(a):
    if type(a) != str:
        raise TypeError(f"Houston, I'm sorry, but I can't work with this text type {type(a)}, I need a text type str...")
    else:
        print("Houston text type is correct!")

b = 10
checker(b)
import warnings

warnings.simplefilter("ignore", SyntaxWarning)
warnings.simplefilter("error", ImportWarning)

warnings.warn("Warning, no code here!", SyntaxWarning)

try:
    warnings.warn("Warning, library not import!", ImportWarning)
except: 
    print("Warning process!")