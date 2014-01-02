#include "bSearchTree.h"
#include <stdlib.h>

BSearchTree create(Comparator* cmp){
	BSearchTree bst;
	bst.root = NULL;
	bst.compare = cmp;
	return bst;
}

Node* createNode(){
	Node* node = calloc(1, sizeof(Node));
	return node;
}

int insertNode(BSearchTree* bst,void* dataToInsert){
	Node* parent, *nodeToInsert;
	nodeToInsert = createNode();
	nodeToInsert->data = dataToInsert;
	if( NULL == bst->root){
		nodeToInsert->left = NULL;
		nodeToInsert->right = NULL;
		bst->root = nodeToInsert;
		return 1;
	}
	if(0 == bst->compare(bst->root->data, nodeToInsert->data))
		return 0;
	return 0;
}