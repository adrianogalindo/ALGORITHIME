#include <stdio.h>
#include <stdlib.h>

int factorielle(int i)
{
	if (i <= 1)
		return i;
	return i * factorielle(i - 1);
}

int main()
{
	int i = 0;
	i = factorielle(4);
	printf("%d\n", i);
}