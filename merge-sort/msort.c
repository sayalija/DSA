#include "msort.h"
#include <stdlib.h>
int msort(void **elements, int startIndex, int endIndex, int length, Compare cmp){
	int mid;
	int i = 0;
    void **leftArray,**rightArray;
    mid = (startIndex + endIndex)/2;
    for(i=0;i<length;i++)
    leftArray = malloc((mid+1)*sizeof(void*));
    rightArray = malloc((mid+1)*sizeof(void*));
    if(length > 1){
        for(i=0;i<=mid;i++){
            leftArray[i] = elements[i];
            rightArray[i] = elements[mid+(i+1)];
        }
        msort(leftArray,0,mid,mid+1,cmp);
        msort(rightArray,0,mid,mid+1,cmp);
    }
    return 0;
}
