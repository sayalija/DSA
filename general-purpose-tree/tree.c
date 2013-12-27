#include "tree.h"
#include <stdlib.h>

Tree createTree(compare* cmp){
	Tree tree;
	tree.root = NULL;
	tree.areEqual = cmp;
	return tree;
}

TreeNode* getNewNode(void *dataToInsert){
	TreeNode* node = calloc(1, sizeof(TreeNode));
	node->children = create();
	node->data = dataToInsert;
	node->parent = NULL;
	return node;
}

void getAllChildren(List* temp,TreeNode* parent){
	Iterator it = getIterator(parent->children);
	while(it.hasNext(&it)){
		insert(temp, temp->numberOfElements-1, it.next(&it));
	}
}

TreeNode* traverse(List* list, void* parentData, compare* cmp){
	Iterator it = getIterator(list);
	List* tempList = create();
	Node* listNode;
	TreeNode* temp;
	while(it.hasNext(&it)){
		temp = (TreeNode*)it.next(&it);
		if(0 == cmp(parentData,temp->data)){
			dispose(tempList);
			return temp;
		}
		getAllChildren(tempList, temp);
	}
	if(tempList->numberOfElements)
		return traverse(tempList, parentData, cmp);
	dispose(tempList);
	return NULL;
}

TreeNode* getNode(Tree* tree,void* parentData){
	TreeNode* root = (TreeNode*)tree->root;
	if(0 == tree->areEqual(parentData,root->data))
		return tree->root;
	return traverse(root->children,parentData, tree->areEqual);
}

int insertNode(Tree* tree, void* parentData, void* dataToInsert ){
	TreeNode* root = (TreeNode*)tree->root;
	TreeNode* parent,*node;
	if(parentData == NULL){
		tree->root =getNewNode(dataToInsert);
		return 1;
	}
	parent = getNode(tree,parentData);
	node = getNewNode(dataToInsert);
	insert(parent->children, 0, node);
		return 1;
}

void* treeNext(Iterator *it){
    TreeNode *node;
    Iterator treeIterator = getIterator(it->list);
    treeIterator.position = it->position;
    node = treeIterator.next(&treeIterator);
    it->position++;
    return node->data;
}
Iterator getChildren(Tree* tree, void *parent) {
    TreeNode *temp,*root = (TreeNode*)tree->root;
    Iterator it;
    if(0 == tree->areEqual(root->data,parent)){
        temp = root;
    }
    else 
        temp = getNode(tree, parent);
    it = getIterator(temp->children);
    it.next = &treeNext;
    return it;
}

void* searchTreeNode(Tree *tree,void* parentData){
    TreeNode* node;
    node = getNode(tree, parentData);
    return node;
};

int search(void* tree,void* parent){
    if(searchTreeNode(tree,parent) == NULL)
    	return 0;
    return 1;
};

int getIndex(List* list,void* data,compare cmp){
    int i = 0;
    TreeNode *tn;
    Iterator it = getIterator(list);
    while(it.hasNext(&it)){
        i = i + 1;
        tn = (TreeNode*)it.next(&it);
        if(0 == cmp(tn->data,data))
            return i-1;
    }
    return i-1;
};

int deleteNode(Tree* tree, void* data){
    List* list;
    int index;
    TreeNode *node = getNode(tree,data);
    if(node == tree->root){
        tree->root = NULL;
        free(node);
        return 1;
    }
    list = node->children;
    index = getIndex(list,data,tree->areEqual);
    remove(list, index);
    if(getLength(list) == 0)
        (node->children->head) = NULL;
    free(node);
    return 1;
};