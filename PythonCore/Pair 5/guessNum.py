import random

def guess_the_number():
    number_to_guess = random.randint(1, 101)
    attempts = 0
    max_attempts = 10

    while attempts < max_attempts:
        try:
            user_guess = int(input(" Введіть число від 1 до 100: "))
        except ValueError:
            print(" Це не виглядає як число. Спробуйте ще раз.")
            continue

        if user_guess < number_to_guess:
            print(" Ваше число менше загаданого. Спробуйте ще раз.")
        elif user_guess > number_to_guess:
            print(" Ваше число більше загаданого. Спробуйте ще раз.")
        else:
            print(f" Вітаємо! Ви вгадали число {number_to_guess} за {attempts+1} спроб!")
            return

        attempts += 1

    print(f" Ви вичерпали всі спроби. Загадане число було {number_to_guess}.")

if __name__ == "__main__":
    guess_the_number()