#include "msort.h"
#include <stdlib.h>
void merge(void **leftArr,void **rightArr,int leftLength,int rightLength,int length,void **base,Compare compare){
    void **temp = malloc(length*2*sizeof(void*));
    int index,leftCounter=0,rightCounter=0;
    for (index=0;index<length;++index)
    {
        if(leftCounter > leftLength-1){
            temp[index] = rightArr[rightCounter];
            rightCounter++;
        }
        else if(rightCounter>rightLength-1){
            temp[index] = leftArr[leftCounter];
            leftCounter++;
        }
        else if(compare(leftArr[leftCounter],rightArr[rightCounter]) > 0){
            temp[index] = rightArr[rightCounter];
            rightCounter++;
        }
        else{
            temp[index] = leftArr[leftCounter];
            leftCounter++;
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
        merge(leftArr,rightArr,mid,length-mid,length,base,compare);
    }
    free(leftArr);
    free(rightArr);
};