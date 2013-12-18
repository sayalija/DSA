#include <stdlib.h>
#include "parentheses.h"
#include <string.h>
#include <stdio.h>
#include "../Stack/Stack.h"
int matchParantheses(char* data){
	Stack* s = create(10, sizeof(char));
	int flag =0;
	int length = strlen(data),a,i,j;
	char open[] = {'(','[','{'};
	char close[] = {')',']','}'};
	for (i = 0; i < length; i++)	{
		for (j = 0; j < 3; j++){
			if(data[i] == open[j])
				push(s, &data[i]);
		}
		for (j = 0; j < 3; j++){
			if(data[i] == close[j]){
				if(isEmpty(s) == 1)
					return 0;
				if(!*(char*)peek(s) == open[j])
					return 0;
					pop(s); 
				}
			}	
		}
	if(isEmpty(s) == 0)
			return 0;
	return 1;
}