#ifndef AVL_H
#define AVL_H

typedef struct Node Node;

struct Node{
	int balance;
	struct Node *leftChild;
  struct Node *rightChild;
  int data;
};

Node *avlAdd(Node *root , Node *nodeToAdd);
Node *avlRemoveX(Node *root , Node *nodeToRemove);
Node *avlRemove(Node **ptrToRoot , Node *nodeToRemove);
Node *avlGetReplacer(Node **ptrToRoot);
Node *avlRemoveRootName(Node *root);

#endif // AVL_H
