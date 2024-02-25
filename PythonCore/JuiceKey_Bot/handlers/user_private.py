import random
from aiogram import types, Router, F
from aiogram.filters import CommandStart, Command

from filters.chat_types import ChatTypeFilter

user_private_router = Router()
user_private_router.message.filter(ChatTypeFilter(['private']))

Hello = random.choice(["Привіт!", "Здоровенькі були!", "Як ся маєш!"])
Bye = random.choice(["Бувай!", "Прощавай!", "До зустрічі!"])

@user_private_router.message(CommandStart())
async def start_cmd(message: types.Message):
    await message.answer_photo(
        photo='https://s.tmimgcdn.com/scr/800x500/271000/privit-ukrainskou-movou-napivploski-kolorovi-vektorni-splivaucu-pidkazku_271055-original.jpg',
        caption=f"{Hello} {message.from_user.full_name}! \n\n Тебе вітає інтернет магазин “JuiceKey Shop”!\n\nМи один з перших онлайн магазинів з України на тематику GTA 5. Ми пропонуємо ключі від ігор рокстар, послуги разбану та прокачки. Наша мета - допомогти вам отримати максимальне задоволення від гри!\n\nОсь наразі доступні команди:\n\n - /about\n - /gta5 \n - /rdr2"
        )

@user_private_router.message(Command('about'))
async def menu_cmd(message: types.Message):
    await message.answer_photo(
        photo='https://i.postimg.cc/xTvzC3BY/photo-2024-02-23-13-19-26.jpg',
        caption=f"GTA 5: Ключі та Прокачка\n\nJuiceKey Shop - це один з перших онлайн магазинів з України на тематику GTA 5. Ми пропонуємо ключі від ігор рокстар, послуги разбану та прокачки. Наша мета - допомогти вам отримати максимальне задоволення від гри!\n\nЧому вибрати нас?\n\n - Доступні ціни: Наші послуги починаються всього від 50 грн!\n\n - Швидкість: Ми працюємо швидко, щоб ви могли якнайшвидше почали грати.\n\n - Надійність: Ми приймаємо оплату через Монобанк та Приватбанк, що гарантує безпеку вашого платежу.\n\n - Гарантія: Ми надаємо 6-місячну гарантію на всі наші послуги.\n\n - Підтримка: Наша команда підтримки доступна 12 годин на добу, щоб допомогти вам з будь-якими питаннями.\n\nОсь наразі доступні команди:\n\n - /about\n - /gta5\n - /rdr2"
        )

@user_private_router.message(Command('gta5'))
async def help_cmd(message: types.Message):
    await message.answer_photo(
        photo='https://i.postimg.cc/dQpDcsmz/photo-2024-02-23-13-19-32.jpg',
        caption="Отримайте доступ до GTA 5 зараз!\n\nХочеш грати в GTA 5, але не маєш ключа? Або ти був заблокований? Ми пропонуємо ключі та послуги розбану!\n\n - 300 грн\n\nНе пропусти свій шанс почати свою гру!"
        )
    await message.answer("Можливо ти ще хочеш прокачати свій GTA ONLINE аккаунт? /boost")

@user_private_router.message(Command('boost'))
async def help_cmd(message: types.Message):
    await message.answer_photo(
        photo='https://i.postimg.cc/3wf0ygmw/photo-2024-02-23-13-19-34.jpg',
        caption="Прокачай свій GTA ONLINE аккаунт!\n\nХочеш стати кращим в GTA ONLINE? Ми пропонуємо послуги прокачки за наступними тарифами:\n\n - 120 рівень: 50 грн\n - 1 млн доларів GTA: 50 грн \n\n - 120 рівень + 1.5 млн доларів GTA: 100 грн\n - 120 рівень + 5 млн доларів GTA: 150 грн\n - 120 рівень + 10 млн доларів GTA: 200 грн\n - 120 рівень + 100 млн доларів GTA: 500 грн\n\nПокращи свій геймплей вже сьогодні!"
        )

@user_private_router.message(Command('rdr2'))
async def echo_cmd(message: types.Message):
    await message.answer_photo(
        photo='https://i.postimg.cc/65V7Vsng/photo-2024-02-23-13-19-39.jpg',
        caption=f"Отримайте доступ до RDR 2 зараз!\n\nХочеш грати в RDR 2, але не маєш ключа? Або ти був заблокований? Ми пропонуємо ключі та послуги розбану!\n\n - 350 грн\n\nНе пропусти свій шанс долучитися до пригод у Дикому Заході!"
        )

@user_private_router.message()
async def echo(message: types.Message):
    text = message.text
    if text in["Hi", "hi", "Hello", "hello", "Привіт", "Здоровенькі були", "привіт", "здоровенькі були"]:
        await message.answer(f"{Hello} {message.from_user.full_name}!")
    elif text in ["goodbye", "Goodbye", "bye", "Bye", "Прощавай", "До зустрічі", "прощавай", "до зустрічі"]:
        await message.answer(f"{Bye} {message.from_user.full_name}!")
    else:
        await message.answer(f"Вибач {message.from_user.full_name}... Але я не розумію тебе :(")