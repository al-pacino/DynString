#include "dyn_string.h"

#include <stdlib.h>

void DynStringInit(struct DynString* s) {
  s->capacity = 8;
  s->length = 0;
  s->data = (char*)malloc(s->capacity * sizeof(char));
}

void DynStringFree(struct DynString* s) {
  s->capacity = 0;
  s->length = 0;
  free(s->data); // Здесь обязательно делать только эту инструкцию
  s->data = NULL;
}

void DynStringAdd(struct DynString* s, char c) {
  if (s->length >= s->capacity) {
    s->capacity *= 2;
    char* temp = (char*)malloc(s->capacity * sizeof(char));
    for (int i = 0; i < s->length; ++i) {
      temp[i] = s->data[i];
    }
    free(s->data);
    s->data = temp;
  }
  s->data[s->length++] = c;
}

void DynStringClear(struct DynString* s) {
  s->length = 0;
}

char* DynStringGet(const struct DynString* s) {
  char* result = (char*)malloc((s->length + 1) * sizeof(char));
  for (int i = 0; i < s->length; ++i) {
    result[i] = s->data[i];
  }
  result[s->length] = '\0';
  return result;
}
