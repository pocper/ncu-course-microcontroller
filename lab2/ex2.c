#include "c4mlib.h"
#include <stdio.h>

int main()
{
    C4M_DEVICE_set();
	int i,j,k;
	printf("   ");
	
	for(i=1;i<10;i++)
	{
		printf("%2d ",i);	
	}
	
	printf("\n");
	
	for(i=1;i<32;i++)
	{
		printf("-");
	}
	
	for(i=1;i<10;i++)
	{
	printf("\n%d|",i);
		for(j=1;j<10;j++)
		{
			k=i*j;
			printf("%3d",k);
		}
	}
    return 0;
} 
