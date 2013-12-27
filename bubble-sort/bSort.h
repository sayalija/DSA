typedef int (*compare) (void* element1, void* element2);
void bSort(void* elements, int length, int typeSize, compare cmp);