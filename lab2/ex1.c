#include "c4mlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    C4M_DEVICE_set();
	srand(time(0));
	int i,a,b,c,num,right=0;
	printf("please enter your student ID:");
	scanf("%d",&num);
	printf("welecome student %d\nthere are 10 questions you need to anwser\n",num);
	for(i=1;i<11;i++)
	{
	a=(rand()%10)+1;
	b=(rand()%10)+1;
	c=a*b;
	printf("%d)%d*%d=",i,a,b);
	scanf("%d",&num);
		if(num==c)
		{
			printf("correct\n");
			right=right+1;
		}
		else
		{
			printf("wrong\n");
		}
	
		
	}
	printf("Your score:%d\nyou got ",10*right);
	switch(right)
	{
		case 10:
		case 9:
			printf("A");
            break;
		case 8:
			printf("B");
            break;
		case 7:
			printf("C");
            break;
		case 6:
			printf("D");
            break;
		
		default:
			printf("F");
            break;
	}
	return 0;
}
