typedef int (Comparator)(void* element1, void* element2);

typedef struct Node{
	void* data;
	struct Node* parent;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct {
	void* left;
	void* right; 
} Children;

typedef struct{
	Node* root;
	Comparator* compare;
} BSearchTree;

BSearchTree create(Comparator* cmp);
int insertNode(BSearchTree* bst,void* dataToInsert);
Children getChildren(BSearchTree* bst,void* data);