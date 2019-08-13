

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int r = 0;
	int x, y;

	do {
		if (x % 2 != 0)
		{
			r += y;
			x -= 1;
		}
		x /= 2;
		y *= 2;
	} while (x != 0)

	return r;
}