#pragma once

// Структура для хранения динамически расширяющейся строки
struct DynString {
  int capacity;  // текущей размер выделенной области памяти
  int length;  // текущая длина
  char* data;  // адрес начала массива символов
};

// Инициализирует структуру пустой строкой
void DynStringInit(struct DynString* s);

// Освобождает всю динамическую память
void DynStringFree(struct DynString* s);

// Очищает строку (делает пустой)
void DynStringClear(struct DynString* s);

// Добавляет один символ в конец строки
void DynStringAdd(struct DynString* s, char c);

// Возвращает нуль терминированную (с \0 на конце) строку
// Важно, что результат работы функции нужно будет освобождать командой free
char* DynStringGet(const struct DynString* s);
