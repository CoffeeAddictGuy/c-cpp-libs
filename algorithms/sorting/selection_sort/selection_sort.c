#include "selection_sort.h"

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void selection_sort(int *array, size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    size_t min_index = i;
    for (size_t j = i + 1; j < size; j++) {
      if (array[min_index] > array[j]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      swap(&array[min_index], &array[i]);
    }
  }
}

void array_print(int *array, size_t size) {
  printf("[");
  for (size_t i = 0; i < size; i++) {
    if (i != size - 1) {
      printf("%d -> ", array[i]);
    } else {
      printf("%d]\n", array[i]);
    }
  }
}

bool is_sorted(int *array, size_t size) {
  for (size_t i = 1; i < size; i++) {
    if (array[i] < array[i - 1]) {
      return false;
    }
  }
  return true;
}