#include "testUtils.h"
#include "bSearchTree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* element1, void* element2){
	return *(int*)element1 - *(int*)element2;
}

int compareDouble(void* element1, void* element2){
	return *(double*)element1 - *(double*)element2;
}

void test_to_insert_rootNode_in_tree(){
	BSearchTree bst = create(&compareInt);
	int dataToInsert = 3;
	int res = insertNode(&bst,&dataToInsert);
	ASSERT(1 == res);

	ASSERT(*(int*)bst.root->data == dataToInsert);
}

void test_to_inserting_same_value_as_of_root_should_fail(){
	BSearchTree bst = create(compareInt);
	int first = 3,res;
	insertNode(&bst,&first);
	res = insertNode(&bst, &first);
	ASSERT(0 == res);
}

void test_to_insert_two_nodes_in_tree(){
	BSearchTree bst = create(compareInt);
	int first = 7,second = 4,res;
	insertNode(&bst,&first);
	res = insertNode(&bst, &second);
	ASSERT(1 == res);
	ASSERT(*(int*)bst.root->data == first);
	ASSERT(*(int*)bst.root->left->data == second);
}

void test_to_insert_four_nodes_in_tree(){
	BSearchTree bst = create(compareInt);
	int first = 7,second = 4, third = 5,forth = 9,res;
	insertNode(&bst,&first);
	insertNode(&bst, &second);
	insertNode(&bst, &third);
	res = insertNode(&bst, &forth);
	ASSERT(1 == res);
}

void test_to_get_the_children_nodes_of_root(){
	BSearchTree bst = create(compareInt);
	int first = 7,second = 4,third = 8,res;
	Children ch;
	insertNode(&bst,&first);
	insertNode(&bst, &second);
	res = insertNode(&bst, &third);
	ASSERT(1 == res);
	ch = getChildren(&bst, &first);
	ASSERT(&second == ch.left);
	ASSERT(&third == ch.right);
}