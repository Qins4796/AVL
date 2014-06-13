#include "unity.h"
#include "AVL.h"
#include "Rotation.h"
#include <stdio.h>

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
	
	TEST_ASSERT_EQUAL_PTR(&Node100, root);
	TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
	TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node75, root->leftChild->rightChild);
	TEST_ASSERT_EQUAL_PTR(&Node1, Node50.leftChild);
	
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node1.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node75.rightChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.leftChild);
	TEST_ASSERT_EQUAL_PTR(NULL, Node150.rightChild);
	
	TEST_ASSERT_EQUAL(0, Node1.balance);
	TEST_ASSERT_EQUAL(2, Node50.balance); 	//zxc
	TEST_ASSERT_EQUAL(0, Node100.balance);
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(0, Node150.balance);
}
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
	TEST_ASSERT_EQUAL(2, Node50.balance); 	//zxc
	TEST_ASSERT_EQUAL(1, Node100.balance);	//zxc
	TEST_ASSERT_EQUAL(0, Node75.balance);
	TEST_ASSERT_EQUAL(1, Node150.balance);	//zxc
	TEST_ASSERT_EQUAL(0, Node200.balance);
}
