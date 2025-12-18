#include "ht_oa.h"

unsigned int hash_func(const char *key, size_t table_size) {
  unsigned long hash = 5381;
  int i = 0;
  while (key[i] != '\0') {
    hash = (hash << 5) + hash + key[i];
    i++;
  }
  return hash % table_size;
}

HashTable *ht_init(size_t capacity) {
  HashTable *n_ht = (HashTable *)malloc(sizeof(HashTable));
  if (n_ht == NULL) {
    return NULL;
  }

  HashItem *n_hi = (HashItem *)calloc(capacity, sizeof(HashItem));
  if (n_hi == NULL) {
    free(n_ht);
    return NULL;
  }

  n_ht->capacity = capacity;
  n_ht->size = 0;
  n_ht->items = n_hi;

  return n_ht;
}

HashTable *ht_insert(HashTable *ht, char *key, int value) {
  if (ht == NULL) {
    return NULL;
  }

  unsigned int index = hash_func(key, ht->capacity);
  HashItem *items = ht->items;
  // is not empty
  if (items[index].state == EMPTY || items[index].state == DELETE) {
    items[index].key = key;
    items[index].value = value;
    items[index].state = OCCUPIED;
  } else if (items[index].state == OCCUPIED) {
    if (strcmp(items[index].key, key) == 0) {
      items[index].value = value;
    }
  }
  return ht;
}