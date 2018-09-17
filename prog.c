

#include <stdio.h>

int main(){
	
    int res = 4;

	int * const ip = &res;

	printf("%d\n", res);
	printf("adress %d\n", *ip);
	(*ip)++;

	printf("%d\n", res);
	printf("adress %d\n", *ip++);


}
