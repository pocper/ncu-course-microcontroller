#include "c4mlib.h"
#include <stdio.h>

int main(){
	C4M_DEVICE_set();
	int i,j,k,n;
	printf("enter the number of student:\n");
	scanf("%d",&n);
	uint8_t score[5][2]={0},temp[1][2]={0};
	printf("first line are ID and second are score\n");
	HMI_snget_matrix(HMI_TYPE_I8,n,2,score);
	
	for (i=n;i>=1;i--){
		for (j=0;j<=i-2;j++){
			if (score[j][1]<score[j+1][1]){
				for(k=0;k<=1;k++){
					temp[0][k]=score[j+1][k];
					score[j+1][k]=score[j][k];
					score[j][k]=temp[0][k];
				}
			}
		}
	}
	
	printf("The student's scores from the highest to lowest\n");
	
	for(i=0;i<n;i++){
		printf("ID:%3d   Score:%3d\n",score[i][0],score[i][1]);
	}
	return 0;
}
