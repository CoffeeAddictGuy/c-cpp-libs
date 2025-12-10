#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int *value;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray *da_init(size_t capacity);
void da_push(DynamicArray *array, int value);
void da_pop(DynamicArray *array);
void da_free(DynamicArray *array);

#endif