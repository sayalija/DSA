#include <stdio.h>
#include <string.h>
#include "parentheses.h"
int main()
{
	char *data = "erfgv(])()[gwf(df)s{Dsffwef}]",ch;
	Stack* s = create(10, sizeof(char));
	int length = strlen(data),a,i,j;
	char open[] = {'(','[','{'};
	char close[] = {')',']','}'};
	for (i = 0; i < length; i++)	{
		for (j = 0; j < 3; j++){
			if(data[i] == open[j])
				push(s, &data[i]);
		}
		for (j = 0; j < 3; j++){
			if(data[i] == close[j])
				if(!*(char*)peek(s) == open[j])
					printf("parentheses not matching\n");
					pop(s); 
			}	
		}
	if(!isEmpty(s))
			printf("parentheses missing\n");
	return 0;
}