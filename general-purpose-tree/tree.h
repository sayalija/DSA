#include "../linked-list/linkedList.h"

typedef int compare(void* parentData, void* nodeData);
typedef struct TreeNode{
	void* data;
	struct TreeNode* parent;
	List* children;
} TreeNode;

typedef struct {
	TreeNode* root;
	compare* areEqual;
} Tree;

Tree createTree(compare* cmp);
int insertNode(Tree* tree, void* parentData, void* dataToInsert );
int deleteNode(Tree* ptree, void* data);
Iterator getChildren(Tree* tree, void* parentData);
int search(void* tree,void* parent);