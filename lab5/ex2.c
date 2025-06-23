#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();
	unsigned char DIOdata=0X0;
	DIO_fpt(200,0xFF,0x00,0xFF);
	DIO_fpt(202,0xFF,0x00,0x00);
	while(1){
		DIO_get(100,1,&DIOdata);
		DIO_put(2,1,&DIOdata);
		_delay_ms(500);
	}
	return 0;
}
