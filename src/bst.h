#ifndef BST_H
#define BST_H

struct t_btree {
  int val;
  struct t_btree *left;
  struct t_btree *right;
};

struct t_btree *bstree_create_node(int item);
void Print(struct t_btree *t, int space);

#endif
