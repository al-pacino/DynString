#include <stdio.h>
#include <stdlib.h>

#include "dyn_string.h"

// Компиляция и запуск:
// gcc -Wall main.c dyn_string.c -o dyn_string_example && ./dyn_string_example
// В стандартный поток ввода будет записано:
// Hello
// Hello, World!
// Bye!

int main() {
  // Объявляем переменную типа динамическая строка
  struct DynString s;

  // Инициализируем строку
  DynStringInit(&s);

  // Дописываем в конец строки текст `Hello`
  DynStringAdd(&s, 'H');
  DynStringAdd(&s, 'e');
  DynStringAdd(&s, 'l');
  DynStringAdd(&s, 'l');
  DynStringAdd(&s, 'o');

  // Печатаем строку (если не сделать free, то будет утечка памяти)
  char* c_str = DynStringGet(&s);
  printf("%s\n", c_str);
  free(c_str);

  // Дописываем в конец строки текст `, World!`
  DynStringAdd(&s, ',');
  DynStringAdd(&s, ' ');
  DynStringAdd(&s, 'W');
  DynStringAdd(&s, 'o');
  DynStringAdd(&s, 'r');
  DynStringAdd(&s, 'l');
  DynStringAdd(&s, 'd');
  DynStringAdd(&s, '!');

  // Печатаем строку (если не сделать free, то будет утечка памяти)
  c_str = DynStringGet(&s);
  printf("%s\n", c_str);
  free(c_str);

  // Очищаем строку
  DynStringClear(&s);

  // Дописываем в конец строки текст `Bye!`
  DynStringAdd(&s, 'B');
  DynStringAdd(&s, 'y');
  DynStringAdd(&s, 'e');
  DynStringAdd(&s, '!');

  // Печатаем строку (если не сделать free, то будет утечка памяти)
  c_str = DynStringGet(&s);
  printf("%s\n", c_str);
  free(c_str);

  // Освобождаем память, занятую динамической строкой
  DynStringFree(&s);

  return 0;
}
