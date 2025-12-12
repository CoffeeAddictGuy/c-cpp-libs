
typedef struct BinarySearchTree {
  int value;
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
} BST;

BST *bst_init(int value);
BST *bst_insert(BST *bst, int value);
BST *bst_search(BST *bst, int value);
BST *bst_delete_element(BST *bst, int value); // todo

void bst_inorder(BST *bst);
void bst_preorder(BST *bst);
void bst_postorder(BST *bst);

void bst_height(BST *bst); // todo
int bst_min(BST *bst);
int bst_max(BST *bst);

void bst_free(BST *bst);