from string import punctuation
from aiogram import Router, types
from filters.chat_types import ChatTypeFilter

user_group_router = Router()
user_group_router.message.filter(ChatTypeFilter(['group','supergroup']))

blocked_words={'blet', 'cyka', 'penis'}
def clean_chat(text:str):
    return text.translate(str.maketrans('','',punctuation)).lower()


@user_group_router.message()
@user_group_router.edited_message()
async def group_message(message: types.Message):
    if blocked_words.intersection(message.text.lower().split()):
        await message.reply(clean_chat(message.text))
        await message.answer(f"{message.from_user.full_name}, keep calm in the chat!")
    else:
        await message.reply(f"Hello {message.from_user.full_name}, {message.text}")