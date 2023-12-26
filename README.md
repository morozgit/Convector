# Перевод в разные системы счисления.

## Установка Python

Установите [python3](https://realpython.com/installing-python/).

## Установка Компилятора
[Windows](https://metanit.com/cpp/tutorial/1.2.php),
[Ubuntu](https://andreyex.ru/ubuntu/kak-ustanovit-g-v-ubuntu/)

## Репозиторий
Клонируйте репозиторий в удобную папку.

## Виртуальное окружение
В терминале перейдите в папку с репозиторием.

### Создание виртуального окружения
```bush 
python3 -m venv venv
```

### Активация виртуального окружения Linux.

```bush
source venv/bin/activate
```

### Активация виртуального окружения Windows.

```bush
venv\Scripts\activate
```

### Установка библиотек.

```bush 
pip3 install -r requirements.txt
```

#### Запись Telegram токена.
```bush
echo TG_TOKEN=ваш токен > .env
```

## Запуск

### Скомпилировать С++

Из директории с проектом выполните команду.
```bush
g++ -fPIC -shared -o libcon.so Convector.cpp
```
### Запуск ботов
Из директории с проектом выполните команды.
```bush
python3 main.py
```
