#include "bst.h"

#include <stdio.h>

t_btree *bstree_create_node(int item) {
  struct t_btree *el;
  el->val = item;
  el->l = NULL;
  el->r = NULL;
}