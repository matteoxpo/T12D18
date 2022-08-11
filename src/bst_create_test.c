#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bst.h"

void test_init(int val);
void test_insert(int count, int testNum, int r, ...);
void test_traverse(int count, int testNum, int r, ...);
int main() {
#ifdef QUEST3
  int val1 = 42;
  int val2 = 13;
  int val3 = -1;
  test_init(val1);
  test_init(val2);
  test_init(val3);
#elif QUEST4
  srand(time(NULL));
  for (int i = 0; i < 3; i++) {
    test_insert(6, i + 1, rand() % 100, rand() % 100, rand() % 100,
                rand() % 100, rand() % 100, rand() % 100, rand() % 100);
    printf(
        "\n\n-----------------------------------------------END OF TEST "
        "#%d\n\n",
        i + 1);
  }

#elif QUEST5
  srand(time(NULL));
  for (int i = 0; i < 3; i++) {
    test_traverse(6, i + 1, rand() % 100, rand() % 100, rand() % 100,
                  rand() % 100, rand() % 100, rand() % 100, rand() % 100);
    printf(
        "\n\n-----------------------------------------------END OF TEST "
        "#%d\n\n",
        i + 1);
  }
#endif
  return 0;
}

void test_init(int val) {
  struct t_btree *root = bstree_create_node(val);
  printf("TEST1 - creatin bin tree search - pushing 1st elemet\n");
  printf("pushing %d in tree\n", val);
  Print(root, 0);
  if (root->val == val) {
    printf("SUCCES\n");
    printf("%d == %d\n", root->val, val);
  } else {
    printf("FAIL\n");
    printf("%d != %d\n", root->val, val);
  }

  printf("TEST2 - checking left and right child for null pointer\n");
  if (root->right == NULL && root->left == NULL) {
    printf("SUCCES\n");
    printf("root->left == root->right == NULL\n");
  } else {
    printf("FAIL\n");
    printf("root->left != NULL && root->right != NULL\n");
  }
  destroyer(root);
}

void test_insert(int count, int testNum, int r, ...) {
  printf("TEST%d - pushing elemets in tree and comparing with your data\n",
         testNum);
  va_list ptr;
  va_start(ptr, r);
  struct t_btree *root = bstree_create_node(r);
  int rootChild;
  int el;
  printf("Input: ");
  printf("%d ", r);
  for (int i = 0; i < count && ptr != NULL; i++) {
    el = va_arg(ptr, int);
    if (i == 0 && el != root->val) rootChild = el;
    printf("%d ", el);
    bstree_insert(&root, el, cmpf);
  }
  printf("\n");
  va_end(ptr);
  if (root->val > rootChild) {
    if (root->left->val == rootChild) {
      printf("SUCCES\n");
      printf("Left child %d == %d next input el after root el\n",
             root->left->val, rootChild);
    } else {
      printf("Left child %d != %d next input el after root el\n",
             root->left->val, rootChild);
      printf("%d != %d\n", root->left->val, rootChild);
    }
  } else if (root->val < el) {
    if (root->right->val == rootChild) {
      printf("SUCCES\n");
      printf("Left child %d == %d next input el after root el\n",
             root->right->val, rootChild);
    } else {
      printf("Left child %d != %d next input el after root el\n",
             root->right->val, rootChild);
      printf("%d != %d\n", root->left->val, rootChild);
    }
  } else if (root->val == rootChild) {
    printf("NONE\n");
    printf(
        "Cant answer, because el == root == %d\n"
        "Element wasnt pushed in tree\n",
        el);
  }
  printf("Tree to compare with your data:\n");
  Print(root, 0);
  destroyer(root);
}

void test_traverse(int count, int testNum, int r, ...) {
  printf("TEST%d - pushing elemets in tree and comparing with your data\n",
         testNum);
  va_list ptr;
  va_start(ptr, r);
  struct t_btree *root = bstree_create_node(r);
  int el;
  printf("Input: ");
  printf("%d ", r);
  for (int i = 0; i < count && ptr != NULL; i++) {
    el = va_arg(ptr, int);
    printf("%d ", el);
    bstree_insert(&root, el, cmpf);
  }
  printf("\n");
  va_end(ptr);
  printf("\nTEST%d-----------PREFIX-----------------\n", testNum);
  bstree_apply_prefix(root, applyf);
  printf("\nTEST%d-----------PREFIX-----------------\n", testNum);
  printf("\n\nTEST%d-----------POSTFIX-----------------\n", testNum);
  bstree_apply_postfix(root, applyf);
  printf("\nTEST%d-----------POSTFIX-----------------\n", testNum);

  printf("\n\nTEST%d-----------INFIX-----------------\n", testNum);
  bstree_apply_infix(root, applyf);
  printf("\nTEST%d-----------INFIX-----------------\n", testNum);
  printf("Tree to compare with your data:\n");
  Print(root, 0);
  destroyer(root);
}
