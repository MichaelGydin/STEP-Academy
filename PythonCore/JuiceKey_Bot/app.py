import os
import asyncio
from aiogram import Bot, Dispatcher, types
from dotenv import load_dotenv, find_dotenv

from common.bot_cmd_list import private
from handlers.user_private import user_private_router
from handlers.user_group import user_group_router

load_dotenv(find_dotenv())

bot = Bot(token=os.getenv('TOKEN'))

dp = Dispatcher()
dp.include_routers(user_private_router)
dp.include_routers(user_group_router)

async def main():
    await bot.delete_webhook(drop_pending_updates=True)
    await bot.set_my_commands(commands=private, scope=types.BotCommandScopeAllPrivateChats())
    await dp.start_polling(bot)
    
asyncio.run(main())