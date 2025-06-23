#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();	
	struct classmate{
		char subject;
		unsigned int number;
	}cl={0,0};
	struct student{
		char name[5];
		unsigned long int id[5];
		unsigned int score[5];
	}stu={0,0,0};
		
	int i,j;
	unsigned int temp[3]={0};
	HMI_snput_struct("ui8_1,ui16_1",sizeof(cl),&cl);//subject number
	HMI_snget_struct("ui8_1,ui16_1",sizeof(cl),&cl);//subject number
	HMI_snput_struct("ui8_5,ui32_5,ui16_5",sizeof(stu),&stu);//name ID score	
	HMI_snget_struct("ui8_5,ui32_5,ui16_5",sizeof(stu),&stu);//name ID score		
	for (i=5;i>=1;i--){
		for (j=0;j<=i-2;j++){
			if (stu.score[j]<stu.score[j+1]){
					temp[0]=stu.name[j];
					temp[1]=stu.id[j];
					temp[2]=stu.score[j];
					stu.name[j]=stu.name[j+1];
					stu.id[j]=stu.id[j+1];
					stu.score[j]=stu.score[j+1];
					stu.name[j+1]=temp[0];
					stu.id[j+1]=temp[1];
					stu.score[j+1]=temp[2];
			}
        }
    }
	HMI_snput_struct("ui8_1,ui16_1",sizeof(cl),&cl);//subject number
	HMI_snput_struct("ui8_5,ui32_5,ui16_5",sizeof(stu),&stu);//name ID score
	return 0;
}