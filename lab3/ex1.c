#include "c4mlib.h"
#include <stdio.h>
long int power(int x,int n);
int ans=1;

int main()
{
    C4M_DEVICE_set();
	int x,n;
	printf("x=");
	scanf("%d",&x);
	printf("n=");
	scanf("%d",&n);
	printf("%ld",power(x,n));
} 

long int power(int x,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		ans*=x;
	}
	return(ans);
}