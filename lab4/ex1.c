#include "c4mlib.h"
#include <stdio.h>

int main(){
    C4M_DEVICE_set();
	int i,j,n;
	int score[10]={0},temp,num;
	printf("the number of student=\n");
	scanf("%d",&n);

	printf("pleas enter scores=\n");
	for(i=0;i<n;i++){
        scanf("%d",&num);
        score[i]=num;
	}
	
	for (i=1;i<=n;i++){
		for (j=0;j<=i-1;j++){
			if (score[j]<score[j+1]){
				temp=score[j+1];
				score[j+1]=score[j];
				score[j]=temp;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%3d",score[i]);
	}
	return 0;
}
