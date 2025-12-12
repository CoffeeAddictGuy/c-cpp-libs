#include "bst.h"
#include <stddef.h>
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

int bst_height(BST *bst) {
  if (bst == NULL) {
    return 0;
  }
  int left_height = bst_height(bst->left);
  int right_height = bst_height(bst->right);

  return 1 + (left_height > right_height ? left_height : right_height);
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

void bst_preorder(BST *bst) {
  if (bst != NULL) {
    printf("%d\n", bst->value);
    bst_preorder(bst->left);
    bst_preorder(bst->right);
  }
}

void bst_postorder(BST *bst) {
  if (bst != NULL) {
    bst_postorder(bst->left);
    bst_postorder(bst->right);
    printf("%d\n", bst->value);
  }
}

void bst_free(BST *bst) { free(bst); }