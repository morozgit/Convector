import ctypes
import os

from dotenv import find_dotenv, load_dotenv
from telebot import TeleBot, apihelper, types

load_dotenv(find_dotenv())
tg_token = os.environ.get("TG_TOKEN")
bot = TeleBot(tg_token)
chat_id = os.environ.get("TG_CHAT_ID")
user_states = {}
if os.name == 'nt':
    convector_cpp = ctypes.CDLL('./libcon.so', winmode=0)
elif os.name == 'posix':
    convector_cpp = ctypes.CDLL('./libcon.so')
convector_cpp.Convector_new.restype = ctypes.c_void_p

convector = convector_cpp.Convector_new()
# convector_cpp.Get_val_str.restype = ctypes.c_char_p
# convector_cpp.Get_val_str.argtypes = [ctypes.c_void_p]

convector_cpp.toBinary_int.restype = ctypes.c_char_p
convector_cpp.toBinary_int.argtypes = [ctypes.c_void_p, ctypes.c_int]

convector_cpp.toOctal_int.restype = ctypes.c_char_p
convector_cpp.toOctal_int.argtypes = [ctypes.c_void_p, ctypes.c_int]

@bot.message_handler(commands=['start'])
def start_message(message):
    markup = types.InlineKeyboardMarkup()
    binary_button = types.InlineKeyboardButton('2 (Двоичная)', callback_data='binary')
    octal_button = types.InlineKeyboardButton('8 (Восьмеричная)', callback_data='octal')
    markup.add(binary_button)
    markup.add(octal_button)
    bot.send_message(message.chat.id, 'В какую систему счисления перевести?', reply_markup=markup)

@bot.message_handler(func=lambda message: True)
def discuss_with_bot(message):
    if message.text.isnumeric():
        if user_states['choice'] == 'binary_choice':
            bot.send_message(message.chat.id,
                             convector_cpp.toBinary_int(convector,
                                                        int(message.text)))
        elif user_states['choice'] == 'octal_choice':
            bot.send_message(message.chat.id,
                             convector_cpp.toOctal_int(convector,
                                                       int(message.text)))
    else:
        bot.send_message(message.chat.id, 'Надо же число ну')

@bot.callback_query_handler(func=lambda call: call.data == 'binary')
def create_binary(call):
    user_states['choice'] = 'binary_choice'
    bot.send_message(call.message.chat.id, 'Введите число')


@bot.callback_query_handler(func=lambda call: call.data == 'octal')
def create_octal(call):
    user_states['choice'] = 'octal_choice'
    bot.send_message(call.message.chat.id, 'Введите число')


bot.infinity_polling()
print('Удаляем класс')
convector_cpp.Convector_del.argtypes = [ctypes.c_void_p]
convector_cpp.Convector_del(convector)
