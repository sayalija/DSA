#include <stdio.h>
#include <string.h>
#include "parentheses.h"
int main()
{
	char *data = "erfgv()()[gwf(df)s{Dsffwef}]",ch;
	int result = matchParantheses(data);
	if(result == 0)
		printf("sorry brackets are not matching\n");
	else
		printf("brackets are matching\n");
	return 0;
}