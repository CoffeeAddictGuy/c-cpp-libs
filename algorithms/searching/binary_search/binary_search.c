#include "binary_search.h"
#include <stddef.h>

size_t binary_search(int *array, size_t size, int target) {
  size_t left = 0, right = size - 1;
  while (left <= right) {
    size_t mid = left + (right - left) / 2;
    if (array[mid] == target) {
      return mid;
    }
    if (target > array[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
}
