#include "bSort.h"
#include <stdlib.h>
#include <memory.h>
void bSort(void* elements, int length, int typeSize, compare cmp){
	int i,j;
	void* temp = calloc(1, typeSize); 
	void *first, *second;

	for(i = 1; i< length; i++){
		for(j = 0; j< length - i; j++){
			first = elements + j * typeSize;
			second = elements + (j+1)* typeSize;
			if(0 < cmp(first,second)){
				memcpy(temp, first, typeSize);
				memcpy(first, second, typeSize);
				memcpy(second, temp, typeSize);
			}
		}
	}
	free(temp);
}