

#include <stdio.h>
#include <stdlib.h>


int main()
{

	char romain[10];
	fgets(romain, 10, stdin);
	

	int nomReel = 0;
	
	for (int i = 0; i < 10; i++)
	{	
		if (romain[i] == 'I')
		{	
			if (romain[i + 1] == 'V')
			{	
				nomReel += 4;
				i++;
			}	
			if (romain[i + 1] == 'X')
			{	
				nomReel += 9;	
				i++;	
			}
		}	
		else if (romain[i] == 'V')
		{
			nomReel += 5;
		}	
		else if (romain[i] == 'X')
		{	
			if (romain[i + 1] == 'L')
			{	
				nomReel += 40;
				i++;
			}
			else
				nomReel += 10;
		}
		else if (romain[i] == 'L')
			nomReel += 50;	
		if (romain[i] == 'I')
		{	
			nomReel += 1;
		}	
	}

	printf("%d\n", nomReel);
}


