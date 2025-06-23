#include "c4mlib.h"
#include <stdio.h>

int main ()
{
    C4M_DEVICE_set();
	int i=1,j=1,k;
	printf("   ");
	
	while(i<10)
	{
		printf("%2d ",i);
		i++;
	}
	
	printf("\n");
	i=1;
	while(i<32)
	{
		printf("-");
		i++;
	}
	i=1;
	while(i<10)
	{
	printf("\n%d|",i);
	j=1;
		while(j<10)
		{
			k=i*j;
			printf("%3d",k);
			j++;
		}
	i++;
	}
    return 0;
} 
