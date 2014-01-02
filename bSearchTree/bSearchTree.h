typedef int (*Comparator)(void* element1, void* element2);
typedef struct{

} BSearchTree;

BSearchTree create(Comparator cmp);
int insertNode(BSearchTree* bst,void* dataToInsert);
