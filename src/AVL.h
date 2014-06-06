#ifndef AVL_H
#define AVL_H

typedef struct Node Node;

struct Node{
	int rank;
	struct Node *leftChild;
  struct Node *rightChild;
  int data;
};

#endif // AVL_H
