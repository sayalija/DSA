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

Node* traverse(BSearchTree* bst, Node* current, void* data){
	int compareResult = bst->compare(current->data, data);
	if(0 == compareResult)
		return current;
	else if(0 < compareResult){
		if(NULL == current->left)
			return current;
		return traverse(bst, current->left, data);
	}
	else{
		if(NULL == current->right)
			return current;
		return traverse(bst, current->right, data);
	}
	return current;
}

int insertNode(BSearchTree* bst,void* dataToInsert){
	Node* current = bst->root;
	Node* newNode, *nodeToInsert;
	nodeToInsert = createNode();
	nodeToInsert->data = dataToInsert;
	if( NULL == bst->root){
		nodeToInsert->left = NULL;
		nodeToInsert->right = NULL;
		bst->root = nodeToInsert;
		return 1;
	}
	if(current->data == dataToInsert)
		return 0;
	newNode = traverse(bst,current,dataToInsert);
	if(newNode->data == dataToInsert)
		return 0;
	nodeToInsert->parent = newNode;
	if(0 < bst->compare(newNode->data,dataToInsert)){
		newNode->left = nodeToInsert;
	}
	else
		newNode->right = nodeToInsert;
	return 1;
}

Children getChildren(BSearchTree* bst,void* data){
	Children ch;
	Node* dataNode = traverse(bst, bst->root ,data);
	ch.left = dataNode->left != NULL ? dataNode->left->data : NULL;
	ch.right = dataNode->right != NULL ? dataNode->right->data : NULL;
	return ch;
}

int deleteNode(BSearchTree* bst,void* dataToDelete){
	Node* node;
	if(NULL == dataToDelete)
		return 0;
	if(bst->compare(bst->root->data,dataToDelete) == 0){
		free(bst->root);
		return 1;
	}
	node = traverse(bst, bst->root, dataToDelete);
	if(node->left == NULL && node->right == NULL){
		if(0 == bst->compare(node->parent->left->data,node->data))
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		free(node);
	}
	return 1;
}