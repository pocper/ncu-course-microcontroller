#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();
	unsigned char hilo=0,new=0;
	DIO_fpt(200,0xff,0x0,0xff);	
	while(1){
		DIO_fgt(100,0x80,0x0,&new);
		
		if(new!=hilo){
			if(new==1){
				printf("UP_EVENT\n");
			}
			else{
				printf("DOWN_EVENT\n");
			}
			hilo=new;
		}
		_delay_ms(1000);
	}
	return 0;
}
