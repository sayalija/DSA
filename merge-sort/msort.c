#include "msort.h"
#include <stdlib.h>
void merge(void **leftArr,void **rightArr,int lLength,int length,void **base,Compare compare){
	int rLength = length-lLength;
    void **temp = malloc(length*2*sizeof(void*));
    int index,left=0,right=0;
    for (index=0;index<length;++index)
    {
        if(left > lLength-1){
            temp[index] = rightArr[right];
            right++;
        }
        else if(right>rLength-1){
            temp[index] = leftArr[left];
            left++;
        }
        else if(compare(leftArr[left],rightArr[right]) > 0){
            temp[index] = rightArr[right];
            right++;
        }
        else{
            temp[index] = leftArr[left];
            left++;
        }
    }
    for(index=0;index<length;index++)
            base[index] = temp[index];
    free(temp);
};

void msort(void **base,int length,Compare compare){
    int mid,index;
    void **leftArr,**rightArr;
    mid = length/2;
    leftArr = malloc((mid+1)*sizeof(void*));
    rightArr = malloc((mid+1)*sizeof(void*));
    if(length == 1)
        return;
    else{
        for(index=0;index<mid;index++)
            leftArr[index] = base[index];
        for(index=mid;index<length;index++)
            rightArr[index-mid] = base[index];
        msort(leftArr,mid,compare);
        msort(rightArr,length-mid,compare);
        merge(leftArr,rightArr,mid,length,base,compare);
    }
    free(leftArr);
    free(rightArr);
};