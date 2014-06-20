#include "unity.h"
#include "AVL.h"
#include "Rotation.h"
#include <stdio.h>
#include "CustomAssert.h"

void setUp(){}
void tearDown(){}

/**
  *        (1) 
  *
  */
void test_avlAdd_for_1st_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = NULL;
  
    root = avlAdd(root,&Node1);
	
	TEST_ASSERT_EQUAL_PTR(&Node1, root);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
}
/**
  *   (1)  
  *     \   
  *     (50) 
  *      
  */
void test_avlAdd_for_2nd_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = NULL;
  
    root = avlAdd(root,&Node1);
	root = avlAdd(root,&Node50);
	
	TEST_ASSERT_EQUAL_PTR(&Node1, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node50.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node50.rightChild);
	
	TEST_ASSERT_EQUAL(1, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	
}
/**
  *   (1)              (50)
  *     \              / \
  *     (50)    =>   (1)  (100)
  *      \
  *      (100)
  */
void test_avlAdd_for_3rd_element(){
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	
	Node *root = NULL;
  
    root = avlAdd(root,&Node1);
	root = avlAdd(root,&Node50);
	root = avlAdd(root,&Node100);
	
	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	
	TEST_ASSERT_EQUAL_PTR(&Node50, root);
	TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
	
	TEST_ASSERT_NOT_NULL(Node50.leftChild);
	TEST_ASSERT_NOT_NULL(Node50.rightChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node100.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node100.rightChild);
	
	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
}
/**     (50)
  *    /   \
  *  (1)   (100)
  *         /
  *       (75)
  *  
  */
void test_avlAdd_for_4th_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	
	Node *root = NULL;
  
    root = avlAdd(root,&Node1);
	root = avlAdd(root,&Node50);
	root = avlAdd(root,&Node100);
	root = avlAdd(root,&Node75);
	
	TEST_ASSERT_EQUAL_PTR(&Node50, root);
	TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->rightChild->leftChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	
	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(1, Node50.balance);
	TEST_ASSERT_EQUAL(-1, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
}
/**	  (50)	
  *   /  \
  * (1)  (100) 
  *       /  \
  *    (75)  (150)
  *  
  */
void test_avlAdd_for_5th_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = NULL;
  
	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n",&Node75);
	// printf("root150 %p\n",&Node150);
	
    root = avlAdd(root,&Node1);
	root = avlAdd(root,&Node50);
	root = avlAdd(root,&Node100);
	root = avlAdd(root,&Node75);
	root = avlAdd(root,&Node150);
	
	TEST_ASSERT_EQUAL_PTR(&Node50, root);
	TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->rightChild->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, Node50.rightChild->rightChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.rightChild);
	
	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(1, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(0, Node150.balance);
}
/**			
  *      (100)
  *      /   \
  *    (50)  (150)
  *    /  \		 \
  *  (1)  (75)   (200)
  */
void test_avlAdd_for_6th_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = NULL;
  
	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n",&Node75);
	// printf("root150 %p\n",&Node150);
	// printf("root200 %p\n",&Node200);
	
    root = avlAdd(root,&Node1);
	root = avlAdd(root,&Node50);
	root = avlAdd(root,&Node100);
	root = avlAdd(root,&Node75);
	root = avlAdd(root,&Node150);
	root = avlAdd(root,&Node200);
	
	TEST_ASSERT_EQUAL_PTR(&Node100, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node1, Node50.leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node200, Node150.rightChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.rightChild);
	
	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(1, Node150.balance);
	TEST_ASSERT_EQUAL(0, Node200.balance);
}
/**			
  *       (100)
  *       /    \
  *    (50)    (150)
  *    /  \	   /   \
  *  (1) (75)(120) (200)
  */
void test_avlAdd_for_7th_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node200 = {.data = 200, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node120 = {.data = 120, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = NULL;
  
	// printf("root1 %p\n",&Node1);
	// printf("root50 %p\n",&Node50);
	// printf("root100 %p\n",&Node100);
	// printf("root70 %p\n",&Node75);
	// printf("root150 %p\n",&Node150);
	// printf("root200 %p\n",&Node200);
	// printf("root120 %p\n",&Node120);
	
    root = avlAdd(root,&Node1);
	root = avlAdd(root,&Node50);
	root = avlAdd(root,&Node100);
	root = avlAdd(root,&Node75);
	root = avlAdd(root,&Node150);
	root = avlAdd(root,&Node200);
	root = avlAdd(root,&Node120);
	
	TEST_ASSERT_EQUAL_PTR(&Node100, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node1, Node50.leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node200, Node150.rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node120, Node150.leftChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node200.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node120.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node120.rightChild);
	
	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(0, Node50.balance);
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(0, Node150.balance);
	TEST_ASSERT_EQUAL(0, Node200.balance);
	
	TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,0,&Node100);
}
 /**          -2
  *         (50)               0  (30) 
  *         /  \                  /  \
  *     1(10) (100)         -1 (10)  (50)
  *       / \           =>     /     /  \
  *     (5) (30) 1        0 (5)   (40) (100)
  *           \        
  *           (40)
  */
