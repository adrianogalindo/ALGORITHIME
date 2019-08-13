#include <stdio.h>
#include <stdlib.h>


void syracuse(int n)
{
	printf("%d", n);
	if (n == 1)
	{	
		printf(".");		
		return;
	}	
	printf(", ");
	if (n % 2 == 0)
		syracuse(n/2);
	else 
		syracuse((n * 3) + 1);
}

int main()
{
	syracuse(54);
	printf("\n");
}