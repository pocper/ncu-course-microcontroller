#include "c4mlib.h"
#include <stdio.h>

int swap(int *x_p,int *y_p);
int main()
{
    C4M_DEVICE_set();
    int a,b;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    swap(&a,&b);
    printf("a=%d\nb=%d",a,b);
}

int swap(int *x_p,int *y_p){
    int tmp;
    tmp=*x_p;
    *x_p=*y_p;
    *y_p=tmp;
}
