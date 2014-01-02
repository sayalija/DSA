#include "bSearchTree.h"
#include <stdlib.h>

BSearchTree create(Comparator cmp){
	BSearchTree bst;
	bst.root = calloc(1, sizeof(Node));
	bst.root->parent = NULL;
	return bst;
}

Node* createNode(){
	Node* node = calloc(1, sizeof(Node));
	return node;
}



int insertNode(BSearchTree* bst,void* dataToInsert){
	Node* parent, *nodeToInsert;
	nodeToInsert = createNode();
	if( NULL == bst->root->parent){
		nodeToInsert->data = dataToInsert;
		nodeToInsert->left = NULL;
		nodeToInsert->right = NULL;
		bst->root = nodeToInsert;
		return 1;
	}
	return 0;
}