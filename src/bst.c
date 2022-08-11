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
  if (t == NULL) return;

  Print(t->right, space + 3);
  for (int i = 0; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", t->val);
  Print(t->left, space + 3);
}