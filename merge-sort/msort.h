typedef int (*Compare)(void *first,void *second);
void msort(void **base,int length,Compare cmp);