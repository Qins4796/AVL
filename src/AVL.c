#include "AVL.h"
#include "Rotation.h"
#include <stdio.h>

Node *avlAdd(Node *root , Node *nodeToAdd){
	
	if(root == NULL) root = nodeToAdd;

	else if (nodeToAdd->data < root->data){
		root->balance += -1;
		root->leftChild = avlAdd(root->leftChild,nodeToAdd);
		if(root->balance <= -2){ root = rightRotate(root);}
	}
	
	else if (nodeToAdd->data > root->data) { 
		root->balance += 1;
		root->rightChild = avlAdd(root->rightChild,nodeToAdd); 
		if(root->balance >= 2) { root = leftRotate(root);}	
	}
	else{printf("ZXC");}
	
	return root;

}

Node *avlRemove(Node *root , Node *nodeToRemove){}
Node *avlRemoveRootName(Node *root){}