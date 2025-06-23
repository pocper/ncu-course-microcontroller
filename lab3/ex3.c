#include "c4mlib.h"
#include <stdio.h>

int interation (int i,int j,int k,int l,int m);
int main()
{
    C4M_DEVICE_set();
	int a,b,c,d,u,e;
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	printf("d=");
	scanf("%d",&d);
	printf("u=");
	scanf("%d",&u);
	for(e=1;e<=10;e++)
	{
        printf("y=%d\n",interation(a,b,c,d,u));			
	}
} 

int interation (int i,int j,int k,int l,int m)
{
	int y,n;
	static int x=0;

	for(n=1;n<=10;n++)
	{
        x=i*x+j*m;
        y=k*x+l*m;
        return(y);		
	}
}