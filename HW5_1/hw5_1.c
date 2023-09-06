#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int N; //人數 
	int *score;
	int i;
    int sum=0; 
    double avg=0;
    int highest=0;
    int highestpos=0;
    
	
	//printf("輸入人數:\n");
	scanf("%d",&N);	//輸入人數
	score=(int *)malloc(sizeof(int)*N); //動態記憶體配置 
	//printf("輸入成績:\n");
	for(i=0;i<N;i++){  //印出三個成績  
		scanf("%d",&score[i]); //輸入三個成績
	
    }
    for(i=0;i<N;i++){
    	//sum+=score[i]; //成績加總 
	    avg+=(double)score[i]/N;   //平均成績 
    }
    printf("avg = %.2f\n",avg); //印出平均成績 
	
	printf("fail:\n");
	for(i=0;i<N;i++){
	    if(score[i]<60){	//找出不及格的編號跟成績 
		    printf("%d: %d\n",i+1,score[i]);
        }
	}
	printf("highest:\n");
	for(i=0;i<N;i++){
	    if(score[i]>highest){  //找出最高的編號跟成績 
		   highest=score[i];
		   highestpos=i;	
        }
	}	
	printf("%d: %d\n",highestpos+1,highest); //印出最高的 
	free(score); //釋放記憶體 
	score=NULL;
	return 0;
 } 
