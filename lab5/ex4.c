#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();
	unsigned char mask,Shift,data=0x0;
	
	while(1){
		printf("Mask(hex):\n");
		scanf("%x",mask);
		printf("Shift(hex):\n");
		scanf("%x",&Shift);
		printf("%x",mask);
		DIO_fpt(200,0xff,0x0,0xff);
		DIO_fgt(100,mask,Shift,&data);
		
		DIO_fpt(202,0xff,0x0,0x0);
		DIO_fpt(2,0xff,0x0,data);
	}
	return 0;
	
}
