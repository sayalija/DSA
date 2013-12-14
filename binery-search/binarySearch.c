#include "binarySearch.h"
#include <string.h>
voidPtr binerySearch(voidPtr key,voidPtr base,int length,int size,int (*compare)(voidPtr,voidPtr)){
        voidPtr middleElement;
        int middle,found,first = 0,last = length - 1;
        while(first<=last){
            middle = (first+last)/2;
            middleElement = base + (middle*size);
            found = compare(key,middleElement);
            if(0 == found) return middleElement;
            if(found < 0) last = middle-1;
            if(found > 0) first = middle+1;
        }
        return NULL;
};