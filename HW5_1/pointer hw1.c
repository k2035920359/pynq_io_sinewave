#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N; //人數 
	int *score;
	int i;
    int sum=0; 
    int avg=0;
    int highest=0;
    int highestpos=0;
    
	//printf("輸入人數:\n");
	scanf("%d\n",&N);	//輸入人數

	score=(int*)malloc(sizeof(int)*N); //動態記憶體配置 
	//printf("輸入成績:\n");
	for(i=0;i<N;i++){  //印出三個成績  
		scanf("%d %d %d\n",&score[i],&score[i+1],&score[i+2]); //輸入三個成績
		sum+=score[i]; //成績加總 
    }
	avg=sum/N;   //平均成績 
    printf("avg = %d.2f",(double)avg); //印出平均成績 
	
	if(score[i]<60){	//找出不及格的編號跟成績 
		printf("fail:\n%d: %d\n",i,score[i]);
	} 
	if(score[i+1]>score[i]){  //找出最高的編號跟成績 
		highest=score[i+1];
		highestpos=i+1;
		printf("highest:\n%d: %d\n",highestpos+1,highest); //印出最高的 
	}
	free(score); //釋放記憶體 
	score=NULL;
	return 0;
 } 
