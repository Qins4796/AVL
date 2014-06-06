#include "Rotation.h"
#include <stdio.h>

int getHeight(Node *parent){
  int left=0,right=0;

  if(parent->leftChild == NULL && parent->rightChild == NULL) return 1;
  else if(parent->leftChild == NULL){right = getHeight(parent->rightChild);}
  else if(parent->rightChild == NULL){left = getHeight(parent->leftChild);} 
  else{
    left = getHeight(parent->leftChild);
    right = getHeight(parent->rightChild);
    }
    if(left >= right) return left+1;
    else return right+1;
}

// int getRank(Node *parent){
  // int left=0, right = 0;
  // if(parent->leftChild ==NULL && parent->rightChild == NULL) return parent->rank = 0;
  // else if (parent->leftChild->leftChild ==NULL && parent->leftChild->rightChild==NULL \
   // &&parent->rightChild->leftChild ==NULL && parent->rightChild->rightChild ==NULL) {
  // return parent->rightChild->rank = 0, parent->leftChild->rank = 0;
  // }
// }

Node *rightRotate(Node *parent){
  Node *Parent = parent->leftChild;
  
  if(Parent->rightChild!=NULL) parent->leftChild = Parent->rightChild;
  
  Parent->rightChild = parent;
  //getRank(parent);
  
  Parent->rank += 1;
  Parent->rightChild->rank += 2;
  
  return Parent;
}
Node *leftRotate(Node *parent){
  Node *Parent = parent->rightChild;
  
  if(Parent->leftChild!=NULL) parent->rightChild = Parent->leftChild;
  
  Parent->leftChild = parent;
  
  Parent->rank += -1;
  Parent->leftChild->rank += -2;
  
  return Parent;
}

Node *doubleRightRotate(Node *parent){
  Node *Parent = parent->leftChild->rightChild;
  
  //if(Parent->rightChild!=NULL) parent->leftChild = Parent->rightChild;
  
  Parent->rightChild = parent;
  Parent->leftChild = parent->leftChild;
  //parent->leftChild = Parent;
  
  //Parent = rightRotate(parent);
  
  Parent->leftChild->rank += -1;
  Parent->rightChild->rank += 2;
  return Parent;
}
Node *doubleLeftRotate(Node *parent){
  Node *Parent = parent->rightChild->leftChild;
  
  Parent->leftChild = parent;
  Parent->rightChild = parent->rightChild;
  
  Parent->rightChild->rank += 1;
  Parent->leftChild->rank += -2;
  return Parent;
}

Node *tree(Node *parent){
  Node *Parent = parent->leftChild;
  
  Parent->leftChild = parent->leftChild->leftChild;
  Parent->rightChild = parent;
  
  Parent->leftChild->leftChild = parent->leftChild->leftChild->leftChild;
  Parent->rightChild->leftChild = parent->leftChild->rightChild;
  Parent->rightChild->rightChild = parent->rightChild;
  
  //printf("Parent->rightChild->rightChild  %d\n",Parent->rightChild->rightChild);
  
  Parent->rank = 2;
  
  Parent->leftChild->rank = 1;
  Parent->rightChild->rank = 1;
  
  Parent->leftChild->leftChild = 0;
  Parent->rightChild->leftChild = 0;
  Parent->rightChild->rightChild = 0;
  
  return Parent;
}
