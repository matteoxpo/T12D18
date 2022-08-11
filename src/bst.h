#ifndef BST_H
#define BST_H

struct t_btree {
  int val;
  struct t_btree *left;
  struct t_btree *right;
};

struct t_btree *bstree_create_node(int item);
void Print(struct t_btree *t, int space);
void bstree_insert(struct t_btree **tree, int item, int (*cmpf)(int, int));
int cmpf(int val1, int val2);

void bstree_apply_prefix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(struct t_btree *root, void (*applyf)(int));
void bstree_apply_infix(struct t_btree *root, void (*applyf)(int));
void applyf(int val);
void destroyer(struct t_btree *root);

#endif
