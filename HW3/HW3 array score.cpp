#include<stdio.h>
#define H 5
#define W 3
int main()
{
	int i,j;
	double avg[W]={};
	int sum=0;
	int totalsum;
	int totalavg;
	int highestavg;
	int highposition;
	int score[H][W]={};
	scanf("%d",&score[i][j]);
	for(i=0;i<H;i++){
		printf("student %d:\n",i+1);
		for(j=0;j<W;j++){
			sum+=score[i][j];
			printf("%d:%d\n",j+1,score[i][j]);
			
			
		}
		avg[i]=sum/W;
		printf("sum :%d\n",(double)sum);
		printf("avg: %lf\n",avg);
		sum=0;  
    }
    totalavg+=avg[W]/H; //總平均 
	totalsum+=score[i][j]; //班總分 
	printf("total: %d, avg: %d",totalsum,totalavg);
	
	for(i=0,i<H,i++){
		if(avg[i]>avg[i+1]);
		   i=highposition;
		   avg[i]=highestavg;
	       printf("highest avg: student %d: %.2f",i+1,highestavg);	   
    }
	return 0;				
}
