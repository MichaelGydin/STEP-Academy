for i in range(1,11):
    print(i)

list = [1,2,3]
iterator = iter(list)
for i in iterator:
    print(i)

for i in iterator:
    print(i)

class Counter:
    def __init__(self, max_number):
        self.i = 0
        self.max_number = max_number

    def __iter__(self):
        self.i = 0
        return self

    def __next__(self):
        self.i += 1
        if self.i > self.max_number:
            raise StopIteration
        return self.i

count = Counter(input("Введи число: "))

if count != int:
    print("Я казав щоб ти написав число!")
    count = Counter(input("Введи ЧИСЛО!: "))

if count != int:
    print("Я КАЗАВ ЩОБ ТИ НАПИСАВ ЧИСЛО!")
    count = Counter(input("ВВЕДИ ЧИСЛО!: "))

if count != int:
    count = Counter(input("Я обідився! "))

if count == int:
    for i in int(count):
        print(i)

def raise_to_the_degress(number,max_degree):
    i = 0
    while True:
        yield number**i
        i+=1

res = raise_to_the_degress(2,50)
print(res)

for _ in res:
    print(str(_)+ "\n")

class Helper:
    def __init__(self, work):
        self.work = work

    def __call__(self, work):
        return f"I will help you with your {self.work}. Afterwards I will help you with {work}."
    
helper = Helper("homework")
print(helper("cleaning"))

def checker(function):
    def checker(function, *args, **kwards):
        try:
            result = function(*args, **kwards)
        except Exception as exc:
            print(f"We have problems {exc}")
        else: 
            print(f"Result: {result}")

def calculate(expression):
    return eval(expression)

calc = checker(calculate)
calculate("2+2")
