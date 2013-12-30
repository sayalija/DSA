typedef int (*Compare)(void *element1,void *element2);
void msort(void **base,int length,Compare cmp);