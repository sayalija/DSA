#include "tree.h"
#include <stdlib.h>


Tree createTree(){
	Tree tree;
	tree.depth = 0;
	tree.root = NULL;
	return tree;
}

TreeNode* getNewNode(void *dataToInsert){
	TreeNode* node = calloc(1, sizeof(TreeNode));
	node->children = NULL;
	node->data = dataToInsert;
	node->parent = NULL;
	return node;
}

int insertNode(Tree* tree, void* parentData, void* dataToInsert ){
	if(parentData == NULL){
		tree->root =getNewNode(dataToInsert);
		return 1;
	}
	
	return 1;
}