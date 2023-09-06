#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int **score;
    int m,n; //h班 w人 
    int i,j;  //i for h, j for w 
    double taver;
    int sum;
    int tsum=0;
    double avg;
    sum=0;
    
    
    scanf("%d",&m);
    fflush;
	scanf("%d",&n); //輸入班 ,人 
    score=(int**)malloc(sizeof(int*)*m);  //h動態記憶體配置 
    for(i=0;i<m;i++){   //排h給w配 
        score[i]=(int*)malloc(sizeof(int)*n); //用i排 w 
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        	//printf("input score");
        	scanf("%d",&score[i][j]);
        }   
    }
    for(i=0;i<m;i++){
    	printf("class %d\n",i+1);
        for(j=0;j<n;j++){
       	    printf(" %d:",j+1);
        	printf(" %d\n",score[i][j]);
        	sum+=score[i][j];   //班總分
        	avg=(double)sum/n;  //班平均 
        	
        } 
        printf(" sum: %d\n",sum);      
	    printf(" avg: %.2lf\n",avg);
	    tsum+=sum; //校總分	
	    sum=0; 
	    avg=0;
	     
    }
    taver=(double)tsum/(m*n); //校平均
    printf("total: %d, avg: %.2lf\n",tsum,taver);
    for(i=0;i<m;i++){
        free(score[i]);
    }
    free(score);
    score==NULL;
    return 0;
}
