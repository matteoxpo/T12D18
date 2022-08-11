#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

void test_init(int val) {
  struct t_btree *root = bstree_create_node(val);
  if (root->val == val)
    printf("SUCCES\n");
  else
    printf("FAIL\n");

  if (root->right == NULL)
    printf("SUCCES\n");
  else
    printf("FAIL\n");

  if (root->left == NULL)
    printf("SUCCES\n");
  else
    printf("FAIL\n");
}

int main() {
#ifdef QUEST3
  int val1 = 42;
  int val2 = 13;
  int val3 = -1;
  test_init(val1);
  test_init(val2);
  test_init(val3);
#endif
  return 0;
}
