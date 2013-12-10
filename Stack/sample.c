#include <stdio.h>
int sum(a,b){
	return (a+b);
}
int main(){
	int a = 4, b = 8;
	int c = sum(a,b);
	printf("sum = %d", c);
	return 0;
}