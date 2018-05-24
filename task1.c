// http://informatics.mccme.ru/mod/statements/view.php?id=599 самая простая задачка
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node
{
  int value;
  struct Node * left;
  struct Node * right;
};

int maxx(int a, int b) {
  if (a > b) {
    return a;
  }
  else {
    return b;
  }
}

struct Node createNodeEmpty()
{
  struct Node node;
  node.left = node.right = NULL;
  return node;
}

struct Node createNode(int val)
{
  struct Node node = createNodeEmpty();
  node.value = val;
  return node;
}

void addNode(struct Node ** root, int val)
{
  if (!(*root)) {
    *root = (struct Node *)malloc(sizeof(struct Node));
    **root = createNode(val);
    return;
  }
  if ((*root)->value > val) {
    addNode(&((*root)->left), val);
  }
  else if ((*root)->value < val) {
    addNode(&((*root)->right), val);
  }
}

void showElem(struct Node node) {
  printf("val: %d\n", node.value);
  if (node.left) {
    printf("left: %d\n", node.left->value);
  }
  else {
    printf("left: NULL\n");
  }
  if (node.right) {
    printf("right: %d\n", node.right->value);
  }
  else {
    printf("right: NULL\n");
  }
  printf("\n");
}

void showTree(struct Node * root) {
  if (root) {
    if (root->left) {
      showTree(root->left);
    }
    showElem(*root);
    if (root->right) {
      showTree(root->right);
    }
  }
}

void deleteTree(struct Node * root) {
  if (root) {
    if (root->left) {
      deleteTree(root->left);
    }
    if (root->right) {
      deleteTree(root->right);
    }
    free(root);
  }
}

int deepTree(struct Node * root) {
  if (root) {
    if (root->left && root->right) {
      return maxx(deepTree(root->left), deepTree(root->right)) + 1;
    }
    else if (root->left) {
      return deepTree(root->left) + 1;
    }
    else if (root->right) {
      return deepTree(root->right) + 1;
    }
    else {
      return 1;
    }
  }
  else {
    return 0;
  }
}

int main() {
  struct Node * root = NULL;
  int a;
  while (true) {
    scanf("%d", &a);
    if (a) {
      addNode(&root, a);
    }
    else {
      break;
    }
  }
  
  //showTree(root);

  printf("%d\n", deepTree(root));
  deleteTree(root);

  //getchar();
  //getchar();
  return 0;
}