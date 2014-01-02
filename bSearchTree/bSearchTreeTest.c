#include "testUtils.h"
#include "bSearchTree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* element1, void* element2){
	return *(int*)element1 - *(int*)element2;
}
int seven = 7,four = 4,eight = 8,three = 3,six = 6, five = 5, nine = 9;

void test_to_insert_rootNode_in_tree(){
	BSearchTree bst = create(&compareInt);
	int res = insertNode(&bst,&three);
	ASSERT(1 == res);

	ASSERT(*(int*)bst.root->data == three);
}

void test_1_to_inserting_same_value_as_of_root_should_fail(){
	BSearchTree bst = create(compareInt);
	int res;
	insertNode(&bst,&three);
	res = insertNode(&bst, &three);
	ASSERT(0 == res);
}

void test_2_to_insert_two_nodes_in_tree(){
	BSearchTree bst = create(compareInt);
	int res;
	insertNode(&bst,&seven);
	res = insertNode(&bst, &four);
	ASSERT(1 == res);
	ASSERT(*(int*)bst.root->data == seven);
	ASSERT(*(int*)bst.root->left->data == four);
}

void test_3_to_insert_four_nodes_in_tree(){
	BSearchTree bst = create(compareInt);
	int res;
	insertNode(&bst,&seven);
	insertNode(&bst, &four);
	insertNode(&bst, &five);
	res = insertNode(&bst, &nine);
	ASSERT(1 == res);
}

void test_4_to_get_the_children_nodes_of_root(){
	BSearchTree bst = create(compareInt);
	int res;
	Children ch;
	insertNode(&bst,&seven);
	insertNode(&bst, &four);
	res = insertNode(&bst, &eight);
	ASSERT(1 == res);
	ch = getChildren(&bst, &seven);
	ASSERT(four == *(int*)ch.left);
	ASSERT(eight == *(int*)ch.right);
}

void test_5_to_get_the_children_of_every_node_inserted(){
	BSearchTree bst = create(compareInt);
	Children ch;
	insertNode(&bst, &seven);
	insertNode(&bst, &four);
	insertNode(&bst, &eight);
	insertNode(&bst, &three);
	insertNode(&bst, &six);
	ch = getChildren(&bst, &seven);
	ASSERT(four == *(int*)ch.left);
	ASSERT(eight == *(int*)ch.right);
	ch = getChildren(&bst, &four);
	ASSERT(three == *(int*)ch.left);
	ASSERT(six == *(int*)ch.right);
}

void test_6_to_get_no_children_when_no_node_is_present(){
	BSearchTree bst = create(compareInt);
	Children ch;
	insertNode(&bst, &seven);
	ch = getChildren(&bst, &seven);
	ASSERT(NULL == (int*)ch.left);
	ASSERT(NULL == (int*)ch.right);
}

void test_7_to_fail_if_tried_to_delete_NULL_element(){
	BSearchTree bst = create(compareInt);
	int res = 0;
	insertNode(&bst, &seven);
	res = deleteNode(&bst,NULL);
	ASSERT(0 == res);
}

void test_8_to_delete_root(){
	BSearchTree bst = create(compareInt);
	int res = 0;
	insertNode(&bst, &seven);
	res = deleteNode(&bst,&seven);
	ASSERT(1 == res);
}

void test_9_to_delete_element_under_root(){
	Children ch;
	BSearchTree bst = create(compareInt);
	int res = 0;
	insertNode(&bst, &seven);
	insertNode(&bst, &four);
	ch = getChildren(&bst, &seven);
	ASSERT(four == *(int*)ch.left);
	ASSERT(NULL == (int*)ch.right);
	res = deleteNode(&bst,&four);
	ASSERT(1 == res);
	ch = getChildren(&bst, &seven);
	ASSERT(NULL == (int*)ch.left);
	ASSERT(NULL == (int*)ch.right);
}