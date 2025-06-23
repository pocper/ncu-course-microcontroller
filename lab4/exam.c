#include "c4mlib.h"
#include <stdio.h>

struct name{
	unsigned int num[5];
	unsigned int ms[5];
	unsigned int es[5];
};
	
struct clas{
	unsigned int ms[4];//math
	unsigned int es[3];//eng
	struct name name1;
}cla={0};


int main(){
	C4M_DEVICE_set();
	int i,j;
	HMI_snput_struct("ui16_4,ui16_3,ui16_5,ui16_5,ui16_5",sizeof (cla),&cla);
	HMI_snget_struct("ui16_4,ui16_3,ui16_5,ui16_5,ui16_5",sizeof (cla),&cla);
	
	double avg[5],temp[4];
	
	for(i=0;i<=4;i++){
		avg[i]=(cla.name1.ms[i]+cla.name1.es[i])/2;
	}
	
	for (i=5;i>=1;i--){
		for (j=0;j<=i-2;j++){
			if (avg[j]>avg[j+1]){
				temp[0]=cla.name1.num[j];
				temp[1]=cla.name1.ms[j];
				temp[2]=cla.name1.es[j];
				temp[3]=avg[j];
				
				cla.name1.num[j]=cla.name1.num[j+1];
				cla.name1.ms[j]=cla.name1.ms[j+1];
				cla.name1.es[j]=cla.name1.es[j+1];
				avg[j]=avg[j+1];
				
				cla.name1.num[j+1]=temp[0];
				cla.name1.ms[j+1]=temp[1];
				cla.name1.es[j+1]=temp[2];
				avg[j+1]=temp[3];
			}
		}
	}
	HMI_snput_struct("ui16_4,ui16_3,ui16_5,ui16_5,ui16_5",sizeof (cla),&cla);
	return 0;
}
