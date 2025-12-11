#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BST *bst_init(int value) {
  BST *bst = (BST *)malloc(sizeof(BST));
  if (bst == NULL) {
    return NULL;
  }
  bst->value = value;
  bst->left = NULL;
  bst->right = NULL;
  return bst;
}

BST *bst_insert(BST *bst, int value) {

  if (bst == NULL) {
    return bst_init(value);
  }
  if (value < bst->value) {
    bst->left = bst_insert(bst->left, value);
  } else if (value > bst->value) {
    bst->right = bst_insert(bst->right, value);
  }
  return bst;
}

BST *bst_search(BST *bst, int value) {
  if (bst == NULL) {
    return NULL;
  }
  if (value > bst->value) {
    return bst_search(bst->right, value);
  } else if (value < bst->value) {
    return bst_search(bst->left, value);
  } else {
    return bst;
  }
}

int bst_min(BST *bst) {
  if (bst->left == NULL) {
    return bst->value;
  }
  return bst_min(bst->left);
}

int bst_max(BST *bst) {
  if (bst->right == NULL) {
    return bst->value;
  }
  return bst_max(bst->right);
}

void bst_inorder(BST *bst) {
  if (bst != NULL) {
    bst_inorder(bst->left);
    printf("%d\n", bst->value);
    bst_inorder(bst->right);
  }
}

void bst_free(BST *bst) { free(bst); }