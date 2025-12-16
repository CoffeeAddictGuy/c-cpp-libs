#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} MinHeap;

MinHeap *heap_init(size_t capacity);
void heap_insert(MinHeap *heap, int value);
void heapify_up(MinHeap *heap, size_t index);
void heap_print(MinHeap *heap);
