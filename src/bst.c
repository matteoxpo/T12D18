#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct t_btree *bstree_create_node(int item) {
  struct t_btree *el = malloc(sizeof(struct t_btree));
  el->val = item;
  el->left = NULL;
  el->right = NULL;
  return el;
}

void Print(struct t_btree *t, int space) {
  if (t == NULL) {
    if (space == 0) printf("Tree is empty\n");
    return;
  }
  Print(t->right, space + 3);
  for (int i = 0; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", t->val);
  Print(t->left, space + 3);
}

void bstree_insert(struct t_btree **tree, int item, int (*cmpf)(int, int)) {
  if (*tree == NULL) {
    *tree = bstree_create_node(item);
  } else {
    int decision = cmpf(item, (*tree)->val);
    switch (decision) {
      case 1:
        bstree_insert(&(*tree)->right, item, cmpf);
        break;
      case -1:
        bstree_insert(&(*tree)->left, item, cmpf);
        break;
      case 0:
        printf("\nElement %d is already in tree", item);
        break;
      default:
        printf("\nI don't know what to do lol");
        break;
    }
  }
}

int cmpf(int val1, int val2) {
  int res;
  if (val1 < val2) res = -1;
  if (val1 > val2) res = 1;
  if (val1 == val2) res = 0;
  return res;
}

void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int)) {
  if (root == NULL) return;
  if (root->val) (*applyf)(root->val);
  bstree_apply_prefix(root->right, (*applyf));
  bstree_apply_prefix(root->left, (*applyf));
}
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int)) {
  if (root == NULL) return;
  bstree_apply_postfix(root->left, (*applyf));
  bstree_apply_postfix(root->right, (*applyf));
  if (root->val) (*applyf)(root->val);
}
void bstree_apply_infix(struct t_btree *root, void (*applyf)(int)) {
  if (root == NULL) return;
  bstree_apply_infix(root->left, (*applyf));
  if (root->val) (*applyf)(root->val);
  bstree_apply_infix(root->right, (*applyf));
}
void applyf(int val) { printf("%d\n", val); }

void destroyer(struct t_btree *root) {
  if (root != NULL) {
    destroyer(root->left);
    destroyer(root->right);
    free(root);
  }
}
