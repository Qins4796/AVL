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
Node *avlRemove(Node *root , Node *nodeToRemove);
Node *avlRemoveRootName(Node *root);

#endif // AVL_H
