#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
// #include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int cmp(void* a, void* b){
	return *(int*)a - *(int*)b;
}

void test_1_to_create_tree_and_insert_root(){
	Tree tree = createTree(&cmp);
	int data = 3;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
}

void test_2_to_create_tree_and_insert_node_under_root(){
	Iterator it;
	Tree tree = createTree(&cmp);
	int root = 3,child1 = 4,child2 = 5,res;
	insertNode(&tree, NULL, &root);
	insertNode(&tree, &root, &child1);
	insertNode(&tree, &root, &child2);
	it = getChildren(&tree, &root);
	ASSERT(child2 == *(int*)it.next(&it));
	ASSERT(child1 == *(int*)it.next(&it));
}

void test_3_to_insert_child_node_to_child_of_root(){
	Iterator it;
	Tree tree = createTree(&cmp);
	int root = 3,child = 4,grandChild = 5,res;
	insertNode(&tree, NULL, &root);
	insertNode(&tree, &root, &child);
	insertNode(&tree, &child, &grandChild);
	it = getChildren(&tree, &root);
	ASSERT(child == *(int*)it.next(&it));
}

void test_4_to_serach_data_in_tree(){
	Iterator it;
	Tree tree = createTree(&cmp);
	int root = 3,child1 = 4,child2 = 5,res;
	insertNode(&tree, NULL, &root);
	insertNode(&tree, &root, &child1);
	insertNode(&tree, &root, &child2);
	it = getChildren(&tree, &root);
	res = search(&tree, &child1);
	ASSERT(1 == res);
	res = search(&tree, &child2);
	ASSERT(1 == res);
}

void test_5_to_serach_unavailable_data_in_tree(){
	Iterator it;
	Tree tree = createTree(&cmp);
	int root = 3,child1 = 4,child2 = 5,res;
	insertNode(&tree, NULL, &root);
	insertNode(&tree, &root, &child1);
	it = getChildren(&tree, &root);
	res = search(&tree, &child1);
	ASSERT(1 == res);
	res = search(&tree, &child2);
	ASSERT(0 == res);
}

void test_6_to_delete_data_from_tree(){
	Iterator it;
	Tree tree = createTree(&cmp);
	int root = 3,child1 = 4,child2 = 5,res;
	insertNode(&tree, NULL, &root);
	insertNode(&tree, &root, &child1);
	it = getChildren(&tree, &root);
	ASSERT(child1 == *(int*)it.next(&it));
	res = deleteNode(&tree, &child1);
	ASSERT(1);
	it = getChildren(&tree, &root);
	ASSERT(0 == it.position);
}