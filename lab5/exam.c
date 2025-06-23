#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();
	unsigned int origin_1=0,origin_2=0,data_3=0,data_4=0;
	int cout=0;
	unsigned int cout_1=0;
	
	while(1){
		_delay_ms(2000);
		DIO_fpt(200,0xff,0X0,0x0);
		DIO_fgt(100,0x01,0x0,&data_3);
		if (origin_1!=data_3)
		{
			if(data_3==1){
				cout--;
				printf("%d\n",cout);
			}
			
			origin_1=data_3;
		}
		
		DIO_fpt(200,0xff,0X0,0x0);
		DIO_fgt(100,0x02,0x1,&data_4);
		if (origin_2!=data_4)
		{
			if(data_4==1){
				cout++;
				printf("%d\n",cout);
			}
			
			origin_2=data_4;
		}
		
		printf("%d\n",cout);
		if (cout==0)
		{
			cout_1=0x0;
		}
		if (cout==-1)
		{
			cout_1=0x01;
		}
		if (cout==-2)
		{
			cout_1=0x03;
		}
		if (cout==-3){
			cout_1=0x07;
		}
		if (cout==-4)
		{
			cout_1=0x0f;
		}
		if (cout==-5)
		{
			cout_1=0x1f;
		}
		if (cout==-6)
		{
			cout_1=0x3f;
		}
		if (cout==-7)
		{
			cout_1=0x7f;
		}
		
		if (cout==2)
		{
			cout_1=0x03;
		}
		if (cout==3){
			cout_1=0x07;
		}
		if (cout==4)
		{
			cout_1=0x0f;
		}
		if (cout==5)
		{
			cout_1=0x1f;
		}
		if (cout==6)
		{
			cout_1=0x3f;
		}
		if (cout==7)
		{
			cout_1=0x7f;
		}
		
		if (cout>0)
		{
			for (int i=0;i<=7;i++){
				DIO_fpt(202,0xFF,0X0,0xff);
				DIO_fpt(2,0xff,i,cout_1);
				
				_delay_ms(1000);
			}
			_delay_ms(5000);
			
		}
		if (cout<0)
		{
			for(int i=7;i>=0;i--){
				DIO_fpt(202,0xFF,0X0,0Xff);
				DIO_fpt(2,0xff,i,cout_1);
				_delay_ms(1000);
				
			}
			_delay_ms(5000);
			
			
		}
	}
	return 0;
}
