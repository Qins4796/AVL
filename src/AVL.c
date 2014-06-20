#include "AVL.h"
#include "Rotation.h"
#include <stdio.h>

Node *avlAdd(Node *root , Node *nodeToAdd){
	int temp=0;
	if(root == NULL) root = nodeToAdd;
	
	else if (nodeToAdd->data < root->data){ // added left
		
		if(root->leftChild == NULL){
		root->leftChild = avlAdd(root->leftChild,nodeToAdd);
		root->balance += -1;
		}
		else{
		temp = root->leftChild->balance;
		root->leftChild = avlAdd(root->leftChild,nodeToAdd);
		if(root->leftChild->balance!=0 && (root->leftChild->balance - temp) !=0){root->balance += -1;}
		}
		
		if(root->balance == -2){
			if(root->leftChild->balance <= 0){root = rightRotate(root);
			//printf("Rotate Right\n");
			}
			else{root = doubleRightRotate(root);
			//printf("Rotate Right 2 times\n");
			}
		}
	}
	
	else if (nodeToAdd->data > root->data){ //added right
		
		if(root->rightChild == NULL){
		root->rightChild = avlAdd(root->rightChild,nodeToAdd);
		root->balance += 1;
		}
		else{
		temp = root->rightChild->balance;
		root->rightChild = avlAdd(root->rightChild,nodeToAdd);
		if(root->rightChild->balance!=0 && (root->rightChild->balance - temp) !=0){root->balance += 1;}
		}
		
		if(root->balance == 2){
			if(root->rightChild->balance >= 0){root = leftRotate(root);
			//printf("Rotate Left\n");
			}
			else{root = doubleLeftRotate(root);
			//printf("Rotate Left 2 times\n");
			}
		}
	}
	
	else{printf("ZXC");}

	
	return root;
}

Node *avlRemove(Node **ptrToRoot , Node *nodeToRemove){
	
	// (*ptrToRoot)->rightChild = NULL;
	// nodeToRemove =(*ptrToRoot)->rightChild;
	*ptrToRoot = NULL;
	return nodeToRemove;
}


Node *avlGetReplacer(Node **ptrToRoot){
	Node *rootNode = *ptrToRoot, *replace = *ptrToRoot;
	
	if(rootNode->rightChild != NULL){
		replace = avlGetReplacer( &rootNode->rightChild);
		if(rootNode->rightChild->leftChild != NULL){
			rootNode->rightChild = rootNode->rightChild->leftChild;
      rootNode->balance--;
		}
		else{
			rootNode->rightChild = NULL;
      rootNode->balance--;
      }
	}
  
  if(rootNode->balance == -2){
			if(rootNode->leftChild->balance <= 0){rootNode = rightRotate(rootNode);
			}
			else{rootNode = doubleRightRotate(rootNode);
			}
		}
  else if(rootNode->balance == 2){
			if(rootNode->rightChild->balance >= 0){rootNode = leftRotate(rootNode);
			}
			else{rootNode = doubleLeftRotate(rootNode);
			}
		}
	return replace;
		
	// if((*ptrToRoot)->rightChild !=NULL){
		// *ptrToRoot = avlGetReplacer(&(*ptrToRoot)->rightChild);
		// return *ptrToRoot;
	// }
	// else return *ptrToRoot;
}

Node *avlRemoveX(Node *root , Node *nodeToRemove){return  NULL;}
Node *avlRemoveRootName(Node *root){}