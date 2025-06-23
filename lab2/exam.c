#include "c4mlib.h"
#include <stdio.h>

int main()
{
    C4M_DEVICE_set();
	int layer,i,j;
	printf("which layer do u want=");
	scanf("%d",&layer);
	
	for(i=1;i<=layer;i++)
	{
		for(j=1;j<=layer-i;j++)
		{
			printf("_");
		}
		for(j=1;j<=(2*i-1);j++)
		{
			printf("*");
		}
		for(j=1;j<=layer-i;j++)
		{
			printf("_");
		}
		printf("\n");
	}
	
	for(i=1;i<=layer;i++)
	{
		for(j=1;j<=layer-i;j++)
		{
			printf("_");
		}
		for(j=1;j<=(2*i-1);j++)
		{
			printf("*");
		}
		for(j=1;j<=layer-i;j++)
		{
			printf("_");
		}
		printf("\n");
	}
	return 0;
} 
