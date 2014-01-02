#include "testUtils.h"
#include "bSearchTree.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void* element1, void* element2){
	return *(int*)element1 - *(int*)element1;
}

void test_to_insert_node_in_tree(){
	BSearchTree bst = create(compareInt);
	int dataToInsert = 3;
	int res = insertNode(&bst,&dataToInsert);
	ASSERT(1 == res);
	ASSERT(*(int*)bst.root->data == dataToInsert);
}
