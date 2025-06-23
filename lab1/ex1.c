#include "c4mlib.h"
int main()
{
	C4M_DEVICE_set();
	int a,b,c,input,num;
	printf("Hello! I can write program now.\n");//第零問題
	printf("Character %c's ASCII code is %d\nThe ASCII code %d represents the Character %c \n",'A',(short int)'A',(short int)66, 66);//第一問題
	printf("Decimate number %d in Hexadecimal is %x\nThe scientific form of %f is %E\n",(short int)15,(short int)15,0.001234,0.001234);
	printf("Pleas keyin a number:\n");//第二問題
	scanf("%d", &input);
	printf("The number you keyined is: %d\n", input);
	printf("Please enter a number to transfer in ASCII character:\n");//第三問題
	scanf("%d",&num);
	printf("The ASCII code %d represents the Character %c \n",num,(char)num);
	a=85,b=0x55,c=0b01010101;//第四問題
	printf("A=%d,B=%d,C=%d\n",a,b,c);
	printf("Please enter a number to calculate the size=\n");
	scanf("%d",&num);
	printf("sizeof(%d):\t %d bytes\n",num,(int)sizeof(num));//第五問題
	return 0;
}