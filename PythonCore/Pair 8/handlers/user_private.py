from aiogram import types, Router
from aiogram.filters import CommandStart, Command
import random

user_private_router = Router()

Hello = random.choice(["Hi!", "Hello!", "Привіт!", "Здоровенькі були!"])
Bye = random.choice(["Goodbye!", "Bye!", "Бувай!", "Прощавай!", "До зустрічі!"])

@user_private_router.message(CommandStart())
async def start_cmd(message: types.Message):
    await message.answer(f"{Hello} {message.from_user.full_name}! Бот запущено!")

@user_private_router.message(Command('menu'))
async def menu_cmd(message: types.Message):
    await message.answer("Меню: \n1. /start \n2. /menu \n3. /help \n4. /commands \n5. /echo \n6. /age \n7. /name")

@user_private_router.message(Command('command', 'commands', 'help'))
async def help_cmd(message: types.Message):
    await message.answer("Ось всі наразі доступні команди: \n1. /start \n2. /menu \n3. /help \n4. /commands \n5. /echo \n6. /age \n7. /name")

@user_private_router.message(Command('age'))
async def echo_cmd(message: types.Message):
    await message.answer(f"Нажаль ця функція наразі не доступна.")

@user_private_router.message(Command('name'))
async def echo_cmd(message: types.Message):
    await message.answer(f"{Hello} Твоє ім'я: {message.from_user.full_name}!")

@user_private_router.message(Command('echo'))
async def echo_cmd(message: types.Message):
    await message.answer(f"Ви сказали: {message.text}")

@user_private_router.message()
async def echo(message: types.Message):
    text = message.text
    if text in["Hi", "hi", "Hello", "hello", "Привіт", "Здоровенькі були", "привіт", "здоровенькі були"]:
        await message.answer(f"{Hello} {message.from_user.full_name}!")
    elif text in ["goodbye", "Goodbye", "bye", "Bye", "Прощавай", "До зустрічі", "прощавай", "до зустрічі"]:
        await message.answer(f"{Bye} {message.from_user.full_name}!")
    else:
        await message.answer(f"Sorry {message.from_user.full_name}... But I don't understand you :(")