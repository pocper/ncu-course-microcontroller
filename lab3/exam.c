#include "c4mlib.h"
#include <stdio.h>

void fibo(int a);
int main()
{
    C4M_DEVICE_set();
	int n;
	printf("which number do you want=");//Fibonacci
	scanf("%d",&n);
	printf("1 ");
    fibo(n-1);
} 

void fibo(int a)
{
    int i,x=0,y=1,z;
    for(i=1;i<=a;i++)
    {
        z=x+y;
        if(i%2==0){
            y=z;
            printf("%3d",y);
        }
        if(i%2==1){
            x=z;
            printf("%3d",x);
        }
    }
}