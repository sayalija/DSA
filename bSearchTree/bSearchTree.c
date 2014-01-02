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

int traverse(BSearchTree* bst,Node* current,Node* nodeToInsert){
	int compareResult = bst->compare(current->data, nodeToInsert->data);
	while(0 != compareResult){
		if(0 > compareResult){
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
	return traverse(bst,current,nodeToInsert);
}