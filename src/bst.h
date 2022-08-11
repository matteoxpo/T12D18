#ifndef BST_H
#define BST_H

struct t_btree {
  int el;
  struct t_btree *l;
  struct t_btree *r;
};

t_btree *bstree_create_node(int item);

#endif
