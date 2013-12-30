typedef int (*Compare)(void *first,void *second);
void mSort(void **base,int startIndex,int endIndex,int length,Compare cmp);