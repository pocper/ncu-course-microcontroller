#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();
	unsigned char o_mask,o_shift,o_flag,i_mask,i_shift,i_flag,v_mask,v_shift;
	int i=1;//用port a輸入即可 c輸出
	
	while(1){	
		printf("enter output mask(hex):\n");//設定輸出mask,shift,flag
		scanf("%X",&o_mask);
		printf("enter output shift(hex):\n");
		scanf("%X",&o_shift);
		printf("enter output flag(hex):\n");
		scanf("%X",&o_flag);
		DIO_fpt(202,o_mask,o_shift,o_flag);//C port輸出
		
		printf("enter input mask(hex):\n");//設定輸入mask,shift,flag
		scanf("%X",&i_mask);
		printf("enter input shift(hex):\n");
		scanf("%X",&i_shift);
		printf("enter input flag(hex):\n");
		scanf("%X",&i_flag);
		DIO_fpt(200,i_mask,i_shift,i_flag);//A port輸入
		
		while(i<=10){
			printf("enter variable mask(hex):\n");//測試dio_fgt()並設定mask,shift
			scanf("%X",&v_mask);
			printf("enter variable shift(hex):\n");
			scanf("%X",&v_shift);
			DIO_fgt(202,v_mask,v_shift,o_flag);
			printf("get value: %X\n",DIO_fgt(202,v_mask,v_shift,o_flag));
			
			printf("enter output mask(hex):\n");//測試dio_fpt()並設定mask,shift,flag
			scanf("%X",&o_mask);
			printf("enter output shift(hex):\n");
			scanf("%X",&o_shift);
			printf("enter output flag(hex):\n");
			scanf("%X",&o_flag);
			DIO_fpt(200,o_mask,o_shift,o_flag);
			i++;
		}
	}
	return 0;
}
