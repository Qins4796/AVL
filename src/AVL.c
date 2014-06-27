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
	Node *root = *ptrToRoot, temp;
  Node *replace;

  if(*ptrToRoot == NULL || nodeToRemove == NULL )return NULL;
  
  else if (nodeToRemove->data > root->data){
    
    nodeToRemove = avlRemove(&root->rightChild,nodeToRemove);
    
    if(root->rightChild != NULL){
      if(root->rightChild->balance == 0) root->balance += -1;
    }
    else{
      if(nodeToRemove != NULL) root->balance += -1;
    }
    
    // root->balance += -1;
  }
  
  else if (nodeToRemove->data < root->data){
  
    if(root->leftChild != NULL){
      temp.leftChild = root->leftChild->leftChild;
      temp.rightChild = root->leftChild->rightChild;
      temp.balance = root->balance;
    }
    
    nodeToRemove = avlRemove(&root->leftChild,nodeToRemove);
    
    // if(root->leftChild == NULL && root->rightChild == NULL) root->balance = 0;
    // else if(root->leftChild != NULL && root->rightChild == NULL) root->balance--;
    // else if(root->leftChild == NULL && root->rightChild != NULL) root->balance++;
    // else{
    // root = avlGetReplacer(&root->leftChild);
    // }
    
    if(root->leftChild != NULL){
      if(root->leftChild->balance == 0) root->balance += 1;
    }
    else{
      if(nodeToRemove != NULL) root->balance += 1;
    }
    
    // root->balance += 1;
  }
  else if (nodeToRemove->data == root->data){
  *ptrToRoot = NULL;
  return root;
  }
  
  if(root->balance == -2){
			if(root->leftChild->balance <= 0){root = rightRotate(root);
			}
			else{root = doubleRightRotate(root);
			}
		}
  else if(root->balance == 2){
			if(root->rightChild->balance >= 0){root = leftRotate(root);
			}
			else{root = doubleLeftRotate(root);
			}
		}
  
	return nodeToRemove;
}


Node *avlGetReplacer(Node **ptrToRoot){
	Node *rootNode = *ptrToRoot, *replace;

	if(rootNode->rightChild != NULL){
    
		replace = avlGetReplacer( &rootNode->rightChild);
    
		// if(rootNode->rightChild->leftChild != NULL){
			// rootNode->rightChild = rootNode->rightChild->leftChild;
      // rootNode->balance--;
		// }
		// else{
			// rootNode->rightChild = NULL;
      // rootNode->balance--;
      // }
    
    if(rootNode->rightChild == NULL){
      rootNode->balance--;
      // printf("- before\n");
    }
    else {
      if(rootNode->rightChild->balance ==0)rootNode->balance--;
      // printf("- after\n");
    }
	}
  else{
  replace = *ptrToRoot;
  if(rootNode->leftChild != NULL){
			*ptrToRoot = rootNode->leftChild;
		}
		else{
			*ptrToRoot = NULL;
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
	
}

Node *avlRemoveRootName(Node *root){}


Node *avlRemoveX(Node *root , Node *nodeToRemove){return  NULL;}