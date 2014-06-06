#include "unity.h"
#include "Rotation.h"
#include "AVL.h"

void setUp(){}
void tearDown(){}

/**
  *   (1)              (2)
  *     \              / \
  *     (2)    =>   (1)  (3)
  *      \
  *      (3)
  */
  
void test_leftRotate_given_3_elements_should_rotate_to_balance_tree(){
	Node Node3 = {.data = 3, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node2 = {.data = 2, .rank = 1, .leftChild = NULL, . rightChild = &Node3};
  Node Node1 = {.data = 1, .rank = 2, .leftChild = NULL, . rightChild = &Node2};
  Node *root;
  
  root = leftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/**
  *       (3)        (2)
  *       /          / \
  *     (2)   =>  (1)  (3)
  *     /
  *   (1)
  */
  
void test_rightRotate_given_3_elements_should_rotate_to_balance_tree(){
  Node Node1 = {.data = 1, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node2 = {.data = 2, .rank = -1, .leftChild = &Node1, . rightChild = NULL};
  Node Node3 = {.data = 3, .rank = -2, .leftChild = &Node2, . rightChild = NULL};

  Node *root;
  
  root = rightRotate(&Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/**
  *       (3)        (2)
  *       /          / \
  *     (1)   =>  (1)  (3)
  *       \
  *       (2)
  */
  
void test_doubleRightRotate_given_3_elements_should_rotate_to_balance_tree(){
  
  Node Node2 = {.data = 2, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node1 = {.data = 1, .rank = 1, .leftChild = NULL, . rightChild = &Node2};
  Node Node3 = {.data = 3, .rank = -2, .leftChild = &Node1, . rightChild = NULL};
  
  
  Node *root;
  
  root = doubleRightRotate(&Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/**
  *   (1)          (2)
  *     \          / \
  *     (3)  =>  (1) (3)
  *     /  
  *   (2)    
  */
  
void test_doubleLeftRotate_given_3_elements_should_rotate_to_balance_tree(){
  
  Node Node2 = {.data = 2, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node3 = {.data = 3, .rank = -1, .leftChild = &Node2, . rightChild = NULL};
  Node Node1 = {.data = 1, .rank = 2, .leftChild = NULL, . rightChild = &Node3};
  
  Node *root;
  
  root = doubleLeftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}
/**
  *        (50)              (10) 2
  *        /  \              /  \
  *     (10)  (100)  =>    (5)  (50) 1
  *     /  \               /    /  \
  *   (5)  (30)          (1) (30)  (100) 0
  *   /
  * (1)
  *
  */
void test_fakeTREE_right_single(){
  Node Node1 = {.data = 1, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node30 = {.data = 30, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node100 = {.data = 100, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node5 = {.data = 5, .rank = 1, .leftChild = &Node1, . rightChild = NULL};
  Node Node10 = {.data = 10, .rank = 2, .leftChild = &Node5, . rightChild = &Node30};
  Node Node50 = {.data = 50, .rank = 2, .leftChild = &Node10, . rightChild = &Node100};
  
  Node *root;
  
  root = tree(&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node10, root);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  
  //TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild->leftChild);
  
  // TEST_ASSERT_EQUAL_PTR(&Node30, root->rightChild->leftChild);
  // printf("Parent->rightChild->rightChild  %d",root->rightChild->rightChild);
  // TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(2, Node10.rank);
  TEST_ASSERT_EQUAL(1, Node5.rank);
  TEST_ASSERT_EQUAL(1, Node50.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node30.rank);
  TEST_ASSERT_EQUAL(0, Node100.rank);
  
}

/**
  *       (3)  
  *       /   
  *     (2)   
  *     /
  *   (1)
  */
void test_getHeight_left_given_3_elements_should_get_the_height_to_balance_tree(){
  Node Node1 = {.data = 1, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node2 = {.data = 2, .rank = 1, .leftChild = &Node1, . rightChild = NULL};
  Node Node3 = {.data = 3, .rank = 2, .leftChild = &Node2, . rightChild = NULL};
  
  int height = getHeight(&Node3);

  TEST_ASSERT_EQUAL(3, height);
}
/**
  *   (1)    
  *     \     
  *     (2)   
  *      \
  *      (3)
  */
void test_getHeight_right_given_3_elements_should_get_the_height_to_balance_tree(){
	Node Node3 = {.data = 3, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node2 = {.data = 2, .rank = 1, .leftChild = NULL, . rightChild = &Node3};
  Node Node1 = {.data = 1, .rank = 2, .leftChild = NULL, . rightChild = &Node2};
  
  int height = getHeight(&Node1);

  TEST_ASSERT_EQUAL(3, height);
}
/**
  *        (50)              (10) 2
  *        /  \              /  \
  *     (10)  (100)  =>    (5)  (50) 1
  *     /  \               /    /  \
  *   (5)  (30)          (1) (30)  (100) 0
  *   /
  * (1)
  *
  */
void test_getHeight_for_the_5_element_above(){
  Node Node1 = {.data = 1, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node30 = {.data = 30, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node100 = {.data = 100, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node5 = {.data = 5, .rank = 1, .leftChild = &Node1, . rightChild = NULL};
  Node Node10 = {.data = 10, .rank = 2, .leftChild = &Node5, . rightChild = &Node30};
  Node Node50 = {.data = 50, .rank = 2, .leftChild = &Node10, . rightChild = &Node100};
  
  int height = getHeight(&Node50);

  TEST_ASSERT_EQUAL(4, height);
}
/**
  *           (5)
  *           /
  *         (4)
  *         /
  *       (3)  
  *       /   
  *     (2)   
  *     /
  *   (1)
  */
void test_getHeight_for_the_height_of_5_element(){
  Node Node1 = {.data = 1, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node2 = {.data = 2, .rank = 1, .leftChild = &Node1, . rightChild = NULL};
  Node Node3 = {.data = 3, .rank = 2, .leftChild = &Node2, . rightChild = NULL};
  Node Node4 = {.data = 4, .rank = 3, .leftChild = &Node3, . rightChild = NULL};
  Node Node5 = {.data = 5, .rank = 4, .leftChild = &Node4, . rightChild = NULL};
  
  int height = getHeight(&Node5);

  TEST_ASSERT_EQUAL(5, height);
}
/**
  *        (50)                  (100) 0
  *        /  \                  /   \
  *     (10)  (100)            (50)  (150) 1
  *           /  \      =>    /   \     \
  *        (70)  (150)      (10) (70)   (200) 0
  *                \
  *               (200)
  */
void test_leftRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  Node Node200 = {.data = 200, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node150 = {.data = 150, .rank = 1, .leftChild = NULL, . rightChild = &Node200};
  Node Node70  = {.data = 70,  .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node100 = {.data = 100, .rank = 1, .leftChild = &Node70, . rightChild = &Node150};
  Node Node10  = {.data = 10,  .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node50  = {.data = 50,  .rank = 2, .leftChild = &Node10, . rightChild = &Node100};
  Node *root;

  root = leftRotate(&Node50);
  
  TEST_ASSERT_EQUAL_PTR(&Node100, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node70, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200, root->rightChild->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node50.rank);
  TEST_ASSERT_EQUAL(0, Node10.rank);
  TEST_ASSERT_EQUAL(0, Node100.rank);
  TEST_ASSERT_EQUAL(0, Node70.rank);
  TEST_ASSERT_EQUAL(1, Node150.rank);
  TEST_ASSERT_EQUAL(0, Node200.rank);
 }
 /**
  *         (50)               0  (10) 
  *         /  \                  /  \
  *       (10) (100)         -1 (5)  (50)
  *       / \           =>     /     /  \
  *     (5) (30)           0 (1)   (30) (100)
  *     /         
  *   (1) 
  *
  */
void test_rightRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  Node Node1 = {.data = 1, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node5 = {.data = 5, .rank = -1, .leftChild = &Node1, . rightChild = NULL};
  Node Node30  = {.data = 30,  .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node100 = {.data = 100, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10  = {.data = 10,  .rank = -1, .leftChild = &Node5, . rightChild = &Node30};
  
  Node Node50  = {.data = 50,  .rank = -2, .leftChild = &Node10, . rightChild = &Node100};
  Node *root;

  root = rightRotate(&Node50);
  
  TEST_ASSERT_EQUAL_PTR(&Node10, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node30, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node10.rank);
  TEST_ASSERT_EQUAL(0, Node50.rank);
  TEST_ASSERT_EQUAL(-1, Node5.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node30.rank);
  TEST_ASSERT_EQUAL(0, Node100.rank);
 }
 /**            -2
  *         (50)               0  (30) 
  *         /  \                  /  \
  *     1(10) (100)         -1 (10)  (50)
  *       / \           =>     /     /  \
  *     (5) (30) 1        0 (5)   (40) (100)
  *           \        
  *           (40)
  */
void test_doubleRightRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  Node Node40 = {.data = 40, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node5 = {.data = 5, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node30  = {.data = 30,  .rank = 0, .leftChild = NULL, . rightChild = &Node40};
  
  Node Node100 = {.data = 100, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10  = {.data = 10,  .rank = 0, .leftChild = &Node5, . rightChild = &Node30};
  
  Node Node50  = {.data = 50,  .rank = -2, .leftChild = &Node10, . rightChild = &Node100};
  Node *root;

  root = doubleRightRotate(&Node50);
  
  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  //TEST_ASSERT_EQUAL_PTR(&Node40, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node30.rank);
  TEST_ASSERT_EQUAL(0, Node50.rank);
  TEST_ASSERT_EQUAL(-1, Node10.rank);
  TEST_ASSERT_EQUAL(0, Node5.rank);
  TEST_ASSERT_EQUAL(0, Node40.rank);
  TEST_ASSERT_EQUAL(0, Node100.rank);
 }

 /**            
  *         (50)                 (30)
  *         /  \                /   \
  *     (100) (10)            (50)  (10) 
  *           /  \     =>     /  \    \
  *        (30)  (5)      (100) (40)  (5)
  *         / 
  *      (40) 
  */
void test_doubleLeftRotate_given_6_element_should_rotate_to_balance_the_tree_case1(){
  Node Node40 = {.data = 40, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  
  Node Node5 = {.data = 5, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node30  = {.data = 30,  .rank = 0, .leftChild = &Node40, . rightChild = NULL};
  
  Node Node100 = {.data = 100, .rank = 0, .leftChild = NULL, . rightChild = NULL};
  Node Node10  = {.data = 10,  .rank = 0, .leftChild = &Node30, . rightChild = &Node5};
  
  Node Node50  = {.data = 50,  .rank = 2, .leftChild = &Node100, . rightChild = &Node10};
  Node *root;
  
  root = doubleLeftRotate(&Node50);
  
  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->rightChild);
  
  TEST_ASSERT_EQUAL_PTR(&Node5, root->rightChild->rightChild);
  //TEST_ASSERT_EQUAL_PTR(&Node40, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->leftChild->leftChild);
  
  TEST_ASSERT_EQUAL(0, Node30.rank);
  TEST_ASSERT_EQUAL(0, Node50.rank);
  TEST_ASSERT_EQUAL(1, Node10.rank);
  TEST_ASSERT_EQUAL(0, Node5.rank);
  TEST_ASSERT_EQUAL(0, Node40.rank);
  TEST_ASSERT_EQUAL(0, Node100.rank);
}