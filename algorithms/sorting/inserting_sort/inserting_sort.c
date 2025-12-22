#include "inserting_sort.h"

void inserting_sort(int *array, size_t size) {
  for (size_t i = 1; i < size; i++) {
    int x = array[i];
    int j = i;
    while (j > 0 && array[j - 1] > x) {
      array[j] = array[j - 1];
      j = j - 1;
    }
    array[j] = x;
  }
}

void array_print(int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (i != size - 1) {
      printf("%d -> ", array[i]);
    } else {
      printf("%d\n", array[i]);
    }
  }
}