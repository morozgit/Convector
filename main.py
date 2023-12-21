import ctypes
import os

import telebot
from dotenv import find_dotenv, load_dotenv

load_dotenv(find_dotenv())
tg_token = os.environ.get("TG_TOKEN")
bot = telebot.TeleBot(tg_token)
chat_id = os.environ.get("TG_CHAT_ID")
user_states = {}

convector_cpp = ctypes.CDLL('./libcon.so')
convector_cpp.Convector_new.restype = ctypes.c_void_p

convector = convector_cpp.Convector_new()
convector_cpp.Get_val_str.restype = ctypes.c_char_p
convector_cpp.Get_val_str.argtypes = [ctypes.c_void_p]

convector_cpp.toBinary_int.restype = ctypes.c_char_p
convector_cpp.toBinary_int.argtypes = [ctypes.c_void_p, ctypes.c_int]

@bot.message_handler(commands=['start'])
def start_message(message):
    bot.send_message(message.chat.id, 'Привет введи число')
    user_states[message.from_user.id] = 'Hi'

@bot.message_handler(func=lambda message: True)
def discuss_with_bot(message):
    if message.text.isnumeric():
        user_id = message.from_user.id
        if user_id in user_states:
            current_state = user_states[user_id]
            if current_state == 'Hi':
                convector_cpp.toBinary_int(convector, int(message.text))
                bot.send_message(message.chat.id, convector_cpp.Get_val_str(convector))
    else:
        bot.send_message(message.chat.id, 'Надо же число ну')


bot.infinity_polling()
print('Удаляем класс')
convector_cpp.Convector_del.argtypes = [ctypes.c_void_p]
convector_cpp.Convector_del(convector)