void test_avlAdd_for_doubleRightRotate(){
  Node Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node5 = {.data = 5, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node30  = {.data = 30,  .balance = 0, .leftChild = NULL, . rightChild = NULL}; 
  Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node50  = {.data = 50,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node *root = NULL;

  root = avlAdd(root,&Node30);
  root = avlAdd(root,&Node10);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node5);
  root = avlAdd(root,&Node40);
  root = avlAdd(root,&Node100);
  
  // printf("30: %p\n",&Node30);
  // printf("50: %p\n",&Node50);
  // printf("10: %p\n",&Node10);
  // printf("5: %p\n",&Node5);
  // printf("40: %p\n",&Node40);
  // printf("100: %p\n",&Node100);
  
  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node40, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  
  TEST_ASSERT_EQUAL_PTR(NULL, Node5.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node5.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node100.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node100.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node40.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, Node40.rightChild);
  
  TEST_ASSERT_EQUAL(0, Node30.balance);
  TEST_ASSERT_EQUAL(0, Node50.balance);
  TEST_ASSERT_EQUAL(-1, Node10.balance);
  TEST_ASSERT_EQUAL(0, Node5.balance);
  TEST_ASSERT_EQUAL(0, Node40.balance);
  TEST_ASSERT_EQUAL(0, Node100.balance);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node50,0,&Node30);
  TEST_ASSERT_EQUAL_AVL_Node(&Node5,NULL,-1,&Node10);
  TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node5);
 }
 /**           2 
  *         (50)                 (30)
  *         /  \                /   \
  *     (100) (10)-1          (50)  (10) 1 
  *           /  \     =>     /  \    \
  *      -1(30)  (5)      (100) (40)  (5)
  *         / 
  *      (40) 
  */
void test_avlAdd_for_doubleLeftRotate(){
  Node Node40 = {.data = 40, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node5 = {.data = 5, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node30  = {.data = 30,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10  = {.data = 10,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node50  = {.data = 50,  .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node10);
  root = avlAdd(root,&Node30);
  root = avlAdd(root,&Node5);
  root = avlAdd(root,&Node40);
  
  // printf("30: %p\n",&Node30);
  // printf("50: %p\n",&Node50);
  // printf("10: %p\n",&Node10);
  // printf("5: %p\n",&Node5);
  // printf("40: %p\n",&Node40);
  // printf("100: %p\n",&Node100);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node50,0,&Node30);
  TEST_ASSERT_EQUAL_AVL_Node(&Node5,NULL,-1,&Node10);
  TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node5);
  
}
// ====================================================
//					REMOVE AVL
// ====================================================

/**
  *        (1) 
  *
  */
void test_avlRemove_for_1st_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = &Node1;
	Node *temp;
	
    temp = avlRemove(&root,&Node1);
	
	TEST_ASSERT_NULL(root);
	TEST_ASSERT_NOT_NULL(temp);
	
	TEST_ASSERT_EQUAL_PTR(NULL, root);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	
	TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
  *   (1)  
  *     \   
  *     (50) 
  *      
  */
void test_avlRemove_for_2nd_element(){
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 1, .leftChild = NULL, . rightChild = &Node50};
	Node *root = &Node1;
	Node *temp;
	
	temp = avlRemove(&root,&Node50);
	
	//TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_NOT_NULL(temp);
	TEST_ASSERT_NOT_NULL(&Node1);
	
	//TEST_ASSERT_EQUAL_PTR(&Node1, root);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	//TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	
}
/**
  *     (50)  
  *    /   \   
  *  (1)  (100) 
  *      
  */
void test_avlRemove_for_3rd_element(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = &Node1, . rightChild = &Node100};
	Node *root = &Node50;
	Node *temp;
	
	temp = avlRemove(&root,&Node100);
	
	//TEST_ASSERT_NOT_NULL(root);
	TEST_ASSERT_NOT_NULL(temp);
	TEST_ASSERT_NOT_NULL(&Node1);
	TEST_ASSERT_NOT_NULL(&Node50);
	//TEST_ASSERT_NULL(&Node100);
	
	//TEST_ASSERT_EQUAL_PTR(&Node50, root);
	//TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	// TEST_ASSERT_EQUAL_PTR(NULL, root->rightChild);
}
/**     (50)
  *    /    \
  *  (1)   (100)
  *         /
  *       (75)
  *  
  */
void test_avlRemove_for_4th_element(){
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = &Node75, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = &Node1, . rightChild = &Node100};
	Node *root;
	
	//TEST_ASSERT_EQUAL_PTR(&Node50, root);
	// TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
	// TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild);
	// TEST_ASSERT_EQUAL_PTR(NULL, root->rightChild->leftChild);
	
}
// ************REPLACER************************
/**
  *        (1) 
  *
  */
