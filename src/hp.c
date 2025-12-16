#include "hp.h"

MinHeap *heap_init(size_t capacity) {
  MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
  if (heap == NULL) {
    return NULL;
  }
  int *data = (int *)malloc(sizeof(int) * capacity);
  if (data == NULL) {
    printf("Space cannot be allocated!");
    return NULL;
  }
  heap->data = data;
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void heap_insert(MinHeap *heap, int value) {
  if (heap == NULL) {
    return;
  }
  if (heap->size + 1 >= heap->capacity) {
    int *t = heap->data;
    t = realloc(heap->data, sizeof(int) * (heap->capacity * 2));
    if (t != NULL) {
      heap->data = t;
      heap->data[heap->size] = value;
      heap->size = heap->size + 1;
      heap->capacity = heap->capacity * 2;
    } else {
      int *n = (int *)malloc(sizeof(int) * (heap->capacity * 2));
      memcpy(n, heap->data, heap->capacity);
      free(heap->data);
      heap->data = n;
      heap->data[heap->size] = value;
      heap->size = heap->size + 1;
      heap->capacity = heap->capacity * 2;
    }
  } else {
    heap->data[heap->size] = value;
    heap->size = heap->size + 1;
  }
  heapify_up(heap, heap->size - 1);
}

void heapify_up(MinHeap *heap, size_t index) {
  if (index == 0) {
    return;
  }

  size_t p_index = (index - 1) / 2;
  // printf("p_index - %lld and value - %d\n", p_index, heap->data[index]);
  if (heap->data[p_index] > heap->data[index]) {
    int t = heap->data[p_index];
    heap->data[p_index] = heap->data[index];
    heap->data[index] = t;
    heapify_up(heap, p_index);
  }
}

void heap_print(MinHeap *heap) {
  for (size_t i = 0; i < heap->size; i++) {
    printf("%d ", heap->data[i]);
  }
  printf("\n");
}