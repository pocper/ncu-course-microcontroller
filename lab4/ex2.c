#include "c4mlib.h"
#include <stdio.h>

int main(){
    C4M_DEVICE_set();
	int i,j,k,n,id,num;
	int score[10][2]={0},temp[1][2]={0};
	printf("the number of student:\n");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("enter student ID:\n");
		scanf("%d",&id);
		score[i][0]=id;
		printf("enter score:\n");
		scanf("%d",&num);
		score[i][1]=num;
	}
	
	for (i=1;i<=n;i++){
		for (j=0;j<=i-1;j++){
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