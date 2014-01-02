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
	Node* current = bst->root;
	nodeToInsert = createNode();
	nodeToInsert->data = dataToInsert;
	if( NULL == bst->root){
		nodeToInsert->left = NULL;
		nodeToInsert->right = NULL;
		bst->root = nodeToInsert;
		return 1;
	}
	while(0 != bst->compare(current->data, nodeToInsert->data)){
		if(0 > bst->compare(current->data, nodeToInsert->data)){
			if(NULL == current->left ){
				current->left = nodeToInsert;
				return 1;
			}
			current = current->left;
		}
		else{
			if(NULL == current->right ){
				current->right = nodeToInsert;
				return 1;
			}
			current = current->right;
		}
	}

	return 0;
}