void test_avlGetReplacer_for_the_first_case(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node *root = &Node1;
	Node *temp;
	
    temp = avlGetReplacer(&root);

	TEST_ASSERT_EQUAL_PTR(&Node1, temp);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**
  *   	  (1)
  *       /   
  *     (50) 
  *      
  */
void test_avlGetReplacer_for_the_2nd_case(){
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 1, .leftChild =  &Node50, . rightChild = NULL};
	Node *root = &Node1;
	Node *temp;
	
    temp = avlGetReplacer(&root);

	TEST_ASSERT_EQUAL_PTR(&Node1, temp);
	//TEST_ASSERT_EQUAL_PTR(&Node50, root);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
}
/**
  *   (1)  
  *     \   
  *     (50) 
  *      
  */
void test_avlGetReplacer_for_the_3rd_case(){
	Node Node50 = {.data = 50, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 1, .leftChild = NULL, . rightChild = &Node50};
	Node *root = &Node1;
	Node *temp;
	
    temp = avlGetReplacer(&root);

	TEST_ASSERT_EQUAL_PTR(&Node50, temp);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}

/**
  *     (50)  
  *    /   \   
  *  (1)  (100) 
  *      
  */
void test_avlGetReplacer_for_the_4th_case(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 0, .leftChild = &Node1, . rightChild = &Node100};
	Node *root = &Node50;
	Node *temp;
	
	temp = avlGetReplacer(&root);
	
	TEST_ASSERT_EQUAL_PTR(&Node100, temp);
	TEST_ASSERT_EQUAL_PTR(NULL, Node50.rightChild);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node50);
  
}
/**     (50)
  *    /    \
  *  (1)   (100)
  *         /
  *       (75)
  *  
  */
void test_avlGetReplacer_for_the_5th_case(){
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = &Node75, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = 1, .leftChild = &Node1, . rightChild = &Node100};
	Node *root = &Node50;
	Node *temp;
	
	temp = avlGetReplacer(&root);
	
	TEST_ASSERT_EQUAL_PTR(&Node100, temp);
	TEST_ASSERT_EQUAL_PTR(&Node75, Node50.rightChild);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);

}
/**    	  (50)
  *  	   /   \
  *  	 (10) (100)
  *    /    /  \
  *  (1) (75) (120)
  *  		       /
	*		      (110)	
  */
void test_avlGetReplacer_for_the_6th_case(){
	Node Node75 = {.data = 75, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node110 = {.data = 110, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	
	Node Node120 = {.data = 120, .balance = -1, .leftChild = &Node110, . rightChild = NULL};
	
	Node Node100 = {.data = 100, .balance = 1, .leftChild = &Node75, . rightChild = &Node120};
	Node Node10 = {.data = 10, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
	
	Node Node50 = {.data = 50, .balance = 1, .leftChild = &Node10, . rightChild = &Node100};
	Node *root = &Node50;
	Node *temp;
	
	temp = avlGetReplacer(&root);
	
	TEST_ASSERT_EQUAL_PTR(&Node120, temp);
	TEST_ASSERT_EQUAL_PTR(&Node110, Node100.rightChild);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node110,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node10);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node75,0,&Node50);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node110);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}
/**    	  (100)                 (75)
  *  	   /   \                  /   \
  *  	 (50) (120)             (50)  100
  *    /  \     \       =>   /  \   /  \
  *  (10) (75)  (150)      (10) 60 80   120
  *  		 /  \ 
	*		(60)  (80)	
  */
void test_avlGetReplacer_for_the_7th_case(){
  Node Node60 = {.data = 60, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node80 = {.data = 80, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10 = {.data = 10, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node150 = {.data = 150, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node120 = {.data = 120, .balance = 1, .leftChild = NULL, . rightChild = &Node150};

	Node Node75 = {.data = 75, .balance = 0, .leftChild = &Node60, . rightChild = &Node80};
  
  Node Node50 = {.data = 50, .balance = 1, .leftChild = &Node10, . rightChild = &Node75};
  
	Node Node100 = {.data = 100, .balance = -1, .leftChild = &Node50, . rightChild = &Node120};

	Node *root = &Node100;
	Node *temp;
	
	temp = avlGetReplacer(&root);
  // printf("60: %p\n",&Node60);
  // printf("80: %p\n",&Node80);
  // printf("75: %p\n",&Node75);
  // printf("50: %p\n",&Node50);
  // printf("10: %p\n",&Node10);
  // printf("100: %p\n",&Node100);
  // printf("120: %p\n",&Node120);
  // printf("150: %p\n",&Node150);
	
	TEST_ASSERT_EQUAL_PTR(&Node150, temp);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node80,NULL,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node100,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(&Node10,&Node60,0,&Node50);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node80);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node60);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node10);
}

/**
  *     (50)            10
  *    /   \          /   \
  *  (10)  (100)  => 1    50
  *  /                      
  *(1)                     
  */
void test_avlGetReplacer_for_the_8th_case(){
	Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, . rightChild = NULL};
	Node Node100 = {.data = 100, .balance = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10 = {.data = 10, .balance = -1, .leftChild = &Node1, . rightChild = NULL};
	Node Node50 = {.data = 50, .balance = -1, .leftChild = &Node10, . rightChild = &Node100};
  
	Node *root = &Node50;
	Node *temp;
	
	temp = avlGetReplacer(&root);
	
	TEST_ASSERT_EQUAL_PTR(&Node100, temp);
	
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node10);
  
}
	