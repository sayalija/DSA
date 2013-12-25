#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_to_create_tree_and_insert_root(){
	Tree tree = createTree();
	int data = 3;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
	ASSERT(*(int*)tree.root->data == data);
	ASSERT(tree.depth == 0);
}
