#include<stdio.h>
#define H 5
#define W 3
int main()
{
	int score[H][W]={};
	int i,j;
	int highposition;
	int sum=0;
	int totalsum=0;
	double totalavg=0;
	double avg[]={};
	double highestavg;
	double H2=H;
	double W2=W;

// scan input
	for(i=0;i<H;i++) {
		scanf("%d %d %d\n",&score[i][0],&score[i][1],&score[i][2]);
		}
	
// print and verify actual input	
//	for(i=0;i<H;i++) {
//		printf("%d %d %d\n",score[i][0],score[i][1],score[i][2]);
//		}
//now caulate it	
	for(i=0;i<H;i++){
		printf("student %d:\n",i+1);
		for(j=0;j<W;j++){
			sum+=score[i][j];
			printf("%d:%d\n",j+1,score[i][j]);
			totalsum+=score[i][j]; //班總分 
 		}
		avg[i]=sum/W2;
		printf("sum :%d\n",sum);
		printf("avg: %.2f\n",avg[i]);
		sum=0;  
    }
    totalavg=totalsum/(H2*W2); //總平均   
	printf("\ntotal: %d, avg: %.2f\n",totalsum,totalavg);
 
//find the highest
 //initail the highposition and avg
  highposition=0;highestavg=avg[0];
  for(i=0;i<H-1;i++){
    if(highestavg<avg[i+1]){
    	highposition=i+1;highestavg=avg[i+1];}
    	}
    	
//print the highest
 printf("Highest avg: student %d: %.2f\n",highposition+1,highestavg);
 
// bye
	return 0;				
}